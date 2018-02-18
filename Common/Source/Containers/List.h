#pragma once

namespace GNCommon
{
   namespace GNContainers
   {
      template < class GTcType >
      class GTcList
      {
       // Public Properties
      public:    GTcType*& VorItem;   // Reference to Item Buffer
      protected: GTcType*  vopBuffer; // Protected Buffer

      public:    const GTu32& VuirCapacity; // Read-only Capacity
      protected: GTu32        vuiCapacity;  // Protected Capacity

      public:    const GTu32& VuirCount; // Read-only Count
      protected: GTu32        vuiCount;  // Protected Count 
      
      public:        // Public Methods
         GTcList( GTcType* aopBuffer, const GTu32 auiCapacity ) :
            VorItem     ( this->vopBuffer   ),
            VuirCapacity( this->vuiCapacity ),
            VuirCount   ( this->vuiCount    )
         {
            this->vopBuffer   = aopBuffer;
            this->vuiCapacity = 0;
            this->vuiCount    = 0;
         }
         GTcList( const GTcList< GTcType >& aorList ) :
            VorItem     ( this->vopBuffer   ),
            VuirCapacity( this->vuiCapacity ),
            VuirCount   ( this->vuiCount    )
         {
            *this = aorList;
         }
         ~GTcList( void )
         {
            // Nothing to Destruct
         }

         virtual GTcList< GTcType >& operator=( const GTcList< GTcType >& aorList )
         {
            this->vopBuffer   = aorList.vopBuffer;
            this->vuiCapacity = aorList.vuiCapacity;
            this->vuiCount    = aorList.vuiCount;
         }

         // Add to the List
         virtual GTb8 MAdd   ( const GTcType& aorItem )
         {
            GTb8 kbSuccess = false;

            if ( this->vuiCount < this->vuiCapacity )
            {
               // TODO
            }

            return kbSuccess;
         }
         virtual GTb8 MInsert( const GTcType& aorItem, const GTu32 auiIndex )
         {
            GTb8 kbSuccess = false;

            if ( this->VuirCount < this->VuirCapacity )
            {
               // TODO
            }

            return kbSuccess;
         }
         
         // Remove from the List
         virtual GTb8 MRemove  ( const GTcType& aorItem  )
         {
            GTu32 kuiIndex = this->MIndexOf ( aorItem );

            return this->MRemvoeAt ( kuiIndex );
         }
         virtual GTb8 MRemvoeAt( const GTu32    auiIndex )
         {
            GTb8  kbRemoved = false;
            GTu32 kuiIndex;

            // If the index is less than the count
            if ( auiIndex < this->MCount ( ) )
            {
               // Starting at the index, loop through each item
               for ( kuiIndex = auiIndex; kuiIndex < this->MCount ( ) - 1; kuiIndex++ )
               {
                  // Copy the next item over the current item
                  this->vopBuffer[ kuiIndex ] = this->vopBuffer[ kuiIndex + 1 ];
               }

               // Decrement the count
               this->vuiCount--;

               // Indicate success
               kbRemoved = true;
            }
         }
         virtual void MClear   ( void )
         {
            this->vuiCount = 0;
         }

         // Find in the list
         virtual GTb8  MContains( const GTcType& aorItem ) const
         {
            GTu32 kuiIndex = this->MIndexOf ( aorItem );

            return ( GTb8 )( kuiIndex != this->MCapacity ( ) );
         }
         virtual GTu32 MIndexOf ( const GTcType& aorItem ) const
         {
            GTu32 kuiIndex;
            GTu32 kuiIndexOf = this->MCapacity ( );

            for ( kuiIndex = 0; kuiIndex < this->MCount ( ); kuiIndex++ )
            {
               if ( this->vopBuffer[ kuiIndex ] == aorItem )
               {
                  kuiIndexOf = kuiIndex;
                  break;
               }
            }

            return kuiIndexOf;
         }

         // List Size
         GTu32 MCapacity ( void ) const
         {
            return this->vuiCapacity;
         }
         GTu32 MCount    ( void ) const
         {
            return this->vuiCount;
         }
      };
   }
}

