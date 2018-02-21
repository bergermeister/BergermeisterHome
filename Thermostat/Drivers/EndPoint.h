#pragma once

namespace GNCommon
{
   namespace GNDriver
   {
      public ref class GTcEndPoint sealed
      {
      private:       // Private Attributes
         Windows::Networking::HostName^ vopHostName;
         Platform::String^              vopPort;
         
      public:        // Public Methods
         GTcEndPoint( void )
         {
            this->MSetHostName( L"localhost" );
            this->MSetPort    ( L"20000" );
         }
         
         GTcEndPoint( Platform::String^ aopHostName, Platform::String^ aopPort )
         {
            this->MSetHostName( aopHostName );
            this->MSetPort    ( aopPort );
         }

         /*
         GTcEndPoint( GTcEndPoint% aorEndPoint )
         {
            //*this = aorEndPoint;
            this->MSetHostName( aorEndPoint.vopHostName->ToString( ) );
            this->MSetPort    ( aorEndPoint.vopPort );
         }
         */

         virtual ~GTcEndPoint( void )
         {
            if ( this->vopHostName != nullptr )
            {
               delete this->vopHostName;
            }

            if ( this->vopPort != nullptr )
            {
               delete this->vopPort;
            }
         }

         /*
         GTcEndPoint% operator=( const GTcEndPoint% aorEndPoint )
         {
            this->MSetHostName( aorEndPoint.vopHostName->ToString( ) );
            this->MSetPort    ( aorEndPoint.vopPort );
         
            return *this;
         }
         */

         void MSetHostName( Platform::String^ aopHostName )
         {
            Windows::Networking::HostName^ kopHostName;
            try
            {
               if ( aopHostName != nullptr )
               {
                  kopHostName = ref new Windows::Networking::HostName( aopHostName );
                  if ( this->vopHostName != kopHostName )
                  {
                     if ( this->vopHostName != nullptr )
                     {
                        delete this->vopHostName;
                     }
                     this->vopHostName = kopHostName;
                     //this->VoEvent.MNotify( this, 0 ); // TODO
                  }
               }
            }
            catch ( Platform::Exception^ aopException )
            {
               // TODO Handle Exception
            }
         }

         void MSetPort( Platform::String^ aopPort )
         {
            if ( this->vopPort != aopPort )
            {
               if ( this->vopPort != nullptr )
               {
                  delete this->vopPort;
               }
               this->vopPort = aopPort;
               // this->VoEvent.MNotify( this, 0 ); // TODO
            }
         }
      
         Windows::Networking::HostName^ MGetHostName( void )
         {
            return this->vopHostName;
         }

         Platform::String^ MGetPort( void )
         {
            return this->vopPort;
         }
      };
   }
}

