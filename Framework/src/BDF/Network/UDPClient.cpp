// BDF Includes
#include <BDF/Network/UDPClient.h>

namespace BDF
{
   namespace Network
   {
      UDPClient::~UDPClient( void )
      {
         this->udpSocket.Close( );
      }

      bool UDPClient::Open( const uint16_t Port )
      {
         if( !this->udpSocket.Open( ) )
         {
            /// @todo
         }
         else if( !this->udpSocket.Bind( Port ) )
         {
            this->udpSocket.Close( );
         }

         return( this->udpSocket.IsOpen( ) && this->udpSocket.IsBound( ) );
      }

      int UDPClient::SendTo( const uint8_t* Buffer, size_t Bytes, const IPEndpoint& RemoteEndpoint )
      {
         return( sendto( this->udpSocket.ID( ), Buffer, Bytes, 0, 
                         RemoteEndpoint.Info( )->ai_addr, 
                         RemoteEndpoint.Info( )->ai_addrlen ) );
      }

      int UDPClient::ReceiveFrom( uint8_t* Buffer, size_t BufferSize, IPEndpoint& RemoteEndpoint )
      {
         struct sockaddr_in remoteEndpoint;
         socklen_t socketLength;
         return( recvfrom( this->udpSocket.ID( ), Buffer, BufferSize, 0, 
                           reinterpret_cast< struct sockaddr* >( &remoteEndpoint ), 
                           &socketLength ) ); 
         RemoteEndpoint.Update( remoteEndpoint, socketLength );
      }
   }
}

