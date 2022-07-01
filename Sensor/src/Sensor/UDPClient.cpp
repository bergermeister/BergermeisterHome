// Sensor Includes
#include <Sensor/UDPClient.h>

// StdLib Includes
#include <cstring>
#include <unistd.h>

namespace Sensor
{
      UDPClient::UDPClient( const std::string& Address, int Port )
         : address( Address ), port( Port )
      {
         struct addrinfo hints;
         char portStr[ 16 ];
         int status;
         snprintf( portStr, sizeof( portStr ), "%d", this->port );
         portStr[ sizeof( portStr ) / sizeof( portStr[ 0 ] ) - 1 ] = '\0';
         
         std::memset( &hints, 0, sizeof( hints ) );
         hints.ai_family = AF_UNSPEC;
         hints.ai_socktype = SOCK_DGRAM;
         hints.ai_protocol = IPPROTO_UDP;
         status = getaddrinfo( this->address.c_str( ), portStr, &hints, &this->addressInfo );
         if( ( status != 0 ) || ( this->addressInfo == NULL ) )
         {
            std::cerr << "invalid address or port: \"" + this->address + ":" + portStr + "\"" << std::endl;
            // throw udp_client_server_runtime_error(("invalid address or port: \"" + addr + ":" + decimal_port + "\"").c_str());
         }
         else
         {
            this->socketID = socket( this->addressInfo->ai_family, SOCK_DGRAM | SOCK_CLOEXEC | SOCK_NONBLOCK, IPPROTO_UDP );
            if( this->socketID == -1 )
            {
               freeaddrinfo( this->addressInfo );
               std::cerr << "could not create socket for: \"" + this->address + ":" + portStr + "\"" << std::endl;
               //throw udp_client_server_runtime_error(("could not create socket for: \"" + addr + ":" + decimal_port + "\"").c_str());
            }
         }
      }

      UDPClient::~UDPClient( void )
      {
         freeaddrinfo( this->addressInfo );
         close( this->socketID );
      }

      int UDPClient::Transmit( const uint8_t* Buffer, size_t Bytes )
      {
         return( sendto( this->socketID, Buffer, Bytes, 0, this->addressInfo->ai_addr, this->addressInfo->ai_addrlen ) );
      }

      int UDPClient::Receive( uint8_t* Buffer, size_t BufferSize )
      {
         //recv
         return( 0 );
      }
}
