/**
 * @file Hash.cpp
 * @brief Package implementation for the Hash interface
 */
#include <Types.h>
#include <DataAuthentication/Hash.h>

using namespace GNCommon::NDataAuthentication;

TcHash::TcHash( void )
{
   // TODO
}

TcHash::TcHash( const TcHash& aorHash )
{
   // Call assignment operator
   *this = aorHash;
}

TcHash::~TcHash( void )
{
   // TODO
}

TcHash& TcHash::operator=( const TcHash& aorHash )
{
   if( this != &aorHash )
   {
      // TODO
   }

   return( *this );
}
