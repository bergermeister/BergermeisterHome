#include "pch.h"

using namespace GNCommon;
using namespace GNCommon::GNNotification;

/**
 * Default Constructor
 */
GTcAlert::GTcAlert( void )
{
   // this->voID     invokes the default constructor
   // this->voStatus invokes the default constructor
   this->vulTimestamp = 0;
   this->vulData      = 0;
}

/**
 * Default Destructor
 */
GTcAlert::~GTcAlert( void )
{
   // Nothing to destruct
}

/**
 * Copy Constructor
 * @param aorAlert   Alert Constant Reference to copy
 */
GTcAlert::GTcAlert( const GTcAlert& aorAlert )
{
   *this = aorAlert;
}

/**
 * operator= Override
 * @param   aorAlert    Alert Constant Reference to copy
 * @return  *this       GTcAlert Reference
 */
GTcAlert& GTcAlert::operator=( const GTcAlert& aorAlert )
{
   this->MSetIdentifier( aorAlert.voID         );
   this->MSetStatus    ( aorAlert.voStatus     );
   this->MSetTimestamp ( aorAlert.vulTimestamp );
   this->MSetData      ( aorAlert.vulData      );

   return *this;
}

/**
 * MSetIdentifier
 * @param   aorID    Identifier Structure Constant Reference
 */
void GTcAlert::MSetIdentifier( const GTcIdentifier& aorID )
{
   if ( this->voID != aorID )
   {
      this->voID = aorID;
      this->VoEvent.MNotify( this, static_cast< GTu32 >( GTcEventId::XeIdentifier ) );
   }
}

/**
 * MSetStatus
 * @param   aorStatus   Status Structure Constant Reference
 */
void GTcAlert::MSetStatus( const GTcStatus& aorStatus )
{
   if ( this->voStatus != aorStatus )
   {
      this->voStatus = aorStatus;
      this->VoEvent.MNotify( this, static_cast< GTu32 >( GTcEventId::XeStatus ) );
   }
}

/**
 * MSetTimeStamp
 * @param   aulTimestamp   constant 64-bit Integer Timestamp
 */
void GTcAlert::MSetTimestamp( const GTu64 aulTimestamp )
{
   if ( this->vulTimestamp != aulTimestamp )
   {
      this->vulTimestamp = aulTimestamp;
      this->VoEvent.MNotify( this, static_cast< GTu32 >( GTcEventId::XeTimestamp ) );
   }
}

/**
 * MSetData
 * @param   aulData     constant 64-bit Integer Data
 */
void GTcAlert::MSetData( const GTu64 aulData )
{
   if ( this->vulData != aulData )
   {
      this->vulData = aulData;
      this->VoEvent.MNotify( this, static_cast< GTu32 >( GTcEventId::XeData ) );
   }
}

/**
 * MGetIdentifier
 * @return  this->voID  constant TsIdentifier
 */
GTcIdentifier GTcAlert::MGetIdentifier( void ) const
{
   return this->voID;
}

/**
 * MGetStatus
 * @return  this->voStatus    constant TsStatus
 */
GTcStatus GTcAlert::MGetStatus( void ) const
{
   return this->voStatus;
}

/**
 * MGetTimestamp
 * @return  this->vulTimestamp   constant 64-bit Integer Timestamp
 */
GTu64 GTcAlert::MGetTimestamp( void ) const
{
   return this->vulTimestamp;
}

/**
 * MGetTrigger
 * @return  this->vulData     constant 64-bit Integer Data
 */
GTu64 GTcAlert::MGetData( void ) const
{
   return this->vulData;
}

