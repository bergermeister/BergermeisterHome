#pragma once

namespace GNCommon
{
   namespace GNContainers
   {
      template < class GTcType >
      class GTcQueue
      {
      private:       // Private Attributes
         GTcType* vopBuffer; // Static buffer 
         GTu32    vuiSize;   // Maximum number of elements
         GTu32    vuiCount;  // Current number of elements
         GTu32    vuiHead;   // Index of the Head of the Queue
         GTu32    vuiTail;   // Index of the Tail of the Queue

      public:        // Public Methods
         GTcQueue  ( void );
         GTcQueue  ( GTcType* aopBuffer, GTu32 auiSize );
         ~GTcQueue ( void );

         GTb8  MEnqueue ( GTcType& aorElement );
         GTb8  MDequeue ( GTcType& aorElement );
         GTb8  MIsEmpty ( void ) const;
         GTb8  MIsFull  ( void ) const;
         GTu32 MCount   ( void ) const;
      };

      template < class GTcType >
      GTcQueue< GTcType >::GTcQueue ( void )
      {
         this->vopBuffer = NULL;
         this->vuiSize   = 0;
         this->vuiCount  = 0;
         this->vuiHead   = 0;
         this->vuiTail   = 0;
      }

      template < class GTcType >
      GTcQueue< GTcType >::GTcQueue ( GTcType* aopBuffer, GTu32 auiSize )
      {
         this->vopBuffer = aopBuffer;
         this->vuiSize   = auiSize;
         this->vuiCount  = 0;
         this->vuiHead   = 0;
         this->vuiTail   = 0;
      }

      template < class GTcType >
      GTcQueue< GTcType >::~GTcQueue ( void )
      {
         this->vopBuffer = NULL;
         this->vuiSize   = 0;
         this->vuiCount  = 0;
         this->vuiHead   = 0;
         this->vuiTail   = 0;
      }

      template < class GTcType >
      GTb8 GTcQueue< GTcType >::MEnqueue ( GTcType& aorElement )
      {
         GTb8 kbSuccess = false; // Assume Failure

         // If the Queue is NOT Full and the buffer is NOT NULL
         if ( ( this->MIsFull ( ) == false ) && ( this->vopBuffer != NULL ) )
         {
            // Copy the contents of the given element into the Tail
            this->vopBuffer[ this->vuiTail ] = aorElement;

            // Increment the Tail index and decrement the count
            this->vuiTail++;
            this->vuiCount++;

            // If the index has exceeded the size
            if ( this->vuiTail >= this->vuiSize )
            {
               // Wrap the index to 0
               this->vuiTail = 0;
            }

            // Indicate success
            kbSuccess = true;
         }

         // Return status;
         return kbSuccess;
      }

      template < class GTcType >
      GTb8 GTcQueue< GTcType >::MDequeue ( GTcType& aorElement )
      {
         GTb8 kbSuccess = false; // Assume Failure

         // If the Queue is NOT Empty and the buffer is NOT NULL
         if ( ( this->MIsEmpty ( ) == false ) && ( this->vopBuffer != NULL ) )
         {
            // Copy the contents of the Head into the given element
            aorElement = this->vopBuffer[ this->vuiHead ];

            // Increment the Head index and decrement the count
            this->vuiHead++;
            this->vuiCount--;

            // If the index has exceeded the size
            if ( this->vuiHead >= this->vuiSize )
            {
               // Wrap the index to 0
               this->vuiHead = 0;
            }

            // Indicate success
            kbSuccess = true;
         }

         // Return status
         return kbSuccess;
      }

      template < class GTcType >
      GTb8 GTcQueue< GTcType >::MIsEmpty ( void ) const
      {
         return ( GTb8 )( this->vuiCount == 0 );
      }

      template < class GTcType >
      GTb8 GTcQueue< GTcType >::MIsFull  ( void ) const
      {
         return ( GTb8 )( this->vuiCount == this->vuiSize );
      }

      template < class GTcType >
      GTu32 GTcQueue< GTcType >::MCount ( void ) const
      {
         return this->vuiCount;
      }
   }
}

