/**
 * @file DHT22.h
 * @author Eisenberger, Edward (Edward.Eisenberger@live.com)
 * @brief 
 * @version 0.1
 * @date 2022-06-29
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#ifndef BDF_Sensor_DHT22_h
#define BDF_Sensor_DHT22_h

// BDF Includes
#include <BDF/Environment.h>

/// @brief Bergermeister Development Framework (BDF)
namespace BDF
{
   /// @brief Collection of Objects comprising a Home Automation Sensor
   namespace Sensor
   {
      /**
       * @brief DHT22 Sensor
       * 
       */
      class DHT22
      {
         public:     // Public Attributes
            static const char* const Consumer;

            enum class Status : uint32_t
            {
               Success = 0,
               InvalidChip,
               InvalidLine,
               RequestOutputFailed,
               RequestInputFailed,
               InitialPulseTimeout,
               RisingEdgeTimeout,
               FallingEdgeTimeout,               
               ChecksumMismatch
            };

         private:    // Private Attributes
            static constexpr uint32_t dataByteCount = 5;

            uint32_t chipNumber;
            uint32_t lineNumber;
            uint8_t data[ dataByteCount ];

         public:     // Public Methods
            DHT22( void );
            ~DHT22( void ) = default;

            Status Open( const uint32_t ChipNumber, const uint32_t LineNumber );
            Status Sample( void );

            inline bool IsValid( void ) const
            {
               uint32_t checksum = this->data[ 3 ] + this->data[ 2 ] + this->data[ 1 ] + this->data[ 0 ];

               return ( static_cast< uint8_t >( checksum & 0x000000FF ) == this->data[ 4 ] );
            }

            inline double Humidity( void ) const
            {
               return( 
                  static_cast< double >( 
                     ( static_cast< uint32_t >( this->data[ 0 ] ) * 256 ) + 
                     ( static_cast< uint32_t >( this->data[ 1 ] )       ) )
                  / 10.0 );
            }

            inline double Temperature( void ) const
            {
               return( 
                  static_cast< double >(
                     ( static_cast< uint32_t >( this->data[ 2 ] & 0x7F ) * 256 ) +
                     ( static_cast< uint32_t >( this->data[ 3 ]                ) )
                  / 10.0 ) );
            }

         private:    // Private Methods
            Status readData( struct gpiod_line* line );
      };
   }
}

#endif
