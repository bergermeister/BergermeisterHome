#pragma once

namespace GNCommon
{
   class GXCommonDLL GTcStopWatch
   {
   protected:     // Protected Attributes
      static const LONGLONG xlMaxQuadPart = 9223372036854775807;
      static const GTu64    xulTimeBase   = 1000000LL; // Microseconds
      static GTu64 vulFrequency;

      LARGE_INTEGER voStart;
      LARGE_INTEGER voEnd;
      GTb8          vbRunning;

   public:
      GTcStopWatch( void )
      {
         LARGE_INTEGER koQPF;

         if ( vulFrequency == 0 )
         {
            QueryPerformanceCounter( &koQPF );
            vulFrequency = static_cast< GTu64 >( koQPF.QuadPart ) / xulTimeBase;
         }

         this->voStart.QuadPart = 0;
         this->voEnd.QuadPart   = 0;
         this->vbRunning        = false;
      }
      GTcStopWatch( const GTcStopWatch& aorStopWatch )
      {
         *this = aorStopWatch;
      }
      GTcStopWatch& operator=( const GTcStopWatch& aorStopWatch )
      {
         this->voStart   = aorStopWatch.voStart;
         this->voEnd     = aorStopWatch.voEnd;
         this->vbRunning = aorStopWatch.vbRunning;

         return *this;
      }
      ~GTcStopWatch( void )
      {
         // Nothing to destruct
      }

      void MStart( void )
      {
         QueryPerformanceCounter( &this->voStart );
         this->vbRunning = true;
      }
      GTu64 MStop( void )
      {
         GTu64 kulElapsed = this->MElapsed( );

         this->vbRunning = false;

         return kulElapsed;
      }
      GTu64 MElapsed( void )
      {
         GTu64 kulElapsed = 0;

         if ( this->vbRunning )
         {
            QueryPerformanceCounter( &this->voEnd );
         }

         if ( this->voStart.QuadPart > this->voEnd.QuadPart )
         {
            kulElapsed = static_cast< GTu64 >( this->voEnd.QuadPart );
            kulElapsed += static_cast< GTu64 >( xlMaxQuadPart - this->voStart.QuadPart );
         }
         else
         {
            kulElapsed = static_cast< GTu64 >( this->voEnd.QuadPart - this->voStart.QuadPart );
         }
         kulElapsed /= vulFrequency;

         return kulElapsed;
      }
   };

}

