/**
 * @file IPEndpoint.h
 * @author Eisenberger, Edward (Edward.Eisenberger@live.com)
 * @brief 
 * @version 0.1
 * @date 2022-07-01
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#ifndef Bergermeister_Network_IPEndpoint_h
#define Bergermeister_Network_IPEndpoint_h

// StdLib Includes
#include <cstdint>
#include <string>

// Linux Includes
#include <netdb.h>

namespace Bergermeister
{
   namespace Network
   {
      class IPEndpoint
      {
         private:    // private Attributes
            uint16_t port;
            std::string address;
            struct addrinfo* addressInfo;
            bool valid;

         public:     // Public Methods
            IPEndpoint( void );
            IPEndpoint( const std::string& Address, uint16_t Port );
            ~IPEndpoint( void );

            void Update( struct sockaddr_in& Address, const size_t Length );

            inline uint16_t Port( void ) const { return( this->port ); }
            inline std::string Address( void ) const { return( this->address ); }
            inline struct addrinfo* Info( void ) const { return( this->addressInfo ); }
            inline bool IsValid( void ) const { return( this->valid ); }
      };
   }
}

#endif

