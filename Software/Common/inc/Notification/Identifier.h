/**
 * @file Identifier.h
 * @brief Package interface for the Alert Identifier
 */
#pragma once

#include <Types.h>
#include <Notification\GroupId.h>
#include <Notification\ComponentId.h>

namespace GNCommon
{
   namespace NNotification
   {
      /** Alert Identifier */
      class TcIdentifier
      {
      public:        // Public Attributes
         Tu8           vucIndex;  /**< Bits  0 -  7 : Index */
         TcGroupId     voGroup;   /**< Bits  8 - 15 : Group */
         TcComponentId voCompDet; /**< Bits 16 - 23 : Detecting Component */
         TcComponentId voCompGen; /**< Bits 24 - 31 : Generating Component */

      public:        // Public Methods
         TcIdentifier ( void );
         TcIdentifier ( const TcIdentifier& aorIdentifier );
         ~TcIdentifier( void );
         TcIdentifier& operator=( const TcIdentifier& aorIdentifier );

         Tb8 operator==( const TcIdentifier& aorIdentifier );
         Tb8 operator!=( const TcIdentifier& aorIdentifier );
      };
   }
}
