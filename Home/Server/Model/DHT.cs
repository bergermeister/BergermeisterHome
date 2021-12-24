namespace Server.Model
{
   using System;
   using System.Collections;
   using System.Collections.Generic;
   using System.Diagnostics;
   using System.Linq;
   using System.Text;
   using System.Threading.Tasks;
   using Windows.Devices.Gpio;

   class DHT
   {
      public enum Status
      {
         Success = 0,
         InitialPulseFailed,
         RisingEdgeTimeout,
         FallingEdgeTimeout,
         ChecksumMismatch
      }

      private const int   delayHoldLow  = 20;
      private const int   delayHoldHigh = 40;
      private const ulong timeout       = 1000; // 1000 Microseconds
      private const int   byteCount     = 5;

      private GpioPin inputPin;
      private GpioPin outputPin;
      private GpioPinDriveMode inputDriveMode;
      private GpioChangeReader changeReader;
      private long data;

      public DHT( )
      {
         this.inputPin = null;
         this.outputPin = null;
         this.inputDriveMode = GpioPinDriveMode.Input;
         this.data = 0;
      }
      public void Initialize( GpioPin aInputPin, GpioPin aOutputPin )
      {
         /// @par Process Design Language
         /// -# Determine the input drive mode
         ///   - Use InputPullUp if supported, otherwise fall back to Input (floating)
         this.inputDriveMode = aInputPin.IsDriveModeSupported( GpioPinDriveMode.InputPullUp ) ?
                               this.inputDriveMode = GpioPinDriveMode.InputPullUp : 
                               this.inputDriveMode = GpioPinDriveMode.Input;
         
         /// -# Set the Input Pin Drive Mode and obtain Gpio Change Reader
         this.inputPin = aInputPin;
         this.inputPin.SetDriveMode( GpioPinDriveMode.Output );
         this.changeReader = new GpioChangeReader( this.inputPin );

         /// -# Set the Output Pin value to Low and Drive Mode to Output
         this.outputPin.Write( GpioPinValue.Low );
         this.outputPin.SetDriveMode( GpioPinDriveMode.Output );
      }

      public Status Sample( )
      {
         // This is the threshold used to determine whether a bit is a '0' or a '1'.
         // A '0' has a pulse time of 76 microseconds, while a '1' has a
         // pulse time of 120 microseconds. 110 is chosen as a reasonable threshold.
         // We convert the value to QPF units for later use.
         const long oneThresholdTicks = 110 * ( TimeSpan.TicksPerMillisecond / 1000 );
         const long initialRisingEdgeTimeoutMillis = 1;
         const long sampleTimeoutMillis = 10;

         Status       status = Status.Success;
         GpioPinValue previousValue = GpioPinValue.Low;
         GpioPinValue currentValue;
         Stopwatch    timer = new Stopwatch( );
         BitArray     bits = new BitArray( 40 );
         int          index;
         long         previousTicks;
         long         currentTicks;
         long         deltaTicks;
         long[ ]      tempData = new long[ 1 ];

         if( !this.sendInitialPulse( ) )
         {
            status = Status.InitialPulseFailed;
         }
         else
         {
            previousValue = this.inputPin.Read( );

            // catch the first rising edge
            timer.Start( );
            while( status == Status.Success )
            {
               
               if( timer.ElapsedMilliseconds > initialRisingEdgeTimeoutMillis )
               {
                  status = Status.RisingEdgeTimeout;
               }
               else
               {
                  currentValue = this.inputPin.Read( );
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
            for( index = 0; ( index < byteCount ) && ( status == Status.Success ); )
            {
               if( timer.ElapsedMilliseconds > sampleTimeoutMillis )
               {
                  status = Status.FallingEdgeTimeout;
               }
               else
               {
                  currentValue = this.inputPin.Read( );
                  if( ( previousValue == GpioPinValue.High ) && ( currentValue == GpioPinValue.Low ) )
                  {
                     // A falling edge was detected
                     currentTicks = timer.ElapsedTicks;
                     if( index != 0 )
                     {
                        deltaTicks = currentTicks - previousTicks;
                        bits[ byteCount - index ] = ( deltaTicks > oneThresholdTicks );
                     }

                     previousTicks = currentTicks;
                     ++index;
                  }

                  previousValue = currentValue;
               }
            }

            bits.CopyTo( tempData, 0 );
            this.data = tempData[ 0 ];

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
            long checksum = ( ( this.data >> 32 ) & 0xFF ) +
                            ( ( this.data >> 24 ) & 0xFF ) +
                            ( ( this.data >> 16 ) & 0xFF ) +
                            ( ( this.data >>  8 ) & 0xFF );

            return ( ( checksum & 0xFF ) == ( this.data & 0xFF ) );
         }
      }

      public double Humidity
      {
         get
         {
            return( ( ( this.data >> 24 ) & 0xFFFF ) * 0.1 );
         }
      }

      public double Temperature
      {
         get
         {
            double temp = ( ( this.data >> 8 ) & 0x7FFF ) * 0.1;
            if( ( ( this.data >> 8 ) & 0x8000 ) == 0x8000 )
            {
               temp = -temp;
            }
            return( temp );
         }
      }

      private bool sendInitialPulse( )
      {
         bool status = true;
         Stopwatch timer = new Stopwatch( );
         
         /// @par Process Design Language
         /// -# Bring the data line low for 18ms
         this.outputPin.Write( GpioPinValue.Low );
         timer.Start( );
         while( timer.ElapsedMilliseconds < 18 )
         {
            ;
         }
         this.outputPin.Write( GpioPinValue.High );

         /// -# Verify initial pulse is less than 30ms
         if( timer.ElapsedMilliseconds > 30 )
         {
            status = false;
         }

         return( status );
      }
   }
}
