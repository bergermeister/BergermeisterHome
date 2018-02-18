#pragma once

namespace GNCommon
{
   namespace GNNotification
   {
      /**
       * @class GTcIdentifier
       */
      class GQCommonDLL GTcIdentifier
      {
      public:
         GTu8           vucIndex;  /**< Bits  0 -  7 : Index */
         GTcGroupId     voGroup;   /**< Bits  8 - 15 : Group */
         GTcComponentId voCompDet; /**< Bits 16 - 23 : Detecting Component */
         GTcComponentId voCompGen; /**< Bits 24 - 31 : Generating Component */

         /**
          *
          */
         GTcIdentifier( void )
         {
            this->vucIndex  = 0;
            this->voGroup   = GTcGroupId::XeNone;    
            this->voCompDet = GTcComponentId::XeNone;
            this->voCompGen = GTcComponentId::XeNone;
         }

         /**
         *
         */
         ~GTcIdentifier( void )
         {
            // Nothing to Destruct
         }

         /**
         *
         */
         GTcIdentifier( const GTcIdentifier& aorIdentifier )
         {
            *this = aorIdentifier;
         }

         /**
         *
         */
         GTcIdentifier& operator=( const GTcIdentifier& aorIdentifier )
         {
            this->vucIndex  = aorIdentifier.vucIndex;
            this->voGroup   = aorIdentifier.voGroup;
            this->voCompDet = aorIdentifier.voCompDet;
            this->voCompGen = aorIdentifier.voCompGen;

            return *this;
         }

         /**
          *
          */
         GTb8 operator==( const GTcIdentifier& aorIdentifier )
         {
            GTb8 kbEqual = true; // Assume Equal

            if ( ( this->vucIndex  != aorIdentifier.vucIndex  ) ||
                 ( this->voGroup   != aorIdentifier.voGroup   ) ||
                 ( this->voCompDet != aorIdentifier.voCompDet ) ||
                 ( this->voCompGen != aorIdentifier.voCompGen ) )
            {
               kbEqual = false;
            }

            return kbEqual;
         }

         GTb8 operator!=( const GTcIdentifier& aorIdentifier )
         {
            return !( *this == aorIdentifier );
         }
      };
   }
}
