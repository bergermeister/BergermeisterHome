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
#ifndef Sensor_DHT22_h
#define Sensor_DHT22_h

// libgpiod includes
#include <gpiod.h>

// StdLib Includes
#include <cstdint>

/**
 * @brief Collection of Objects comprising a Home Automation Sensor
 */
namespace Sensor
{
   /**
    * @brief DHT22 Sensor
    * 
    */
   class DHT22
   {
   public:     // Public Attributes
      enum class Status : uint32_t
      {
         Success = 0,
         InitialPulseFailed,
         RisingEdgeTimeout,
         FallingEdgeTimeout,
         ChecksumMismatch
      };

   private:    // Private Attributes
      static constexpr uint32_t dataByteCount = 5;
      static const char* const gpioChipName;

      struct gpiod_line* line;
      uint8_t data[ dataByteCount ];

   public:     // Public Methods
      DHT22( const uint32_t LineOffset );
      ~DHT22( void );

      Status Sample( void );

      inline bool IsOpen( void ) const
      {
         return( this->line != nullptr );
      }

      inline bool IsValid( void ) const
      {
         long checksum = ( ( this->data[ 4 ] ) & 0xFF ) +
                         ( ( this->data[ 3 ] ) & 0xFF ) +
                         ( ( this->data[ 2 ] ) & 0xFF ) +
                         ( ( this->data[ 1 ] ) & 0xFF );

         return ( ( checksum & 0xFF ) == ( this->data[ 0 ] & 0xFF ) );
      }

      inline double Humidity( void ) const
      {
         return( ( double )this->data[ 4 ] + ( ( double )this->data[ 3 ] ) * 0.1 );
      }

      inline double Temperature( void ) const
      {
         return( ( double )this->data[ 2 ] + ( ( double )this->data[ 1 ] * 0.1 ) );
      }

   private:    // Private Methods
      bool sendInitialPulse( void );
   };
}

#endif
