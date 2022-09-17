// Sensor Includes
#include <BDF/Sensor/DHT22.h>
#include <BDF/Time/StopWatch.h>

// StdLib Includes
#include <bitset>
#include <chrono>

namespace BDF
{
   namespace Sensor
   {
      const char* const DHT22::Consumer = "DHT22";

      /**
       * @brief Construct a new DHT22::DHT22 object
       * 
       */
      DHT22::DHT22( void )
      {
         this->line = nullptr;
         std::memset( reinterpret_cast< void* >( this->data ), 0, dataByteCount );
      }

      /**
       * @brief 
       * 
       * @param[in] Chip 
       * @param[in] LineNumber 
       * @return DHT22::Status 
       */
      DHT22::Status DHT22::Open( struct gpiod_chip* Chip, const uint32_t LineNumber )
      {
         this->line = gpiod_chip_get_line( Chip, LineNumber);
         return( ( this->line != nullptr ) ? Status::Success : Status::InvalidLine );
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
       * @param None
       * @return
       * 
       */
      DHT22::Status DHT22::Sample( void )
      {
         static constexpr uint32_t totalPulses = 41;
         static constexpr uint32_t maxCount = 36000;

         uint32_t count = 0;
         uint32_t pulseCounts[ totalPulses * 2 ] = { 0 };
         uint32_t threshold = 0;
         int pulseIndex;
         int dataIndex;
         volatile int delayIndex;

         gpiod_line_release( this->line );
         if( gpiod_line_request_output( this->line, Consumer, 0 ) == -1 )
         {
            return( Status::RequestOutputFailed );
         }

         gpiod_line_set_value( this->line, 1 );
         usleep( 500000 );

         gpiod_line_set_value( this->line, 0 );
         usleep( 20000 );

         gpiod_line_release( this->line );

         if( gpiod_line_request_input( this->line, Consumer ) == -1 )
         {
            return( Status::RequestInputFailed );
         }
      
         // Very short delay before reading
         for( delayIndex = 0; delayIndex < 50; delayIndex++ );

         // Wait for sensor pin to pull low
         while( gpiod_line_get_value( this->line ) == 1 )
         {
            count++;
            if( count >= maxCount )
            {
               return( Status::InitialPulseTimeout );
            }
         }

         for( pulseIndex = 0; pulseIndex < ( totalPulses * 2 ); pulseIndex += 2 )
         {
            while( gpiod_line_get_value( this->line ) == 0 )
            {
               if( ( ++pulseCounts[ pulseIndex ] ) >= maxCount )
               {
                  return( Status::RisingEdgeTimeout );
               }
            }

            while( gpiod_line_get_value( this->line ) == 1 )
            {
               if( ( ++pulseCounts[ pulseIndex + 1 ] ) >= maxCount )
               {
                  return( Status::FallingEdgeTimeout );
               }
            }
         } 

         threshold = 0;
         for( pulseIndex = 0; pulseIndex < ( totalPulses * 2 ); pulseIndex += 2 )
         {
            threshold += pulseCounts[ pulseIndex ];
         }
         threshold /= ( totalPulses - 1 );

         for( pulseIndex = 3; pulseIndex < ( totalPulses * 2 ); pulseIndex += 2 )
         {
            dataIndex = ( pulseIndex - 3 ) / 16;
            this->data[ dataIndex ] <<= 1;
            if( pulseCounts[ pulseIndex ] >= threshold )
            {
               this->data[ dataIndex ] |= 1;
            }
         }

         return( Status::Success );
      }

      void DHT22::Close( void )
      {
         gpiod_line_release( this->line );
      }
   }
}
