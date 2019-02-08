/**
 * @file UInt128.cpp
 * @brief Package implementation for the UInt128 class
 */
#include <Types.h>
#include <DataAuthentication\UInt512.h>

using namespace GNCommon;
using namespace GNCommon::NDataAuthentication;

TcUInt512::TcUInt512( void )
{
   // Nothing to construct
}

TcUInt512::TcUInt512( const TcUInt512& aorUInt )
{
   // Call assignment operator
   *this = aorUInt;
}

TcUInt512::TcUInt512( const Tu64 aulUInt[ xulWordCount ] )
{
   // Call assignment operator
   *this = aulUInt;
}

TcUInt512::~TcUInt512( void )
{
   // Nothing to destruct
}

TcUInt512& TcUInt512::operator=( const TcUInt512& aorUInt )
{
   Tu32 kuiIndex;

   // Copy internal members
   for( kuiIndex = 0; kuiIndex < xulWordCount; kuiIndex++ )
   {
      this->vulWord[ kuiIndex ] = aorUInt.vulWord[ kuiIndex ];
   }

   return( *this );
}

TcUInt512& TcUInt512::operator+=( const TcUInt512& aorUInt )
{
   Tu32* kuipLocW = ( Tu32* )this->vulWord;
   Tu32* kuipRemW = ( Tu32* )aorUInt.vulWord;
   Tu64  kulValue = 0;
   Tu32  kuiIndex;

   for( kuiIndex = 0; kuiIndex < ( xulWordCount * ( sizeof( Tu64 ) / sizeof( Tu32 ) ) ); kuiIndex++ )
   {
      // Calculate new value and hold overflow
      kulValue = ( Tu64 )*kuipLocW + ( Tu64 )*kuipRemW + kulValue;

      // Store value and maintain overflow
      *kuipLocW = ( Tu32 )( kulValue & XulMask32 );
      
      // Shift out the lower 16 bits
      kulValue >>= XulShift32;

      // Move to next short
      kuipRemW++;
      kuipLocW++;
   }

   return( *this );
}

TcUInt512& TcUInt512::operator-=( const TcUInt512& aorUInt )
{
   Tu32* kuipLocW = ( Tu32* )this->vulWord;
   Tu32* kuipRemW = ( Tu32* )aorUInt.vulWord;
   Tu64  kulValue = 0;
   Tu64  kulUnder = 0;
   Tu32  kuiIndex;

   for( kuiIndex = 0; kuiIndex < ( xulWordCount * ( sizeof( Tu64 ) / sizeof( Tu32 ) ) ); kuiIndex++ )
   {
      //  100
      // -  5
      //   95

      // Check for underflow
      if( *kuipLocW < ( *kuipRemW + kulUnder ) )
      {
         kulValue = *kuipRemW - *kuipLocW - kulUnder;
         kulUnder = 1;
      }
      else
      {
         kulValue = *kuipLocW - *kuipRemW - kulUnder;
         kulUnder = 0;
      }

      // Store value and maintain overflow
      *kuipLocW = ( Tu32 )( kulValue & XulMask32 );

      // Move to next short
      kuipRemW++;
      kuipLocW++;
   }

   return( *this );
   return( *this );
}

TcUInt512& TcUInt512::operator*=( const TcUInt512& aorUInt )
{
   // TODO

   return( *this );
}

TcUInt512& TcUInt512::operator%=( const TcUInt512& aorUInt )
{
   // TODO

   return( *this );
}

TcUInt512 TcUInt512::operator+( const TcUInt512& aorUInt )
{
   TcUInt512 koUInt( *this );
   koUInt += aorUInt;
   return( koUInt );
}

TcUInt512 TcUInt512::operator-( const TcUInt512& aorUInt )
{
   TcUInt512 koUInt( *this );
   koUInt -= aorUInt;
   return( koUInt );
}

TcUInt512 TcUInt512::operator*( const TcUInt512& aorUInt )
{
   TcUInt512 koUInt( *this );
   koUInt *= aorUInt;
   return( koUInt );
}

TcUInt512 TcUInt512::operator%( const TcUInt512& korUInt )
{
   // TODO

   return( *this );
}

TcUInt512& TcUInt512::operator=( const Tu64 aulUInt )
{
   Tu32 kuiIndex;

   // Copy 64-bits into the first word
   this->vulWord[ 0 ] = aulUInt;

   // Zero remaining members
   for( kuiIndex = 1; kuiIndex < xulWordCount; kuiIndex++ )
   {
      this->vulWord[ kuiIndex ] = 0;
   }

   return( *this );
}

TcUInt512 TcUInt512::operator+( const Tu64 aulUInt ) const
{
   TcUInt512 aoUInt;

   aoUInt =  aulUInt;
   aoUInt += *this;

   return( aoUInt );
}

TcUInt512 TcUInt512::operator-( const Tu64 aulUInt )
{
   // TODO

   return( *this );
}

TcUInt512 TcUInt512::operator*( const Tu64 aulUInt )
{
   // TODO

   return( *this );
}

TcUInt512 TcUInt512::operator%( const Tu64 aulUInt )
{
   // TODO

   return( *this );
}

TcUInt512& TcUInt512::operator=( const Tu64 aulValue[ xulWordCount ] )
{
   Tu32  kuiIndex;

   for( kuiIndex = 0; kuiIndex < xulWordCount; kuiIndex++ )
   {
      this->vulWord[ kuiIndex ] = aulValue[ kuiIndex ];
   }

   return( *this );
}

void TcUInt512::mCarry( const Tu32 auiIndex )
{
   Tu32 kuiIndex;
   Tb8  kbCarry;

   // Check the remaining words for carry operation
   for( kuiIndex = auiIndex; kuiIndex < xulWordCount; kuiIndex++ )
   {
      // Increment the word
      this->vulWord[ kuiIndex ]++;

      if( ( xulWordMax - 1 ) >= this->vulWord[ kuiIndex ] )
      {
         break;
      }
   }
}

