#include <pch.h>

// Define Windows 32-bit LEAN_AND_MEAN
#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN
#endif
#include <windows.h>
#include <gpio.h>
#include <windows.devices.gpio.h>
#include <windows.devices.gpio.provider.h>

using namespace GNCommon;
using namespace GNCommon::NGPIO;

TcPin::TcPin( void )
{
   // TODO
}

TcPin::TcPin( const TcPin& aorPin )
{
   *this = aorPin;
}

TcPin::~TcPin( void )
{
   // TODO
}

TcPin& TcPin::operator=( const TcPin& aorPin )
{
   // TODO
   this->voMode = aorPin.voMode;

   return( *this );
}

void TcPin::MSetMode( const TcMode aoMode )
{
   this->voMode = aoMode;
}

void TcPin::MWrite( const Tb8 abHigh )
{
   // TODO
}

void TcPin::MWrite( const Tb8 abHigh, const Tu64 aulDebounce )
{
   this->MWrite( abHigh );
   this->mSleep( aulDebounce );
}

void TcPin::mSleep( const Tu64 aulMicroseconds )
{
   GTcStopWatch koTimer;
   koTimer.MStart( );
   while( koTimer.MElapsed( ) < aulMicroseconds );
   koTimer.MStop( );
}

