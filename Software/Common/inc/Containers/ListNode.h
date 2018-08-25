#pragma once

#include <Types.h>
#include <Constants.h>

namespace GNCommon
{
   namespace NContainers
   {
      template < class GTcType >
      class GTcListNode
      {
      protected:     // Protected Attributes
         GTcListNode< GTcType >* vopNext;
         GTcListNode< GTcType >* vopPrev;
         GTcType                 voObject;
         Tb8                    vbAvailable;

      public:        // Public Methods
         GTcListNode( void )
         {
            this->vopNext = NULL;
            this->vopPrev = NULL;
            this->vbAvailable = true;
         }

         ~GTcListNode( void )
         {
            this->vbAvailable = false;
         }

         void MSetObject( GTcType& aorObject )
         {
            this->voObject = aorObject;
         }

         GTcType* MGetObject( void )
         {
            return &this->voObject;
         }

         void MSetNext( GTcListNode< GTcType >* aopNode )
         {
            this->vopNext = aopNode;
         }

         void MSetPrev( GTcListNode< GTcType >* aopNode )
         {
            this->vopPrev = aopNode;
         }

         GTcListNode< GTcType >* MSGetNext( void )
         {
            return this->vopNext;
         }

         GTcListNode< GTcType >* MSGetPrev( void )
         {
            return this->vopPrev;
         }

         Tb8 MInsertAfter( GTcListNode< GTcType >& aorNode )
         {
            Tb8 kbSuccess = false;

            // Verify the current node is part of a list (NOT Available)
            if ( this->vbAvailable != true )
            {
               // Set new Node's pointers
               aorNode.MSetNext ( this->vopNext );
               aorNode.MSetPrev ( this );

               // If the Next Node is NOT NULL
               if ( this->vopNext != NULL )
               {
                  // Set the Next Node's Prev Node to the new Node
                  this->vopNext->MSetPrev ( &aorNode );
               }            

               // Set the Next Node Pointer to the new Node
               this->vopNext = aopNode;

               // Node inserted successfully
               kbSuccess = true;
            }

            return kbSuccess;
         }

         Tb8 MInsertBefore( GTcListNode< GTcType >& aorNode )
         {
            Tb8 kbSuccess = false;

            // Verify the current node is part of a list (NOT Available)
            if ( this->vbAvailable != true )
            {
               // Set new Node's pointers
               aorNode.MSetNext ( this );
               aorNode.MSetPrev ( this->vopPrev );

               // If the Next Node is NOT NULL
               if ( this->vopPrev != NULL )
               {
                  // Set the Next Node's Prev Node to the new Node
                  this->vopPrev->MSetNext ( &aorNode );
               }

               // Set the Prev Node Pointer to the new Node
               this->vopPrev = aopNode;

               // Node inserted successfully
               kbSuccess = true;
            }

            return kbSuccess;
         }

         Tb8 MRemove( void )
         {
            Tb8 kbSuccess = false;

            // If the node is NOT available, remove it
            if ( this->vbAvailable != true )
            {
               // If the next Node is NOT NULL
               if ( this->vopNext != NULL )
               {
                  // Set the Next Node's Previous Node to this Node's Previous Node
                  this->vopNext->MSetPrev ( this->vopPrev );
               }

               // If the previous Node is NOT NULL
               if ( this->vopPrev != NULL )
               {
                  // Set the Previous Node's Next Node to this Node's Next Node
                  this->vopPrev->MSetNext ( this->vopNext );
               }

               // Mark the Node as available
               this->vbAvailable = true; 

               // Indicate success
               kbSuccess = true;
            }

            return kbSuccess;
         }
      };
   }
}

