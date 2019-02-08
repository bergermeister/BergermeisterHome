/**
 * @file Alert.h
 * @brief Package interface for the Alert Class
 */
#pragma once

#include <Types.h>
#include <Component\Model.h>
#include <Notification\ComponentId.h>
#include <Notification\Identifier.h>
#include <Notification\Status.h>

namespace GNCommon
{
   /** @brief Namespace containing system Alerts */
   namespace NNotification
   {
      /** Alert Class */
      class TcAlert : public GNCommon::NComponent::TcModel
      {
      public:        // Public Type Definitions
         static const Tu32 XuiSizeOfIdentifier = sizeof( TcIdentifier ); /**< Size of Identifier */
         static const Tu32 XuiSizeOfStatus     = sizeof( TcStatus     ); /**< Size of Status */

      protected:     // Protected Attributes
         TcIdentifier voID;         /**< Encoded Identifier */
         TcStatus     voStatus;     /**< Encoded Status */
         Tu64         vulTimestamp; /**< 64-bit Timestamp of Occurrence */
         Tu64         vulData;      /**< 64-bit Additional Data */

      public:        // Public Methods
         TcAlert ( void );
         ~TcAlert( void );
         TcAlert ( const TcAlert& aorAlert );
         TcAlert& operator=( const TcAlert& aorAlert );

         void MSetIdentifier( const TcIdentifier& aorID        );
         void MSetStatus    ( const TcStatus&     aorStatus    );
         void MSetTimestamp ( const Tu64          aulTimestamp );
         void MSetData      ( const Tu64          aulData      );

         TcIdentifier MGetIdentifier( void ) const;
         TcStatus     MGetStatus    ( void ) const;
         Tu64         MGetTimestamp ( void ) const;
         Tu64         MGetData      ( void ) const;
      };
   }
}

