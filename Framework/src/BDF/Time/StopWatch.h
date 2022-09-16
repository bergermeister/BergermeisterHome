/**
 * @file StopWatch.h
 * @author Eisenberger, Edward (Edward.Eisenberger@live.com)
 * @brief 
 * @version 0.1
 * @date 2022-08-29
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#ifndef BDF_Time_StopWatch
#define BDF_Time_StopWatch

// BDF Includes
#include <BDF/Environment.h>

namespace BDF
{
   namespace Time
   {
      class StopWatch
      {
         protected:  // Protected Attributes
            std::chrono::time_point< std::chrono::system_clock > start;
            std::chrono::time_point< std::chrono::system_clock > end;
            bool running;

         public:     // Public Methods
            StopWatch( void );
            ~StopWatch( void ) = default;

            void Start( void );
            void Stop( void );

            template< typename T > T Elapsed( void )
            {
               if( this->running )
               {
                  this->end = std::chrono::system_clock::now( );
               }
               return( std::chrono::duration_cast< T >( this->end - this->start ) );
            }

            /**
             * @brief 
             * 
             * 
             * @param None
             * @return 
             */
            inline bool IsRunning( void ) const
            {
               return( this->running );
            }
      };
   }
}

#endif

