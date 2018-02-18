/**
 * @file Alert.h

 * Alert Class Interface.
 */

#pragma once

namespace GNCommon
{
   namespace GNNotification
   {
      /**
       * @class GTcAlert
       *
       * Alert Class
       */
      class GQCommonDLL GTcAlert : public GNCommon::GNComponent::GTcModel
      {
      public:        // Public Type Definitions
         static const GTu32 XuiSizeOfIdentifier = sizeof( GTcIdentifier ); /**< Size of Identifier */
         static const GTu32 XuiSizeOfStatus     = sizeof( GTcStatus     ); /**< Size of Status */

      protected:     // Protected Attributes
         GTcIdentifier voID;         /**< Encoded Identifier */
         GTcStatus     voStatus;     /**< Encoded Status */
         GTu64         vulTimestamp; /**< 64-bit Timestamp of Occurrence */
         GTu64         vulData;      /**< 64-bit Additional Data */

      public:        // Public Methods
         /**
         * Default Constructor
         */
         GTcAlert( void )
         {
            // this->voID     invokes the default constructor
            // this->voStatus invokes the default constructor
            this->vulTimestamp = 0;
            this->vulData      = 0;
         }

         /**
         * Default Destructor
         */
         ~GTcAlert( void )
         {
            // Nothing to destruct
         }

         /**
         * Copy Constructor
         * @param aorAlert   Alert Constant Reference to copy
         */
         GTcAlert( const GTcAlert& aorAlert )
         {
            *this = aorAlert;
         }
      
         /**
         * operator= Override
         * @param   aorAlert    Alert Constant Reference to copy
         * @return  *this       GTcAlert Reference
         */
         GTcAlert& operator=( const GTcAlert& aorAlert )
         {
            this->MSetIdentifier( aorAlert.voID         );
            this->MSetStatus    ( aorAlert.voStatus     );
            this->MSetTimestamp ( aorAlert.vulTimestamp );
            this->MSetData      ( aorAlert.vulData      );

            return *this;
         }

         

         /**
         * MSetIdentifier
         * @param   aorID    Identifier Structure Constant Reference
         */
         void MSetIdentifier( const GTcIdentifier& aorID )
         {
            if ( this->voID != aorID )
            {
               this->voID = aorID;
               this->VoEvent.MNotify( this, static_cast< GTu32 >( GTcEventId::XeIdentifier ) );
            }
         }

         /**
         * MSetStatus
         * @param   aorStatus   Status Structure Constant Reference
         */
         void MSetStatus( const GTcStatus& aorStatus )
         {
            if ( this->voStatus != aorStatus )
            {
               this->voStatus = aorStatus;
               this->VoEvent.MNotify( this, static_cast< GTu32 >( GTcEventId::XeStatus ) );
            }
         }

         /**
         * MSetTimeStamp
         * @param   aulTimestamp   constant 64-bit Integer Timestamp
         */
         void MSetTimestamp( const GTu64 aulTimestamp )
         {
            if ( this->vulTimestamp != aulTimestamp )
            {
               this->vulTimestamp = aulTimestamp;
               this->VoEvent.MNotify( this, static_cast< GTu32 >( GTcEventId::XeTimestamp ) );
            }
         }

         /**
         * MSetData
         * @param   aulData     constant 64-bit Integer Data
         */
         void MSetData( const GTu64 aulData )
         {
            if ( this->vulData != aulData )
            {
               this->vulData = aulData;
               this->VoEvent.MNotify( this, static_cast< GTu32 >( GTcEventId::XeData ) );
            }
         }

         /**
         * MGetIdentifier
         * @return  this->voID  constant TsIdentifier
         */
         GTcIdentifier MGetIdentifier( void ) const
         {
            return this->voID;
         }

         /**
         * MGetStatus
         * @return  this->voStatus    constant TsStatus
         */
         GTcStatus MGetStatus( void ) const
         {
            return this->voStatus;
         }
      
         /**
         * MGetTimestamp
         * @return  this->vulTimestamp   constant 64-bit Integer Timestamp
         */
         GTu64 MGetTimestamp( void ) const
         {
            return this->vulTimestamp;
         }
      
         /**
         * MGetTrigger
         * @return  this->vulData     constant 64-bit Integer Data
         */
         GTu64 MGetData( void ) const
         {
            return this->vulData;
         }
      };
   }
}

