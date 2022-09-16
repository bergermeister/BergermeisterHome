// Bergermeister Network Includes
#include <BDF/Network/UDPSocket.h>

namespace BDF
{
   namespace Network
   {
      UDPSocket::UDPSocket( void )
      {
         this->open = false;
         this->bound = false;
      }

      bool UDPSocket::Open( void )
      {
         /// @par Process Design Language
         /// -# Verify the UDP Socket is not already open
         if( !this->open )
         {
            /// -# Create a UDP Socket
            this->id = socket( AF_INET, SOCK_DGRAM | SOCK_NONBLOCK, IPPROTO_UDP );
            
            /// -# If the Socket ID is -1
            ///   -# Socket failed to create
            ///   -# Indicate not open
            if( this->id == -1 )
            {
               this->open = false;
            }
            /// -# Else the socket created successfully
            ///   -# Indicate open
            else
            {
               this->open = true;
            }
         }

         /// -# Return the Open status of the socket
         return( this->open );
      }

      bool UDPSocket::Bind( const uint16_t Port )
      {
         /// @ par Process Design Language
         /// -# Verify the socket is open
         if( !this->open )
         {
            this->bound = false;
         }
         else
         {
            /// -# Initialize the socket address
            std::memset( reinterpret_cast< void* >( &this->address ), 0, sizeof( struct sockaddr_in ) );
            this->address.sin_family = AF_INET;
            this->address.sin_port = htons( Port );
            this->address.sin_addr.s_addr = htonl( INADDR_ANY );

            /// -# Bind the socket
            if( bind( this->id, ( struct sockaddr* )&this->address, sizeof( struct sockaddr_in ) ) == -1 )
            {
               this->bound = false;
            }
            else
            {
               this->bound = true;
            }   
         }

         /// -# Return the Bound status of the socket
         return( this->bound );
      }

      bool UDPSocket::Close( void )
      {
         if( this->open )
         {
            close( this->id );
            this->open = false;
         }
         return( this->open );
      }
   }
}

