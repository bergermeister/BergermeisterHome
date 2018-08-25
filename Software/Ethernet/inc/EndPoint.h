#pragma once

namespace GNCommon
{
   namespace GNEthernet
   {
      class GXEthernetDLL GTcEndPoint : public GNCommon::GNComponent::GTcModel
      {
      public:        // Public Attributes
         static const GTu32 XuiLengthHostName = 256;


      protected:     // Protected Attributes
         const GTc8* vcpHostName;
         GTu32       vuiPort;

      public:        // Public Methods
         GTcEndPoint( void )
         {
            this->vcpHostName = nullptr;
            this->vuiPort     = 0;
         }

         GTcEndPoint( const GTc8* acpHostName, const GTu32 auiPort )
         {
            this->vcpHostName = acpHostName;
            this->vuiPort     = auiPort;
         }

         GTcEndPoint( const GTcEndPoint& aorEndPoint )
         {
            *this = aorEndPoint;
         }

         virtual ~GTcEndPoint( void )
         {
            // Nothing to destruct
         }

         GTcEndPoint& operator=( const GTcEndPoint& aorEndPoint )
         {
            this->vcpHostName = aorEndPoint.vcpHostName;
            this->vuiPort     = aorEndPoint.vuiPort;

            return *this;
         }

         void MSetHostName( const GTc8* acpHostName )
         {
            // TODO Improve comparison
            if ( this->vcpHostName != acpHostName )
            {
               this->vcpHostName = acpHostName;
               this->VoEvent.MNotify( this, static_cast< GTu32 >( GTcEventId::XeEndPointHostName ) );
            }
         }

         void MSetPort( const GTu32 auiPort )
         {
            if ( this->vuiPort != auiPort )
            {
               this->vuiPort = auiPort;
               this->VoEvent.MNotify( this, static_cast< GTu32 >( GTcEventId::XeEndPointPort ) );
            }
         }

         const GTc8* MGetHostName( void ) const
         {
            return this->vcpHostName;
         }

         GTu32 MGetPort( void ) const
         {
            return this->vuiPort;
         }
      };
   }
}

