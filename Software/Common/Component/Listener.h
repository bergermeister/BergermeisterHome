#pragma once

namespace GNCommon
{
   namespace NComponent
   {
      class GTcListener
      {
      public:        // Public Types
         typedef void ( *TsHandle ) ( void* aopListener, void* aopParameter );

      protected:     // Protected Attributes
         void*    vopInstance;
         TsHandle vopHandle;

      public:        // Public Methods
         GTcListener  ( void );
         GTcListener  ( void* aopInstance, const TsHandle aopHandle );
         ~GTcListener ( void );

         void*    MGetInstance ( void ) const;
         TsHandle MGetHandle   ( void ) const;

         Tb8 operator== ( const GTcListener& aorListener );
      };
   }
}