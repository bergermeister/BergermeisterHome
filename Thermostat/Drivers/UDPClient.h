#pragma once

namespace GNCommon
{
   namespace GNDriver
   {
      public ref class GTcUDPClient sealed
      {
      private:       // Private Methods
         //GTcEndPoint                                     voLocal;
         //GTcEndPoint                                     voRemote;
         Windows::Networking::Sockets::DatagramSocket^   vopSocket;
         Windows::Networking::Sockets::SocketErrorStatus veErrorStatus;
         Platform::String^                               vopStatus;
         GTb8                                            vbInitialized;

      public:        // Public Methods
         GTcUDPClient( void )
         {
            this->vbInitialized = false;
            this->veErrorStatus = Windows::Networking::Sockets::SocketErrorStatus::Unknown;
            this->vopStatus     = "Uninitialized";
            this->vopSocket     = nullptr;
         }

         virtual ~GTcUDPClient( void )
         {
            this->MClose( );

            if ( this->vopStatus != nullptr )
            {
               delete this->vopStatus;
            }
         }

         GTb8 MOpen( GTcEndPoint^ aorLocal, GTcEndPoint^ aorRemote )
         {
            // Information obtained from https://docs.microsoft.com/en-us/uwp/api/Windows.Networking.Sockets.DatagramSocket

            using Windows::Foundation::TypedEventHandler;
            using Windows::Networking::HostName;
            using Windows::Networking::Sockets::DatagramSocket;
            using Windows::Networking::Sockets::DatagramSocketMessageReceivedEventArgs;
            using Windows::Networking::Sockets::SocketErrorStatus;

            this->vbInitialized = false;
            this->veErrorStatus = SocketErrorStatus::Unknown;
            this->vopStatus     = "Uninitialized";

            try
            {
               // Copy Endpoint Configurations
               //this->voLocal  = aorLocal;
               //this->voRemote = aorRemote;
               
               // Initialize new DatagramSocket
               this->vopSocket = ref new DatagramSocket( );
               
               // Attach Message Received Handler
               this->vopSocket->MessageReceived += ref new TypedEventHandler< DatagramSocket^, DatagramSocketMessageReceivedEventArgs^ >( this, &GTcUDPClient::mOnReceive );
               
               // Bind Listening Endpoint
               Concurrency::create_task( this->vopSocket->BindEndpointAsync( aorLocal->MGetHostName( ), aorLocal->MGetPort( ) ) ).then( [this] { } );

               // Connect to Remote Endpoint
               Concurrency::create_task( this->vopSocket->ConnectAsync( aorRemote->MGetHostName( ), aorRemote->MGetPort( ) ) ).then( [this] { } );

               this->vbInitialized = true;
            }
            catch ( Platform::Exception^ aopException )
            {
               this->veErrorStatus = Windows::Networking::Sockets::SocketError::GetStatus( aopException->HResult );
               this->vopStatus     = "Error: " + this->veErrorStatus.ToString( ) + aopException->Message;
            }

            return this->vbInitialized;
         }

         void MClose( void )
         {
            if ( this->vopSocket != nullptr )
            {
               delete this->vopSocket; // Delete calls ->Close( )
            }
         }

         void MSend( const Platform::Array< GTu8 >^ aucpBuffer )
         {
            using Windows::Storage::Streams::DataWriter;

            DataWriter^ kopWriter;

            if ( this->vbInitialized )
            {
               try
               {
                  // Create Data Writer
                  kopWriter = ref new DataWriter( this->vopSocket->OutputStream );

                  // Write the buffer
                  kopWriter->WriteBytes( aucpBuffer );

                  // Store Async
                  Concurrency::create_task( kopWriter->StoreAsync( ) );//.then( [=] { } );
               }
               catch ( Platform::Exception^ aopException )
               {
                  this->veErrorStatus = Windows::Networking::Sockets::SocketError::GetStatus( aopException->HResult );
                  this->vopStatus     = "Error: " + this->veErrorStatus.ToString( ) + aopException->Message;
               }
            }
         }

      protected:     // Protected Methods
         void mOnReceive( Windows::Networking::Sockets::DatagramSocket^ aopSender, Windows::Networking::Sockets::DatagramSocketMessageReceivedEventArgs^ aopArgs )
         {
            using Windows::Storage::Streams::DataReader;

            DataReader^              kopReader;
            Platform::Array< GTu8 >^ kopBuffer;

            try
            {
               kopReader = aopArgs->GetDataReader( );
               kopBuffer = ref new Platform::Array< GTu8 >( kopReader->UnconsumedBufferLength );
               kopReader->ReadBytes( kopBuffer );
            }
            catch ( Platform::Exception^ aopException )
            {
               this->veErrorStatus = Windows::Networking::Sockets::SocketError::GetStatus( aopException->HResult );
               this->vopStatus     = "Error: " + this->veErrorStatus.ToString( ) + aopException->Message;
            }
         }
      };
   }
}

