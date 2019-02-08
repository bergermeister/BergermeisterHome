#pragma once

#include <Types.h>
#include <Component\Event.h>

namespace GNCommon
{
   namespace NComponent
   {
      class TcModel
      {
      protected:     // Protected Constants
         static const Tu32 xuiMaxListeners = 16;

      public:     // Protected Attributes
         GTcEvent< xuiMaxListeners > VoEvent;

      public:        // Public Methods
         TcModel ( void );
         ~TcModel( void );
      };
   }
}
