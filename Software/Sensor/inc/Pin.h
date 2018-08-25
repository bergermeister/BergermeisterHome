#pragma once

#include <Types.h>

namespace GNCommon
{
   namespace NGPIO
   {
      enum class TcMode
      {
         XeInput                    = 0,
         XeOutput                   = 1,
         XeInputPullUp              = 2,
         XeInputPullDown            = 3,
         XeOutputOpenDrain          = 4,
         XeOutputOpenDrainPullUp    = 5,
         XeOutputOpenSource         = 6,
         XeOutputOpenSourcePullDown = 7
      };

      class TcPin
      {
      protected:     // Protected Attributes
         TcMode voMode;

      public:        // Public Methods
         TcPin( void );
         TcPin( const TcPin& aorPin );
         ~TcPin( void );

         TcPin& operator=( const TcPin& aorPin );

         void MSetMode( const TcMode aoMode );

         void MWrite( const Tb8 abHigh );
         void MWrite( const Tb8 abHigh, const Tu64 aulDebounce );

      protected:     // Protected Methods
         void mSleep( const Tu64 aulMicroseconds );
      };
   }
}

