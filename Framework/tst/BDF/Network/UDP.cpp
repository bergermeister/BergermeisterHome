// Google Test Includes
#include <gtest/gtest.h>

// BDF Includes
#include <BDF/Network/IPEndpoint.h>
#include <BDF/Network/UDPClient.h>
#include <BDF/Network/UDPSocket.h>

TEST( Network, UDPClient )
{
   static constexpr size_t udpPayloadLength = 256;
   static constexpr size_t hostnameMaxLength = 256;
   const char* const txMessage = "Hello LocalHost!";

   char localHostname[ hostnameMaxLength ];

   /// @par Process Design Language
   /// -# Obtain the local hostname and verify no errors were encountered
   EXPECT_EQ( gethostname( localHostname, hostnameMaxLength ), 0 );
   int port = 59200;
   BDF::Network::IPEndpoint receivedEndpoint;
   BDF::Network::IPEndpoint remoteEndpoint( std::string( localHostname ), port );
   BDF::Network::UDPClient udpClient;
   uint8_t rxBuffer[ udpPayloadLength ];
   uint8_t txBuffer[ udpPayloadLength ];
   int bytesReceived;
   int status = 0;

   /// -# Clear the rx and tx buffers
   std::memset( reinterpret_cast< void* >( rxBuffer ), 0, udpPayloadLength );
   std::memset( reinterpret_cast< void* >( txBuffer ), 0, udpPayloadLength );

   /// -# Open the Udp Client
   udpClient.Open( port );

   /// -# Send empty packet and verify reception
   udpClient.SendTo( txBuffer, udpPayloadLength, remoteEndpoint );
   bytesReceived = udpClient.ReceiveFrom( rxBuffer, udpPayloadLength, remoteEndpoint );
   status = std::memcmp( reinterpret_cast< const void* >( rxBuffer ),
                         reinterpret_cast< const void* >( txBuffer ),
                         udpPayloadLength );
   EXPECT_EQ( bytesReceived, udpPayloadLength );
   EXPECT_EQ( status, 0 );
   
   /// -# Send string packet and verify reception
   std::memcpy( reinterpret_cast< void* >( txBuffer ), 
                reinterpret_cast< const void* >( txMessage ), 
                strlen( txMessage ) );
   udpClient.SendTo( txBuffer, udpPayloadLength, remoteEndpoint );
   bytesReceived = udpClient.ReceiveFrom( rxBuffer, udpPayloadLength, remoteEndpoint );
   status = std::memcmp( reinterpret_cast< const void* >( rxBuffer ),
                         reinterpret_cast< const void* >( txBuffer ),
                         udpPayloadLength );
   EXPECT_EQ( bytesReceived, udpPayloadLength );
   EXPECT_EQ( status, 0 );
}

