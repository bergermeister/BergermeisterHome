#pragma once

namespace GNCommon
{
   namespace GNComponent
   {
      template < GTu32 auiMaxListeners >
      class GQCommonDLL GTcEvent
      {
      public:        // Public Types
         //typedef void ( Top)

      protected:     // Protected Attributes
         GNCommon::GNContainers::GTcListNode  < GTcListener > voBuffer[ auiMaxListeners ];
         GNCommon::GNContainers::GTcLinkedList< GTcListener > voListeners;

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
         void MNotify ( void* aopSender, const GTu32 auiIdentifier )
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
