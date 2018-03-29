#pragma once

namespace GNCommon
{
   namespace GNComponent
   {
      class GXCommonDLL GTcModel
      {
      protected:     // Protected Constants
         static const GTu32 xuiMaxListeners = 16;

      public:     // Protected Attributes
         GTcEvent< xuiMaxListeners > VoEvent;

      public:        // Public Methods
         GTcModel ( void );
         ~GTcModel( void );
      };
   }
}
