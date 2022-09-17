// Google Test Includes
#include <gtest/gtest.h>

// BDF Includes
#include <BDF/Sensor/DHT22.h>

// Linux Includes
#include <gpiod.h>

TEST( Sensor, Temperature )
{
   static constexpr uint32_t chipNumber = 0;
   static constexpr uint32_t lineNumber = 23;
   static constexpr uint32_t attemptCount = 20;
   BDF::Sensor::DHT22 sensor;

   bool sampled = false;
   struct gpiod_chip* chip;

   chip = gpiod_chip_open_by_number( chipNumber );
   ASSERT_TRUE( chip != nullptr );

   ASSERT_EQ( sensor.Open( chip, lineNumber ), BDF::Sensor::DHT22::Status::Success );
   for( uint32_t attempt = 0; attempt < attemptCount; attempt++ )
   {
      if( sensor.Sample( ) == BDF::Sensor::DHT22::Status::Success )
      {
         ASSERT_TRUE( sensor.IsValid( ) );
         sampled = true;
         std::cout << "Attempts:    " << attempt + 1 << std::endl <<
                      "Temperature: " << sensor.Temperature( ) << "\t" <<
                      "Humidity:    " << sensor.Humidity( ) << std::endl;
         break;
      }
   } 
   sensor.Close( );

   ASSERT_TRUE( sampled );

   gpiod_chip_close( chip );
}
