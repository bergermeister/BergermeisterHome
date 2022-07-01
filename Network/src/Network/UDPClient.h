/**
 * @file UDPClient.h
 * @author Eisenberger, Edward (Edward.Eisenberger@live.com)
 * @brief 
 * @version 0.1
 * @date 2022-07-01
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#ifndef Sensor_UDPClient_h
#define Sensor_UDPClient_h

// Bergermeister Network Includes
#include <Network/UDPSocket.h>
#include <Network/IPEndpoint.h>

// StdLib Includes
#include <cstdint>

namespace Bergermeister
{
   namespace Network
   {
      class UDPClient
      {
         private:    // Private Attributes
            UDPSocket udpSocket;

         public:     // Public Methods
            UDPClient( void ) = default;
            ~UDPClient( void );

            inline const UDPSocket& Socket( void ) const { return( this->udpSocket ); }

            bool Open( const uint16_t Port );

            int SendTo( const uint8_t* Buffer, size_t Bytes, const IPEndpoint& RemoteEndpoint );
            int ReceiveFrom( uint8_t* Buffer, size_t BufferSize, IPEndpoint& RemoteEndpoint );
      };
   }
}

#endif

