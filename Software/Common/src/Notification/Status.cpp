/**
 * @file Status.cpp
 * @brief Package implementation for the Alert Status
 */
#include <Types.h>
#include <Notification\Criticality.h>
#include <Notification\Status.h>

using namespace GNCommon;
using namespace GNCommon::NNotification;

/**
 * @brief Default Constructor
 *
 * Initializes the internal members to default values.
 *
 * @return  None
 *
 * @par Formal Parameters
 * @PRM{ None }
 *
 * @par Local Symbols
 * @LOC{ None }
 */
TcStatus::TcStatus( void )
{
   this->vucActive       = false;
   this->vucAcknowledged = false;
   this->vucCleared      = false;
   this->vucTrigger      = false;
   this->vucSpare1       = 0;
   this->voCriticality   = TcCriticality::XeNone;
   this->vucSpare2       = 0;
   this->vucChildren     = 0;
}

/**
 * @brief Copy Constructor
 *
 * Copies the internal members of the given Status to this Status via the assignment operator.
 *
 * @return  None
 *
 * @par Formal Parameters
 * @PRM{ in, aorStatus,   Status object reference to be copied }
 *
 * @par Local Symbols
 * @LOC{ None }
 */
TcStatus::TcStatus( const TcStatus& aorStatus )
{
   *this = aorStatus;
}

/**
* @brief Destructor
*
* Nothing to destruct
*
* @return   None
*
* @par Formal Parameters
* @PRM{ None }
*
* @par Local Symbols
* @LOC{ None }
*/
TcStatus::~TcStatus( void )
{
   // Nothing to destruct
}


/**
 * @brief Assignment Operator
 *
 * Copies the internal members of the given Status
 *
 * @return  Status object reference to this Status
 *
 * @par Formal Parameters
 * @PRM{ in, aorStatus,   Status object reference to be copied }
 *
 * @par Local Symbols
 * @LOC{ None }
 */
TcStatus& TcStatus::operator=( const TcStatus& aorStatus )
{
   this->vucActive       = aorStatus.vucActive;
   this->vucAcknowledged = aorStatus.vucAcknowledged;
   this->vucCleared      = aorStatus.vucCleared;
   this->vucTrigger      = aorStatus.vucTrigger;
   this->vucSpare1       = aorStatus.vucSpare1;
   this->voCriticality   = aorStatus.voCriticality;
   this->vucSpare2       = aorStatus.vucSpare2;
   this->vucChildren     = aorStatus.vucChildren;

   return( *this );
}

/**
 * @brief Equality Operator
 *
 * Compares this Status to the given Status and returns if they are equal.
 *
 * @return  True if all of this Status's internal members equal the given Status's internal members
 *
 * @par Formal Parameters
 * @PRM{ in, aorStatus,   Status object reference to be compared }
 *
 * @par Local Symbols
 * @LOC{ kbEqual,   Flag indicating if the Statuses are equal }
 */
Tb8 TcStatus::operator==( const TcStatus& aorStatus )
{
   Tb8 kbEqual = true; // Assume Equal

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

   return( kbEqual );
}

/**
 * @brief Inequality Operator
 *
 * Compares this Status to the given Status and returns if they are not equal.
 *
 * @return  True if any of this Status's internal members are not equal to the given Status's internal members
 *
 * @par Formal Parameters
 * @PRM{ in, aorStatus,   Status object reference to be compared }
 *
 * @par Local Symbols
 * @LOC{ None }
 */
Tb8 TcStatus::operator!=( const TcStatus& aorStatus )
{
   return( !( *this == aorStatus ) );
}

