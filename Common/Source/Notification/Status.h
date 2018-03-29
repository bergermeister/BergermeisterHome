#pragma once

namespace GNCommon
{
   namespace GNNotification
   {
      class GXCommonDLL GTcStatus
      {
      public:        // Public Attributes
         GTu8           vucActive       : 1; /**< Bit        0 : Active Flag */
         GTu8           vucAcknowledged : 1; /**< Bit        1 : Acknowledged Flag */
         GTu8           vucCleared      : 1; /**< Bit        2 : Cleared Flag */
         GTu8           vucTrigger      : 1; /**< Bit        3 : Trigger Available Flag */
         GTu8           vucSpare1       : 4; /**< Bits  4 -  7 : Spare Flags */
         GTcCriticality voCriticality;       /**< Bits  8 - 15 : Alert Level */
         GTu8           vucSpare2;           /**< Bits 16 - 23 : Spare */
         GTu8           vucChildren;         /**< Bits 24 - 31 : Number of Child Alerts */

      public:        // Public Methods
         GTcStatus ( void );
         ~GTcStatus( void );
         GTcStatus ( const GTcStatus& aorStatus );
         GTcStatus& operator=( const GTcStatus& aorStatus );

         GTb8 operator==( const GTcStatus& aorStatus );
         GTb8 operator!=( const GTcStatus& aorStatus );
      };
   }
}
