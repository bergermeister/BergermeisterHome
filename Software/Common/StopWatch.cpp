#include <Windows.h>
#include <Types.h>
#include <StopWatch.h>

using namespace GNCommon;

Tu64 GTcStopWatch::vulFrequency = 0;

GTcStopWatch::GTcStopWatch( void )
{
   LARGE_INTEGER koQPF;

   if( vulFrequency == 0 )
   {
      QueryPerformanceCounter( &koQPF );
      vulFrequency = static_cast< Tu64 >( koQPF.QuadPart ) / xulTimeBase;
   }

   this->vlStart   = 0;
   this->vlEnd     = 0;
   this->vbRunning = false;
}

GTcStopWatch::GTcStopWatch( const GTcStopWatch& aorStopWatch )
{
   *this = aorStopWatch;
}

GTcStopWatch::~GTcStopWatch( void )
{
   // Nothing to destruct
}

GTcStopWatch& GTcStopWatch::operator=( const GTcStopWatch& aorStopWatch )
{
   this->vlStart   = aorStopWatch.vlStart;
   this->vlEnd     = aorStopWatch.vlEnd;
   this->vbRunning = aorStopWatch.vbRunning;

   return( *this );
}

void GTcStopWatch::MStart( void )
{
   LARGE_INTEGER koQPF;

   QueryPerformanceCounter( &koQPF ); 
   this->vlStart   = static_cast< Tu64 >( koQPF.QuadPart );
   this->vbRunning = true;
}

Tu64 GTcStopWatch::MStop( void )
{
   Tu64 kulElapsed = this->MElapsed( );

   this->vbRunning = false;

   return( kulElapsed );
}

Tu64 GTcStopWatch::MElapsed( void )
{
   LARGE_INTEGER koQPF;
   Tu64         kulElapsed = 0;

   if( this->vbRunning )
   {
      QueryPerformanceCounter( &koQPF );
      this->vlEnd = static_cast< Ti64 >( koQPF.QuadPart );
   }

   if( this->vlStart > this->vlEnd )
   {
      kulElapsed =  static_cast< Tu64 >( this->vlEnd );
      kulElapsed += static_cast< Tu64 >( xlMaxQuadPart - this->vlStart );
   }
   else
   {
      kulElapsed = static_cast< Tu64 >( this->vlEnd - this->vlStart );
   }

   kulElapsed /= vulFrequency;

   return kulElapsed;
}

