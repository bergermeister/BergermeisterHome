#include "pch.h"

using namespace GNCommon;
using namespace GNCommon::GNNotification;

/**
 *
 */
GTcStatus::GTcStatus( void )
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

/**
 *
 */
GTcStatus::~GTcStatus( void )
{
   // Nothing to destruct
}

/**
 *
 */
GTcStatus::GTcStatus( const GTcStatus& aorStatus )
{
   *this = aorStatus;
}

/**
 *
 */
GTcStatus& GTcStatus::operator=( const GTcStatus& aorStatus )
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

/**
 *
 */
GTb8 GTcStatus::operator==( const GTcStatus& aorStatus )
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

/**
 *
 */
GTb8 GTcStatus::operator!=( const GTcStatus& aorStatus )
{
   return !( *this == aorStatus );
}

