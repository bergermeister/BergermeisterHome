/**
 * @file UInt128.h
 *
 * @brief Package interface the 128-bit Unsigned Integer
 */
#pragma once

#include <Types.h>

namespace GNCommon
{
   /** @brief Namespace containing Data Authentication and Validity utilities */
   namespace NDataAuthentication
   {
      /** @brief 128-bit Unsigned Integer */
      class TcUInt512
      {
      protected:     // Protected Attributes
         static const Tu64 xulWordMax   = 0xFFFFFFFFFFFFFFFF;  /**< Max value for a 64-bit word */
         static const Tu64 xulWordCount = 8;                   /**< Number of 64-bit words in a 512-bit unsigned integer */

         Tu64 vulWord[ xulWordCount ]; /**< Words in a 512-bit unsigned integer */

      public:        // Public Methods
         TcUInt512( void );
         TcUInt512( const TcUInt512& aorUInt );
         TcUInt512( const Tu64 aulUInt[ xulWordCount ] );
         ~TcUInt512( void );

         TcUInt512& operator= ( const TcUInt512& aorUInt );
         TcUInt512& operator+=( const TcUInt512& aorUInt );
         TcUInt512& operator-=( const TcUInt512& aorUInt );
         TcUInt512& operator*=( const TcUInt512& aorUInt );
         TcUInt512& operator%=( const TcUInt512& aorUInt );

         TcUInt512  operator+( const TcUInt512& aorUInt );
         TcUInt512  operator-( const TcUInt512& aorUInt );
         TcUInt512  operator*( const TcUInt512& aorUInt );
         TcUInt512  operator%( const TcUInt512& aorUInt );

         

         TcUInt512& operator=( const Tu64 aulUInt );
         TcUInt512  operator+( const Tu64 aulUInt ) const;
         TcUInt512  operator-( const Tu64 aulUInt );
         TcUInt512  operator*( const Tu64 aulUInt );
         TcUInt512  operator%( const Tu64 aulUInt );

         TcUInt512& operator=( const Tu64 aulUInt[ xulWordCount ] );

         friend TcUInt512 operator+( const Tu64 aulUInt, const TcUInt512& aorUInt )
         {
            return( aorUInt.operator+( aulUInt ) );
         }

      protected:     // Protected Methods
         void mCarry( const Tu32 auiIndex );
      };
   }
}
