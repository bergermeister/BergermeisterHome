/**
 * @file main.cpp
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
#include <Sensor/UDPClient.h>

// StdLib Includes
#include <cstdint>
#include <iostream>
#include <unistd.h>

/**
 * @brief 
 * 
 * @param[in] argc   Number of provided arguments in argv
 * @param[in] argv   Array of command line string arguments
 * 
 * @return int 
 */
int main( int argc, char** argv )
{
   int status = 0;
   std::string remoteHostname = "DESKTOP-PM4TGPJ.local";
   int port = 59200;
   Sensor::DHT22 sensor( 4 );
   Sensor::UDPClient udpClient( remoteHostname, port );
   uint8_t buffer[] = "Hello Host!";

   std::cout << "GPIO Test..." << std::endl;   

   if( sensor.IsOpen( ) )
   {
      std::cout << "   Initialized" << std::endl;
   }
   else
   {
      std::cout << "   Failed to initialize" << std::endl;
   }

   for( int retry = 0; retry < 10; retry++ )
   {
      udpClient.Transmit( buffer, 12 );
      usleep( 1000 * 1000 );
   }

   return( status );
}