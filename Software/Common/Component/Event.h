#pragma once

#include <Types.h>
#include <Containers\ListNode.h>
#include <Containers\LinkedList.h>
#include <Component\Listener.h>

/** @brief Namespace containing Common components and infrastrucutre */
namespace GNCommon
{
   namespace NComponent
   {
      template < Tu32 auiMaxListeners >
      class GTcEvent
      {
      public:        // Public Types
         //typedef void ( Top)

      protected:     // Protected Attributes
         GNCommon::NContainers::GTcListNode  < GTcListener > voBuffer[ auiMaxListeners ];
         GNCommon::NContainers::GTcLinkedList< GTcListener > voListeners;

      public:        // Public Methods
         /**
          *
          */
         GTcEvent( void )
         {
            // Initialize the Linked List of Listeners
            this->voListeners.MInitialize ( voBuffer, auiMaxListeners );
         }

         /**
         *
         */
         ~GTcEvent ( void )
         {
            // Nothing to destruct
         }

         /**
         *
         */
         void MNotify ( void* aopSender, const Tu32 auiIdentifier )
         {
            if ( this->voListeners.MIsInitialized ( ) == true )
            {
               // TODO: Obtain Iterator and iterate through linked list
            }
         }

         /**
         *
         */
         GTcEvent& operator+= ( const GTcListener& aorListener )
         {
            if ( this->voListeners.MIsInitialized ( ) )
            {
               this->voListeners.MInsertAtTail ( aorListener );
            }

            return *this;
         }

         /**
         *
         */
         GTcEvent& operator-= ( const GTcListener& aorListener )
         {
            if ( this->voListeners.MIsInitialized ( ) )
            {
               this->voListeners.MInsertAtTail ( aorListener );
            }

            return *this;
         }
      };
   }
}
