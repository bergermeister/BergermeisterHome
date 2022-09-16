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
#ifndef BDF_Network_IPEndpoint_h
#define BDF_Network_IPEndpoint_h

// BDF Includes
#include <BDF/Environment.h>

namespace BDF
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

