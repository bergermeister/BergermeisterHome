/**
 * @file SHA.h
 * @brief Package interface for the SHA base class
 */
#ifndef SHA_h
#define SHA_h

#include <Types.h>
#include <DataAuthentication/Hash.h>

namespace GNCommon
{
   /** @brief Namespace containing Data Authentication and Validity utilities */
   namespace NDataAuthentication
   {
      /** @brief 32-bit Cycle Redundancy Code (CRC) Class */
      class TcSHA : public TcHash
      {
      protected:     // Protected Attributes

      public:        // Public Methods
         TcSHA( void );
         TcSHA( const TcSHA& aorSHA );
         virtual ~TcSHA( void );

         TcSHA& operator=( const TcSHA& aorSHA );

         virtual void MInitialize( void ) = 0;
         virtual void MProcess( const Tu8* aucpData, const Tu32 auiBytes ) = 0;
         virtual void MFinalize( void ) = 0;

         virtual const Tu8* MGet( void ) const = 0;

      protected:     // Protected Methods
         /**
          * @brief Rotate Left Operation
          *
          * Rotate left (circular left shift) operation, where x is a w-bit word and n is an integer with 0 <= n < w,
          * is defined by ROTL( x, n, w )=( x << n ) | ( x >> ( w - n ) )
          *
          * @return  64-bit word rotated left
          *
          * @par Formal Parameters
          * @PRM{ in, aulrX,   W-bit word to be operated on }
          * @PRM{ in, aulrN,   Integer with 0 <= N <= W }
          * @PRM{ in, aulrW,   Size of a word in bits }
          *
          * @par Local Symbols
          * @LOC{ None }
          */
         inline Tu64 mROTL( const Tu64& aulrX, const Tu64& aulrN, const Tu64& aulrW )
         {
            return( ( aulrX << aulrN ) | ( aulrX >> ( aulrW - aulrN ) ) );
         }

         /**
          * @brief Rotate Right Operation
          *
          * Rotate right (circular right shift) operation, where x is a w-bit word and n is an integer with 0 <= n < w,
          * is defined by ROTR( x, n, w )=( x >> n ) | ( x << ( w - n ) )
          *
          * @return  64-bit word rotated right
          *
          * @par Formal Parameters
          * @PRM{ in, aulrX,   W-bit word to be operated on }
          * @PRM{ in, aulrN,   Integer with 0 <= N <= W }
          * @PRM{ in, aulrW,   Size of a word in bits }
          *
          * @par Local Symbols
          * @LOC{ None }
          */
         inline Tu64 mROTR( const Tu64 aulX, const Tu64 aulN, const Tu64 aulW )
         {
            return( ( aulX >> aulN ) | ( aulX << ( aulW - aulN ) ) );
         }

         /**
          * @brief Right Shift Operation
          *
          * Rotate shift operation, where x is a w-bit word and n is an integer with 0 <= n < w,
          * is defined by ( x, n )=( x >> n )
          *
          * @return  64-bit word rotated left
          *
          * @par Formal Parameters
          * @PRM{ in, aulrX,   W-bit word to be operated on }
          * @PRM{ in, aulrN,   Integer with 0 <= N <= W }
          *
          * @par Local Symbols
          * @LOC{ None }
          */
         inline Tu64 mSHR ( const Tu64& aulrX, const Tu64& aulrN )
         {
            return( aulrX >> aulrN );
         }

         inline Tu64 mCh( const Tu64& aulrX, const Tu64& aulrY, const Tu64& aulrZ )
         {
            return( ( aulrX & aulrY ) ^ ( ~aulrX & aulrZ ) );
         }

         inline Tu64 mMaj( const Tu64& aulrX, const Tu64& aulrY, const Tu64& aulrZ )
         {
            return( ( aulrX & aulrY ) ^ ( aulrX & aulrZ ) ^ ( aulrY & aulrZ ) );
         }
      };
   }
}

#endif
