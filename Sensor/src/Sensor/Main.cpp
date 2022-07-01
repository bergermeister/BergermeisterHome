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
#include <Network/IPEndpoint.h>
#include <Network/UDPClient.h>

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
   std::string localHostname = "hub.local";
   std::string remoteHostname = "DESKTOP-PM4TGPJ.local";
   int port = 59200;
   Sensor::DHT22 sensor( 4 );
   Bergermeister::Network::IPEndpoint remoteEndpoint( remoteHostname, port );
   Bergermeister::Network::UDPClient udpClient;

   std::cout << "GPIO Test..." << std::endl;   

   if( sensor.IsOpen( ) )
   {
      std::cout << "   Initialized" << std::endl;
   }
   else
   {
      std::cout << "   Failed to initialize" << std::endl;
   }

   uint8_t rxBuffer[ 256 ];
   uint8_t txBuffer[ ] = "Hello PC!";
   int bytesReceived;

   udpClient.Open( port );

   for( int retry = 0; retry < 10; retry++ )
   {
      do
      {
         bytesReceived = udpClient.ReceiveFrom( rxBuffer, 256, remoteEndpoint );
         if( bytesReceived > 0 )
         {
            std::cout << "Received " << bytesReceived << ": " << std::string( ( char* )rxBuffer ) << std::endl;
         }
      } while ( bytesReceived > 0 );
      udpClient.SendTo( txBuffer, 10, remoteEndpoint );
      usleep( 1000 * 1000 );
   }

   return( status );
}