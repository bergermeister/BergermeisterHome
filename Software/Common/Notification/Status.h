/**
 * @file Status.h
 * @brief Package interface for the Alert Status
 */
#pragma once

#include <Types.h>
#include <Notification\Criticality.h>

namespace GNCommon
{
   namespace NNotification
   {
      /** Alert Status */
      class TcStatus
      {
      public:        // Public Attributes
         Tu8           vucActive       : 1; /**< Bit        0 : Active Flag */
         Tu8           vucAcknowledged : 1; /**< Bit        1 : Acknowledged Flag */
         Tu8           vucCleared      : 1; /**< Bit        2 : Cleared Flag */
         Tu8           vucTrigger      : 1; /**< Bit        3 : Trigger Available Flag */
         Tu8           vucSpare1       : 4; /**< Bits  4 -  7 : Spare Flags */
         TcCriticality voCriticality;       /**< Bits  8 - 15 : Alert Level */
         Tu8           vucSpare2;           /**< Bits 16 - 23 : Spare */
         Tu8           vucChildren;         /**< Bits 24 - 31 : Number of Child Alerts */

      public:        // Public Methods
         TcStatus ( void );
         TcStatus ( const TcStatus& aorStatus );
         ~TcStatus( void );
         TcStatus& operator=( const TcStatus& aorStatus );

         Tb8 operator==( const TcStatus& aorStatus );
         Tb8 operator!=( const TcStatus& aorStatus );
      };
   }
}
