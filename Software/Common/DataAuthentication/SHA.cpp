/**
 * @file SHA.cpp
 * @brief Package implementation for the SHA base class
 */
#include <DataAuthentication\SHA.h>

using namespace GNCommon::NDataAuthentication;


TcSHA::TcSHA( void )
{
   // TODO
}

TcSHA::TcSHA( const TcSHA& aorSHA )
{
   // Call assignment operator
   *this = aorSHA;
}

TcSHA::~TcSHA( void )
{
   // TODO
}

TcSHA& TcSHA::operator=( const TcSHA& aorSHA )
{
   if( this != &aorSHA )
   {
      // TODO
   }

   return( *this );
}
