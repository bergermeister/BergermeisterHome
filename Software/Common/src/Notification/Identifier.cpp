/**
 * @file Identifier.cpp
 *
 * Package implementation for the Alert Identifier
 */
#include <Types.h>
#include <Notification\GroupId.h>
#include <Notification\ComponentId.h>
#include <Notification\Identifier.h>

using namespace GNCommon;
using namespace GNCommon::NNotification;

/**
 * Default Constructor
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
TcIdentifier::TcIdentifier( void )
{
   this->vucIndex  = 0;
   this->voGroup   = TcGroupId::XeNone;    
   this->voCompDet = TcComponentId::XeNone;
   this->voCompGen = TcComponentId::XeNone;
}

/**
 * Copy Constructor
 *
 * Copies the internal members of the given Identifier to this Identifier via the assignment operator.
 *
 * @return  None
 *
 * @par Formal Parameters
 * @PRM{ in, aorIdentifier,   Identifier object reference to be copied }
 *
 * @par Local Symbols
 * @LOC{ None }
 */
TcIdentifier::TcIdentifier( const TcIdentifier& aorIdentifier )
{
   *this = aorIdentifier;
}

/**
* Destructor
*
* Nothing to destruct.
*
* @return   None
*
* @par Formal Parameters
* @PRM{ None }
*
* @par Local Symbols
* @LOC{ None }
*/
TcIdentifier::~TcIdentifier( void )
{
   // Nothing to Destruct
}

/**
 * Assignment Operator
 *
 * Copies the internal members of the given Identifier
 *
 * @return  Identifier object reference to this Identifier
 *
 * @par Formal Parameters
 * @PRM{ in, aorIdentifier,   Identifier object reference to be copied }
 *
 * @par Local Symbols
 * @LOC{ None }
 */
TcIdentifier& TcIdentifier::operator=( const TcIdentifier& aorIdentifier )
{
   this->vucIndex  = aorIdentifier.vucIndex;
   this->voGroup   = aorIdentifier.voGroup;
   this->voCompDet = aorIdentifier.voCompDet;
   this->voCompGen = aorIdentifier.voCompGen;

   return( *this );
}

/**
 * Equality Operator
 *
 * Compares this Identifier to the given Identifier and returns if they are equal.
 *
 * @return  True if all of this Identifier's internal members equal the given Identifier's internal members, False otherwise
 *
 * @par Formal Parameters
 * @PRM{ in, aorIdentifier,   Identifier object reference to be compared }
 *
 * @par Local Symbols
 * @LOC{ kbEqual,   Flag indicating if the Identifiers are equal }
 */
Tb8 TcIdentifier::operator==( const TcIdentifier& aorIdentifier )
{
   Tb8 kbEqual = true; // Assume Equal

   if ( ( this->vucIndex  != aorIdentifier.vucIndex  ) ||
        ( this->voGroup   != aorIdentifier.voGroup   ) ||
        ( this->voCompDet != aorIdentifier.voCompDet ) ||
        ( this->voCompGen != aorIdentifier.voCompGen ) )
   {
      kbEqual = false;
   }

   return( kbEqual );
}

/**
 * Inequality Operator
 *
 * Compares this Identifier to the given Identifier and returns if they are not equal.
 *
 * @return  True if any of this Identifier's internal members are not equal to the given Identifier's internal members, False otherwise
 *
 * @par Formal Parameters
 * @PRM{ in, aorIdentifier,   Identifier object reference to be compared }
 *
 * @par Local Symbols
 * @LOC{ None }
 */
Tb8 TcIdentifier::operator!=( const TcIdentifier& aorIdentifier )
{
   return( !( *this == aorIdentifier ) );
}

