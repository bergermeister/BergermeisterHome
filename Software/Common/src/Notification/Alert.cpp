#include <Types.h>
#include <Notification\EventId.h>
#include <Notification\Identifier.h>
#include <Notification\Status.h>
#include <Notification\Alert.h>

using namespace GNCommon;
using namespace GNCommon::NNotification;

/**
 * Default Constructor
 */
TcAlert::TcAlert( void )
{
   // this->voID     invokes the default constructor
   // this->voStatus invokes the default constructor
   this->vulTimestamp = 0;
   this->vulData      = 0;
}

/**
 * Default Destructor
 */
TcAlert::~TcAlert( void )
{
   // Nothing to destruct
}

/**
 * Copy Constructor
 * @param aorAlert   Alert Constant Reference to copy
 */
TcAlert::TcAlert( const TcAlert& aorAlert )
{
   *this = aorAlert;
}

/**
 * operator= Override
 * @param   aorAlert    Alert Constant Reference to copy
 * @return  *this       GTcAlert Reference
 */
TcAlert& TcAlert::operator=( const TcAlert& aorAlert )
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
void TcAlert::MSetIdentifier( const TcIdentifier& aorID )
{
   if ( this->voID != aorID )
   {
      this->voID = aorID;
      this->VoEvent.MNotify( this, static_cast< Tu32 >( TcEventId::XeIdentifier ) );
   }
}

/**
 * MSetStatus
 * @param   aorStatus   Status Structure Constant Reference
 */
void TcAlert::MSetStatus( const TcStatus& aorStatus )
{
   if ( this->voStatus != aorStatus )
   {
      this->voStatus = aorStatus;
      this->VoEvent.MNotify( this, static_cast< Tu32 >( TcEventId::XeStatus ) );
   }
}

/**
 * MSetTimeStamp
 * @param   aulTimestamp   constant 64-bit Integer Timestamp
 */
void TcAlert::MSetTimestamp( const Tu64 aulTimestamp )
{
   if ( this->vulTimestamp != aulTimestamp )
   {
      this->vulTimestamp = aulTimestamp;
      this->VoEvent.MNotify( this, static_cast< Tu32 >( TcEventId::XeTimestamp ) );
   }
}

/**
 * MSetData
 * @param   aulData     constant 64-bit Integer Data
 */
void TcAlert::MSetData( const Tu64 aulData )
{
   if ( this->vulData != aulData )
   {
      this->vulData = aulData;
      this->VoEvent.MNotify( this, static_cast< Tu32 >( TcEventId::XeData ) );
   }
}

/**
 * MGetIdentifier
 * @return  this->voID  constant TsIdentifier
 */
TcIdentifier TcAlert::MGetIdentifier( void ) const
{
   return this->voID;
}

/**
 * MGetStatus
 * @return  this->voStatus    constant TsStatus
 */
TcStatus TcAlert::MGetStatus( void ) const
{
   return this->voStatus;
}

/**
 * MGetTimestamp
 * @return  this->vulTimestamp   constant 64-bit Integer Timestamp
 */
Tu64 TcAlert::MGetTimestamp( void ) const
{
   return this->vulTimestamp;
}

/**
 * MGetTrigger
 * @return  this->vulData     constant 64-bit Integer Data
 */
Tu64 TcAlert::MGetData( void ) const
{
   return this->vulData;
}

