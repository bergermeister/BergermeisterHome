// Google Test Includes
#include <gtest/gtest.h>

// BDF Includes
#include <BDF/Sensor/DHT22.h>

TEST( Sensor, Temperature )
{
   static constexpr uint32_t chipNumber = 0;
   static constexpr uint32_t lineNumber = 23;
   static constexpr uint32_t attemptCount = 5;
   BDF::Sensor::DHT22 sensor;

   ASSERT_EQ( sensor.Open( chipNumber, lineNumber ), BDF::Sensor::DHT22::Status::Success );
   for( uint32_t attempt = 0; attemptCount < 5; attempt++ )
   {
      if( sensor.Sample( ) == BDF::Sensor::DHT22::Status::Success )
      {
         ASSERT_TRUE( sensor.IsValid( ) );
         std::cout << "Temperature: " << sensor.Temperature( ) << "\t" <<
                      "Humidity:    " << sensor.Humidity( ) << std::endl;
      }
   } 
}
