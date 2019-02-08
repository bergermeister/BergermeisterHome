/**
 * @file StopWatch.h
 * 
 * Package interface for the Stop Watch class interface
 */
#pragma once

namespace GNCommon
{
   class GTcStopWatch
   {
   protected:     // Protected Attributes
      static const Ti64 xlMaxQuadPart = 9223372036854775807;  /**<  */
      static const Tu64 xulTimeBase   = 1000000LL;            /**< Microseconds */
      static Tu64 vulFrequency;

      Ti64 vlStart;
      Ti64 vlEnd;
      Tb8  vbRunning;

   public:
      GTcStopWatch( void );
      GTcStopWatch( const GTcStopWatch& aorStopWatch );
      ~GTcStopWatch( void );

      GTcStopWatch& operator=( const GTcStopWatch& aorStopWatch );

      void  MStart  ( void );
      Tu64 MStop   ( void );
      Tu64 MElapsed( void );
   };

}

