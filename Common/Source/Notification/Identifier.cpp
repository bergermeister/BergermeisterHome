#include "pch.h"

using namespace GNCommon;
using namespace GNCommon::GNNotification;

/**
 *
 */
GTcIdentifier::GTcIdentifier( void )
{
   this->vucIndex  = 0;
   this->voGroup   = GTcGroupId::XeNone;    
   this->voCompDet = GTcComponentId::XeNone;
   this->voCompGen = GTcComponentId::XeNone;
}

/**
 *
 */
GTcIdentifier::~GTcIdentifier( void )
{
   // Nothing to Destruct
}

/**
 *
 */
GTcIdentifier::GTcIdentifier( const GTcIdentifier& aorIdentifier )
{
   *this = aorIdentifier;
}

/**
 *
 */
GTcIdentifier& GTcIdentifier::operator=( const GTcIdentifier& aorIdentifier )
{
   this->vucIndex  = aorIdentifier.vucIndex;
   this->voGroup   = aorIdentifier.voGroup;
   this->voCompDet = aorIdentifier.voCompDet;
   this->voCompGen = aorIdentifier.voCompGen;

   return *this;
}

/**
 *
 */
GTb8 GTcIdentifier::operator==( const GTcIdentifier& aorIdentifier )
{
   GTb8 kbEqual = true; // Assume Equal

   if ( ( this->vucIndex  != aorIdentifier.vucIndex  ) ||
      ( this->voGroup   != aorIdentifier.voGroup   ) ||
        ( this->voCompDet != aorIdentifier.voCompDet ) ||
        ( this->voCompGen != aorIdentifier.voCompGen ) )
   {
      kbEqual = false;
   }

   return kbEqual;
}

/**
 *
 */
GTb8 GTcIdentifier::operator!=( const GTcIdentifier& aorIdentifier )
{
   return !( *this == aorIdentifier );
}

