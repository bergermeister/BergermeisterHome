#pragma once

namespace GNCommon
{
   namespace GNNotification
   {
      /**
       * @class GTcIdentifier
       */
      class GXCommonDLL GTcIdentifier
      {
      public:        // Public Attributes
         GTu8           vucIndex;  /**< Bits  0 -  7 : Index */
         GTcGroupId     voGroup;   /**< Bits  8 - 15 : Group */
         GTcComponentId voCompDet; /**< Bits 16 - 23 : Detecting Component */
         GTcComponentId voCompGen; /**< Bits 24 - 31 : Generating Component */

      public:        // Public Methods
         GTcIdentifier ( void );
         ~GTcIdentifier( void );
         GTcIdentifier ( const GTcIdentifier& aorIdentifier );
         GTcIdentifier& operator=( const GTcIdentifier& aorIdentifier );

         GTb8 operator==( const GTcIdentifier& aorIdentifier );
         GTb8 operator!=( const GTcIdentifier& aorIdentifier );
      };
   }
}
