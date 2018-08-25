#pragma once

namespace GNCommon
{
   namespace NContainers
   {
      template < class GTcType >
      class GTcList
      {
       // Public Properties
      public:    GTcType*& VorItem;   // Reference to Item Buffer
      protected: GTcType*  vopBuffer; // Protected Buffer

      public:    const Tu32& VuirCapacity; // Read-only Capacity
      protected: Tu32        vuiCapacity;  // Protected Capacity

      public:    const Tu32& VuirCount; // Read-only Count
      protected: Tu32        vuiCount;  // Protected Count 
      
      public:        // Public Methods
         GTcList( GTcType* aopBuffer, const Tu32 auiCapacity ) :
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
         virtual Tb8 MAdd   ( const GTcType& aorItem )
         {
            Tb8 kbSuccess = false;

            if ( this->vuiCount < this->vuiCapacity )
            {
               // TODO
            }

            return kbSuccess;
         }
         virtual Tb8 MInsert( const GTcType& aorItem, const Tu32 auiIndex )
         {
            Tb8 kbSuccess = false;

            if ( this->VuirCount < this->VuirCapacity )
            {
               // TODO
            }

            return kbSuccess;
         }
         
         // Remove from the List
         virtual Tb8 MRemove  ( const GTcType& aorItem  )
         {
            Tu32 kuiIndex = this->MIndexOf ( aorItem );

            return this->MRemvoeAt ( kuiIndex );
         }
         virtual Tb8 MRemvoeAt( const Tu32    auiIndex )
         {
            Tb8  kbRemoved = false;
            Tu32 kuiIndex;

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
         virtual Tb8  MContains( const GTcType& aorItem ) const
         {
            Tu32 kuiIndex = this->MIndexOf ( aorItem );

            return ( Tb8 )( kuiIndex != this->MCapacity ( ) );
         }
         virtual Tu32 MIndexOf ( const GTcType& aorItem ) const
         {
            Tu32 kuiIndex;
            Tu32 kuiIndexOf = this->MCapacity ( );

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
         Tu32 MCapacity ( void ) const
         {
            return this->vuiCapacity;
         }
         Tu32 MCount    ( void ) const
         {
            return this->vuiCount;
         }
      };
   }
}

