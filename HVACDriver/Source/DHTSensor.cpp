#include "pch.h"

using namespace GNCommon;
using namespace GNCommon::GNDrivers;
using namespace Windows::Devices::Gpio;

GTcDHTSensor::GTcDHTSensor( void )
{
   this->vopPin           = nullptr;
   this->veInputDriveMode = GpioPinDriveMode::Input;
   // TODO Initialize this->voBits
}


GTcDHTSensor::GTcDHTSensor( const GTcDHTSensor& aorSensor )
{
   *this = aorSensor;
}


GTcDHTSensor& GTcDHTSensor::operator=( const GTcDHTSensor& aorSensor )
{
   GTu32 kuiIndex;

   this->vopPin           = aorSensor.vopPin;
   this->veInputDriveMode = aorSensor.veInputDriveMode;
   this->voTimer          = aorSensor.voTimer;

   for ( kuiIndex = 0; kuiIndex < xuiByteCount; kuiIndex++ )
   {
      this->vucData[ kuiIndex ] = aorSensor.vucData[ kuiIndex ];
   }

   return *this;
}


GTcDHTSensor::~GTcDHTSensor( void )
{
   // TODO Check for destruct
}


void GTcDHTSensor::MInitialize( Windows::Devices::Gpio::GpioPin^ aopPin )
{
   this->veInputDriveMode = GpioPinDriveMode::Input;
   if ( aopPin->IsDriveModeSupported( GpioPinDriveMode::InputPullUp ) )
   {
      this->veInputDriveMode = GpioPinDriveMode::InputPullUp;
   }

   this->vopPin = aopPin;

   this->vopPin->SetDriveMode( GpioPinDriveMode::Output );
   this->vopPin->Write       ( GpioPinValue::High );
}


GTb8 GTcDHTSensor::MPullResistorRequired( void ) const
{
   return this->veInputDriveMode != GpioPinDriveMode::InputPullUp;
}


GTcDHTSensor::TeStatus GTcDHTSensor::MSample( void )
{
   TeStatus keStatus = QeStatusSuccess; // Assume Success
   GTu32    kuiIndex;
   GTu32    kuiCycles[ 80 ];
   GTu32    kuiCycleLow;
   GTu32    kuiCycleHigh;

   for ( kuiIndex = 0; kuiIndex < xuiByteCount; kuiIndex++ )
   {
      vucData[ kuiIndex ] = 0;
   }

   // Latch pin high to let pull-up raise data line level and start the reading process
   this->vopPin->SetDriveMode( GpioPinDriveMode::Output );
   this->vopPin->Write( GpioPinValue::High );
   Sleep( 250 ); // High for 250 ms

   // Set data line low for 20ms
   this->vopPin->Write( GpioPinValue::Low );
   Sleep( xuiDelayHoldLow );  // Low for 20ms

   // Latch pin high
   this->vopPin->Write( GpioPinValue::High );
   this->mSleep( xuiDelayHoldHigh ); // High for 40ms

   // Read the Pin
   this->vopPin->SetDriveMode( this->veInputDriveMode );
   this->mCheckPulse( GpioPinValue::High );//this->mSleep( 10 );

   if ( this->mCheckPulse( GpioPinValue::Low ) == 0 )
   {
      // Timeout
      keStatus = QeStatusStartHigh;
   }

   if ( this->mCheckPulse( GpioPinValue::High ) == 0 )
   {
      // Timeout
      keStatus = QeStatusStartLow;
   }

   for ( kuiIndex = 0; ( kuiIndex < 80 ) && ( keStatus == QeStatusSuccess ); kuiIndex+= 2 )
   {
      kuiCycles[ kuiIndex     ] = this->mCheckPulse( GpioPinValue::Low );
      kuiCycles[ kuiIndex + 1 ] = this->mCheckPulse( GpioPinValue::High );
   }

   for ( kuiIndex = 0; ( kuiIndex < 40 ) && ( keStatus == QeStatusSuccess ); kuiIndex++ )
   {
      kuiCycleLow  = kuiCycles[ ( kuiIndex * 2 ) ];
      kuiCycleHigh = kuiCycles[ ( kuiIndex * 2 ) + 1 ];
      if ( ( kuiCycleLow == 0 ) || ( kuiCycleHigh == 0 ) )
      {
         keStatus = QeStatusTimeout;
      }
      vucData[ kuiIndex / 8 ] <<= 1;
      if ( kuiCycleHigh > kuiCycleLow )
      {
         vucData[ kuiIndex / 8 ] |= 1;
      }
   }

   if ( keStatus == QeStatusSuccess )
   {
      if ( this->MIsValid( ) == false )
      {
         keStatus = QeStatusInvalidData;
      }
   }

   // Latch the pin high
   this->vopPin->SetDriveMode( GpioPinDriveMode::Output );
   this->vopPin->Write( GpioPinValue::High );

   return keStatus;
}


GTb8 GTcDHTSensor::MIsValid( void ) const
{
   GTu32 kuiIndex;
   GTu32 kucChecksum = 0;
   
   for ( kuiIndex = 0; kuiIndex < ( xuiByteCount - 1 ); kuiIndex++ )
   {
      kucChecksum += vucData[ kuiIndex ];
   }
   
   return ( kucChecksum == vucData[ xuiByteCount - 1 ] );
}


GTf64 GTcDHTSensor::MHumidity( void ) const
{
   return ( GTf64 )vucData[ 0 ] + ( ( GTf64 )vucData[ 1 ] / 100.0  );
}


GTf64 GTcDHTSensor::MTemperature( void ) const
{
   return ( GTf64 )vucData[ 2 ] + ( ( GTf64 )vucData[ 3 ] );
}


void GTcDHTSensor::mSleep( GTu64 aulMicroseconds )
{
   LARGE_INTEGER koQPF = { 0 }; // Processor Frequency
   LARGE_INTEGER koTimeStart;
   LARGE_INTEGER koTimeQuery;
   GTu64         kulFrequency;
   GTu64         kulElapsed = 0;

   QueryPerformanceFrequency( &koQPF );
   kulFrequency = static_cast< GTu64 >( koQPF.QuadPart ) / xulMicros;

   // Obtain the start counter
   QueryPerformanceCounter( &koTimeStart );
   while ( kulElapsed < aulMicroseconds )
   {
      QueryPerformanceCounter( &koTimeQuery );
      kulElapsed = static_cast< GTu64 >( koTimeQuery.QuadPart - koTimeStart.QuadPart );
      kulElapsed /= kulFrequency;
   }
}


GTu32 GTcDHTSensor::mCheckPulse( Windows::Devices::Gpio::GpioPinValue keLevel )
{
   GTu32 kuiCycle = 0;

   // Start the timer
   //this->voTimer.MStart( );

   // Read the pin until the level changes or a timeout occurs
   while ( ( this->vopPin->Read( ) == keLevel ) &&
           ( kuiCycle < xuiTimeout ) )
   {
      kuiCycle++;
   }

   if ( kuiCycle >= xuiTimeout )
   {
      kuiCycle = 0;
   }

   // Return 1 if the pin changed or 0 if a timeout occurred
   return kuiCycle;
}

