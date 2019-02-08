#pragma once

#include <Types.h>
#include <Constants.h>

namespace GNCommon
{
   namespace NContainers
   {
      template < class GTcType >
      class GTcLinkedList
      {
      protected:     // Protected Attributes
         GTcListNode< GTcType >* vopBuff; // Buffer of Nodes
         GTcListNode< GTcType >* vopHead; // Pointer to the Head of the List
         GTcListNode< GTcType >* vopTail; // Pointer to the Tail of the List

         Tu32 vuiSize;       // Size of the buffer of Nodes
         Tu32 vuiCount;      // Number of Linked Nodes
         Tb8  vbInitialized; // Initialized Flag

      public:        // Public Methods
         GTcLinkedList( void )
         {
            this->vopBuff = NULL;
            this->vopHead = NULL;
            this->vopTail = NULL;

            this->vuiSize  = 0;
            this->vuiCount = 0;

            this->vbInitialized = false;
         }

         ~GTcLinkedList( void )
         {
            // Nothing to destruct
         }

         void MInitialize( GTcListNode< GTcType >* aopBuffer, Tu32 auiSize )
         {
            this->vbInitialized = false;  // Assume not initialized

            this->vopBuff = aopBuffer; // Save the node buffer pointer
            this->vuiSize = auiSize;   // Save the size of the node buffer
            this->vopHead = NULL;      // Clear the Head Node pointer
            this->vopTail = NULL;      // Clear the Tail Node pointer

                                       // If the Node Buffer is NOT NULL and its size is greater than 0
            if ( ( this->vopBuff != NULL ) && ( this->vuiSize > 0 ) )
            {
               this->vbInitialized = true; // Indicate Initialized
            }
         }

         Tb8 MIsInitialized( void ) const
         {
            return this->vbInitialized;
         }

         Tb8 MInsertAtHead( GTcType& aorObject )
         {
            // TODO
            return false;
         }

         Tb8 MInsertAtTail( GTcType& aorObject )
         {
            // TODO
            return false;
         }

         Tb8 MInsert( GTcType& aorObject )
         {
            // TODO
            return false;
         }

         Tb8 MRemoveHead( void )
         {
            // TODO
            return false;
         }

         Tb8 MRemoveTail( void )
         {
            // TODO
            return false;
         }

         Tb8 MRemove( GTcType& aorObject )
         {
            // TODO
            return false;
         }
      };
   }
}

