#pragma once

namespace GNCommon
{
   namespace GNNotification
   {
      class GQCommonDLL GTcStatus
      {
      public:
         GTu8           vucActive       : 1; /**< Bit        0 : Active Flag */
         GTu8           vucAcknowledged : 1; /**< Bit        1 : Acknowledged Flag */
         GTu8           vucCleared      : 1; /**< Bit        2 : Cleared Flag */
         GTu8           vucTrigger      : 1; /**< Bit        3 : Trigger Available Flag */
         GTu8           vucSpare1       : 4; /**< Bits  4 -  7 : Spare Flags */
         GTcCriticality voCriticality;       /**< Bits  8 - 15 : Alert Level */
         GTu8           vucSpare2;           /**< Bits 16 - 23 : Spare */
         GTu8           vucChildren;         /**< Bits 24 - 31 : Number of Child Alerts */
      
         GTcStatus( void )
         {
            this->vucActive       = false;
            this->vucAcknowledged = false;
            this->vucCleared      = false;
            this->vucTrigger      = false;
            this->vucSpare1       = 0;
            this->voCriticality   = GTcCriticality::XeNone;
            this->vucSpare2       = 0;
            this->vucChildren     = 0;
         }

         ~GTcStatus( void )
         {
            // Nothing to destruct
         }

         GTcStatus( const GTcStatus& aorStatus )
         {
            *this = aorStatus;
         }

         GTcStatus& operator=( const GTcStatus& aorStatus )
         {
            this->vucActive       = aorStatus.vucActive;
            this->vucAcknowledged = aorStatus.vucAcknowledged;
            this->vucCleared      = aorStatus.vucCleared;
            this->vucTrigger      = aorStatus.vucTrigger;
            this->vucSpare1       = aorStatus.vucSpare1;
            this->voCriticality   = aorStatus.voCriticality;
            this->vucSpare2       = aorStatus.vucSpare2;
            this->vucChildren     = aorStatus.vucChildren;

            return *this;
         }

         GTb8 operator==( const GTcStatus& aorStatus )
         {
            GTb8 kbEqual = true; // Assume Equal

            if ( ( this->vucActive       != aorStatus.vucActive       ) ||
                 ( this->vucAcknowledged != aorStatus.vucAcknowledged ) ||
                 ( this->vucCleared      != aorStatus.vucCleared      ) ||
                 ( this->vucTrigger      != aorStatus.vucTrigger      ) ||
                 ( this->vucSpare1       != aorStatus.vucSpare1       ) ||
                 ( this->voCriticality   != aorStatus.voCriticality   ) ||
                 ( this->vucSpare2       != aorStatus.vucSpare2       ) ||
                 ( this->vucChildren     != aorStatus.vucChildren     ) )
            {
               kbEqual = false;
            }

            return kbEqual;
         }

         GTb8 operator!=( const GTcStatus& aorStatus )
         {
            return !( *this == aorStatus );
         }
      };
   }
}
