/**
 * @file
 * @brief
 * 
 * 
 * @details
 * 
 */
namespace Server.Model
{
   using System;
   using System.Collections;
   using System.Diagnostics;
   using Windows.Devices.Gpio;

   /**
    * @brief
    * DHT11 Driver
    * 
    * @details
    * 
    */
   class DHT11
   {
      /**
       * @brief
       * Enumeration of Sampling Status
       */
      public enum Status
      {
         Success = 0,
         InitialPulseFailed,
         RisingEdgeTimeout,
         FallingEdgeTimeout,
         ChecksumMismatch
      }

      private const int        byteCount = 5;   ///< Number of Data Bytes
      private GpioPin          pin;             ///< GPIO Pin connected to Single-bus Data Pin
      private GpioPinDriveMode inputDriveMode;  ///< Input Drive Mode
      private byte[ ]          data;            ///< Humidity, Temperature, and Checksum data

      /**
       * @brief
       * Default Constructor
       * 
       * @details
       * @par
       * 
       */
      public DHT11( )
      {
         this.pin = null;
         this.inputDriveMode = GpioPinDriveMode.Input;
         this.data = new byte[ byteCount ];
      }

      /**
       * @brief
       * 
       * @details
       * 
       * 
       * @param in aPin    GPIO Pin assigned to Single-bus Data Pin
       */
      public void Initialize( GpioPin aPin )
      {
         /// @par Process Design Language
         /// -# Determine the input drive mode
         ///   - Use InputPullUp if supported, otherwise fall back to Input (floating)
         this.inputDriveMode = aPin.IsDriveModeSupported( GpioPinDriveMode.InputPullUp ) ?
                               this.inputDriveMode = GpioPinDriveMode.InputPullUp : 
                               this.inputDriveMode = GpioPinDriveMode.Input;
         
         /// -# Store the Input Pin and set the Input Pin Drive Mode
         this.pin = aPin;
         this.pin.SetDriveMode( GpioPinDriveMode.Output );
      }

      /**
       * @brief
       * 
       * 
       * @details
       * This method
       * 
       * @note
       * Reference DHT11-Technical-Data-Sheet-Translated-Version-1143054.pdf from Mouser Electronics
       * 
       * @note
       * Once the DHT detects the start signal, it will send out a low-voltage-level response signal, which lasts 80us.
       * Then the DHT sets Data Single-bus voltage level from low to high and keeps it for 80us for DHT's preparation
       * for sending data.
       * 
       * @note
       * When DHT is sending data, every bit of data begins with 50us of low-voltage-level and the length of the 
       * following high-voltage-level signal determines whether data bit is "0" or "1".
       * - A 0 data bit is  ~78us (50us start transmit + 28us of high-voltage-level)
       * - A 1 data bit is ~120us (50us start transmit + 70us of high-voltage-level)
       * 
       * @return
       * 
       */
      public Status Sample( )
      {
         // This is the threshold used to determine whether a bit is a '0' or a '1'.
         long oneThresholdTicks             = 110 * ( Stopwatch.Frequency / ( 1000 * 1000 ) );  // 110us
         long initialRisingEdgeTimeoutTicks =   1 * ( Stopwatch.Frequency / ( 1000 ) );         //   1ms
         long sampleTimeoutTicks            =  10 * ( Stopwatch.Frequency / ( 1000 ) );         //  10ms
         int  bitCount                      = 40;

         Status       status = Status.Success;
         GpioPinValue previousValue = GpioPinValue.Low;
         GpioPinValue currentValue;
         Stopwatch    timer = new Stopwatch( );
         BitArray     bits = new BitArray( bitCount );
         int          index;
         long         previousTicks;
         long         currentTicks;
         long         deltaTicks;
         long[ ]      deltas = new long[ bitCount ];

         if( !this.sendInitialPulse( ) )
         {
            status = Status.InitialPulseFailed;
         }
         else
         {
            previousValue = this.pin.Read( );

            // catch the first rising edge
            timer.Start( );
            while( status == Status.Success )
            {
               
               if( timer.ElapsedTicks > initialRisingEdgeTimeoutTicks )
               {
                  status = Status.RisingEdgeTimeout;
               }
               else
               {
                  currentValue = this.pin.Read( );
                  if( currentValue != previousValue )
                  {
                     // rising edge?
                     if( currentValue == GpioPinValue.High )
                     {
                        break;
                     }
                     previousValue = currentValue;
                  }
               }
            }
            timer.Stop( );
         }

         if( status == Status.Success )
         {
            // capture every falling edge until all bits are received or timeout occurs
            previousTicks = 0;
            timer.Start( );
            for( index = 0; ( index < bitCount + 1 ) && ( status == Status.Success ); )
            {
               if( timer.ElapsedTicks > sampleTimeoutTicks )
               {
                  status = Status.FallingEdgeTimeout;
               }
               else
               {
                  currentValue = this.pin.Read( );
                  if( ( previousValue == GpioPinValue.High ) && ( currentValue == GpioPinValue.Low ) )
                  {
                     // A falling edge was detected
                     currentTicks = timer.ElapsedTicks;
                     if( index != 0 )
                     {
                        deltaTicks = currentTicks - previousTicks;
                        bits[ bitCount - index ] = ( deltaTicks > oneThresholdTicks );
                        deltas[ bitCount - index ] = deltaTicks;
                     }

                     previousTicks = currentTicks;
                     ++index;
                  }

                  previousValue = currentValue;
               }
            }
         }

         if( status == Status.Success )
         {
            bits.CopyTo( this.data, 0 );

            if( !this.IsValid )
            {
               // checksum mismatch
               status = Status.ChecksumMismatch;
            }
         }

         return( status );
      }

      public bool IsValid
      {
         get
         {
            long checksum = ( ( this.data[ 4 ] ) & 0xFF ) +
                            ( ( this.data[ 3 ] ) & 0xFF ) +
                            ( ( this.data[ 2 ] ) & 0xFF ) +
                            ( ( this.data[ 1 ] ) & 0xFF );

            return ( ( checksum & 0xFF ) == ( this.data[ 0 ] & 0xFF ) );
         }
      }

      public double Humidity
      {
         get
         {
            return( ( double )this.data[ 4 ] + ( ( double )this.data[ 3 ] ) * 0.1 );
         }
      }

      public double Temperature
      {
         get
         {
            return( ( double )this.data[ 2 ] + ( ( double )this.data[ 1 ] * 0.1 ) );
         }
      }

      private bool sendInitialPulse( )
      {
         bool status = true;
         Stopwatch timer = new Stopwatch( );

         /// @par Process Design Language
         /// -# Bring the data line low for 18ms
         this.pin.SetDriveMode( GpioPinDriveMode.Output );
         this.pin.Write( GpioPinValue.Low );
         timer.Start( );
         while( timer.ElapsedMilliseconds < 18 )
         {
            ;
         }
         this.pin.Write( GpioPinValue.High );
         this.pin.SetDriveMode( this.inputDriveMode );

         /// -# Verify initial pulse is less than 30ms
         if( timer.ElapsedMilliseconds > 30 )
         {
            status = false;
         }

         return( status );
      }
   }
}
