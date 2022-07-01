 
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

// StdLib Includes
#include <cstdint>
#include <iostream>

// Linux Includes
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>

namespace Sensor
{
   class UDPClient
   {
   private:    // Private Attributes
      int socketID;
      int port;
      std::string address;
      struct addrinfo* addressInfo;

   public:     // Public Methods
      UDPClient( const std::string& Address, int Port );
      ~UDPClient( void );

      inline int SocketID( void ) const { return( this->socketID ); }
      inline int Port( void ) const { return( this->port ); }
      inline std::string Address( void ) const { return( this->address ); }

      int Transmit( const uint8_t* Buffer, size_t Bytes );
      int Receive( uint8_t* Buffer, size_t BufferSize );
   };
}

#endif

