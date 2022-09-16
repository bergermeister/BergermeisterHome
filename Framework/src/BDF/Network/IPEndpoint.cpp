// BDF Includes
#include <BDF/Network/IPEndpoint.h>

namespace BDF
{
   namespace Network
   {
      IPEndpoint::IPEndpoint( void )
      {
         this->addressInfo = nullptr;
         this->valid = false;
      }

      IPEndpoint::IPEndpoint( const std::string& Address, uint16_t Port )
         : address( Address ), port( Port )
      {
         struct addrinfo addressHints;
         char portStr[ 16 ];
         int status;

         /// @par Process Design Language
         /// -# Convert the port to a string
         snprintf( portStr, sizeof( portStr ), "%d", this->port );

         /// -# Initialize the details about the address
         std::memset( &addressHints, 0, sizeof( addressHints ) );
         addressHints.ai_family = AF_UNSPEC;
         addressHints.ai_socktype = SOCK_DGRAM;
         addressHints.ai_protocol = IPPROTO_UDP;

         /// -# Obtain a pointer to the address information
         status = getaddrinfo( this->address.c_str( ), portStr, &addressHints, &this->addressInfo );
         
         /// -# If the address information is invalid, indicate this IPEndpoint is invalid
         if( ( status != 0 ) || ( this->addressInfo == nullptr ) )
         {
            this->valid = false;
         }
         /// -# Else indicate this IPEndpoint is valid
         else
         {
            this->valid = true;
         }
      }

      IPEndpoint::~IPEndpoint( void )
      {
         freeaddrinfo( this->addressInfo );
      }

      void IPEndpoint::Update( struct sockaddr_in& Address, const size_t Length )
      {

      }
   }
}

