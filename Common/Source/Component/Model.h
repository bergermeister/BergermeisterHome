#pragma once

namespace GNCommon
{
   namespace GNComponent
   {
      class GQCommonDLL GTcModel
      {
      protected:     // Protected Constants
         static const GTu32 xuiMaxListeners = 16;

      public:     // Protected Attributes
         GTcEvent< xuiMaxListeners > VoEvent;

      public:        // Public Methods
         GTcModel( void )
         {

         }

         ~GTcModel ( void )
         {
            // Nohing to destruct
         }
      };
   }
}
