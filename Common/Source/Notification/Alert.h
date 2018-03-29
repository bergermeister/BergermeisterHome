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
      class GXCommonDLL GTcAlert : public GNCommon::GNComponent::GTcModel
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
         GTcAlert ( void );
         ~GTcAlert( void );
         GTcAlert ( const GTcAlert& aorAlert );
         GTcAlert& operator=( const GTcAlert& aorAlert );

         void MSetIdentifier( const GTcIdentifier& aorID        );
         void MSetStatus    ( const GTcStatus&     aorStatus    );
         void MSetTimestamp ( const GTu64          aulTimestamp );
         void MSetData      ( const GTu64          aulData      );

         GTcIdentifier MGetIdentifier( void ) const;
         GTcStatus     MGetStatus    ( void ) const;
         GTu64         MGetTimestamp ( void ) const;
         GTu64         MGetData      ( void ) const;
      };
   }
}

