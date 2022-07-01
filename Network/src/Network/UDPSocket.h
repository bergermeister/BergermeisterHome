/**
 * @file Socket.h
 * @author Eisenberger, Edward (Edward.Eisenberger@live.com)
 * @brief 
 * @version 0.1
 * @date 2022-07-01
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#ifndef Bergermeister_Network_UDPSocket_h
#define Bergermeister_Network_UDPSocket_h

// Linux Includes
#include <netdb.h>

namespace Bergermeister
{
   namespace Network
   {
      class UDPSocket
      {
         private:    // Private Attributes
            struct sockaddr_in address;   ///< 
            int id;                       ///< 
            bool open;
            bool bound;

         public:     // Public Methods
            UDPSocket( void );
            bool Open( void );
            bool Bind( const uint16_t Port );
            bool Close( void );

            inline uint16_t Port( void ) const { return( ntohs( this->address.sin_port ) ); }
            inline int ID( void ) const { return( this->id ); }
            inline bool IsOpen( void ) const { return( this->open ); }
            inline bool IsBound( void ) const { return( this->open ); }
      };
   }
}

#endif

