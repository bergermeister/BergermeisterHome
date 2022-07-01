/**
 * @file DHT22.cpp
 * @author Eisenberger, Edward (Edward.Eisenberger@live.com)
 * @brief 
 * @version 0.1
 * @date 2022-06-29
 * 
 * @copyright Copyright (c) 2022
 * 
 */
// Sensor Includes
#include <Sensor/DHT22.h>

// StdLib Includes
#include <iostream>
#include <cstring>
#include <chrono>

namespace Sensor
{
   using namespace std::chrono;

   const char* const DHT22::gpioChipName = "gpiochip0";

   /**
    * @brief Construct a new DHT22::DHT22 object
    * 
    */
   DHT22::DHT22( const uint32_t LineOffset )
   {
      struct gpiod_line_request_config lineConfig =
      {
         /* Name of Consumer */ "DHT22 Sensor", 
         /* Request type     */ GPIOD_LINE_REQUEST_DIRECTION_OUTPUT, 
         /* Flags            */ 0 // GPIOD_LINE_REQUEST_FLAG_BIAS_PULL_UP
      };
      struct gpiod_chip* chip = gpiod_chip_open_by_name( gpioChipName );
      this->line = gpiod_chip_get_line( chip, LineOffset );
      std::memset( reinterpret_cast< void* >( this->data ), 0, dataByteCount );
   }

   DHT22::~DHT22( void )
   {
      struct gpiod_chip* chip = gpiod_line_get_chip( this->line );
      gpiod_chip_close( chip );
   }

   /**
    * @brief
    * 
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
   DHT22::Status DHT22::Sample( void )
   {
      Status status = Status::Success;
      /*
      // This is the threshold used to determine whether a bit is a '0' or a '1'.
      long oneThresholdTicks             = 110 * ( Stopwatch.Frequency / ( 1000 * 1000 ) );  // 110us
      long initialRisingEdgeTimeoutTicks =   1 * ( Stopwatch.Frequency / ( 1000 ) );         //   1ms
      long sampleTimeoutTicks            =  10 * ( Stopwatch.Frequency / ( 1000 ) );         //  10ms
      int  bitCount                      = 40;

      
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
      */
      return( status );
   }

   bool DHT22::sendInitialPulse( void )
   {
      static constexpr float lowDurationMilliseconds = 18.0f;
      bool status = true;
      
      time_point< system_clock > start;
      time_point< system_clock > end;
      float elapsedMilliseconds;

      start = system_clock::now( );
      do
      {
         end = system_clock::now( );
         elapsedMilliseconds = duration_cast< duration< float, std::milli > >( end - start ).count( );
      } while( elapsedMilliseconds < lowDurationMilliseconds );
      /*
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
      */
      return( status );
   }
}

