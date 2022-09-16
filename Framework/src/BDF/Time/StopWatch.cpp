// BDF Includes
#include <BDF/Time/StopWatch.h>

namespace BDF
{
   namespace Time
   {
            StopWatch::StopWatch( void )
            {
               this->start = std::chrono::system_clock::now( );
               this->end = std::chrono::system_clock::now( );
               this->running = false;
            }

            void StopWatch::Start( void )
            {
               this->start = std::chrono::system_clock::now( );
               this->running = true;
            }

            void StopWatch::Stop( void )
            {
               this->end = std::chrono::system_clock::now( );
               this->running = false;
            }
   }
}

