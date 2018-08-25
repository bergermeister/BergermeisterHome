namespace GNCommon
{
   namespace GNEthernet
   {
      class GTcUDPClient
      {
      protected:     // Protected Attributes
         //Windows::Networking::Sockets::DatagramSocket^ vopSocket;

      public:        // Public Methods
         GTcUDPClient( void )
         {
         }

         GTcUDPClient( const GTcUDPClient& aorClient )
         {
         }

         virtual ~GTcUDPClient( void )
         {
            // Nothing to destruct
         }

         //GTb8 MOpen( const GTcEndPoint& aorLocal, const GTcEndPoint& aorRemtoe )
         //{
         //}
         //
         //void MClose( void )
         //{
         //   if ( this->vopSocket != nullptr )
         //   {
         //      delete this->vopSocket; // Delete calls ->Close( )
         //   }
         //}
         //
         //GTb8 MSend( const GTu8* aucpBuffer, const GTu32 auiLength )
         //{
         //
         //}

      protected:     // Protected Methods
         //void mOnReceive( Windows::Networking::Sockets::DatagramSocket^ aopSender, Windows::Networking::Sockets::DatagramSocketMessageReceivedEventArgs^ aopArgs )
         //{
         //   using Windows::Storage::Streams::DataReader;
         //
         //   DataReader^              kopReader;
         //   Platform::Array< GTu8 >^ kopBuffer;
         //
         //   try
         //   {
         //      kopReader = aopArgs->GetDataReader( );
         //      kopBuffer = ref new Platform::Array< GTu8 >( kopReader->UnconsumedBufferLength );
         //      kopReader->ReadBytes( kopBuffer );
         //   }
         //   catch ( Platform::Exception^ aopException )
         //   {
         //      this->veErrorStatus = Windows::Networking::Sockets::SocketError::GetStatus( aopException->HResult );
         //      this->vopStatus     = "Error: " + this->veErrorStatus.ToString( ) + aopException->Message;
         //   }
         //}
      };
   }
}

