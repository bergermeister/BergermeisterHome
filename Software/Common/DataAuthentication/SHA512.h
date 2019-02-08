/**
 * @file SHA512.h
 * @brief Package interface for the SHA512 class
 */
#pragma once

#include <Types.h>
#include <DataAuthentication/SHA.h>
#include <DataAuthentication/UInt512.h>

namespace GNCommon
{
   /** @brief Namespace containing Data Authentication and Validity utilities */
   namespace NDataAuthentication
   {
      /** @brief 512-bit Secure Hashing Algorithm */
      class TcSHA512 : public TcSHA
      {
      public:        // Public Attributes
         static const Tu32 XuiLengthHash  =  64;   /**< Length of Hash in bytes */

      protected:     // Protected Attributes
         static const Tu32 xuiConstCnt    =  80;
         static const Tu32 xuiLengthBlock = 128;   /**< Length of pad buffer in bytes */
         static const Tu64 xulConstant   [ xuiConstCnt ];
         static const Tu64 xulDefaultHash[ XuiLengthHash / sizeof( Tu64 ) ];
         static const Tu8  xucPadding[ xuiLengthBlock ];

         Tu64 vulBlock[ xuiLengthBlock / sizeof( Tu64 ) ];  /**< Padding buffer */
         Tu64 vulHash [ XuiLengthHash  / sizeof( Tu64 ) ];  /**< Calculated Hash */
         Tu32 vuiDigested;                                  /**< Number of bytes digested */
         Tu32 vuiBlockSize;

      public:        // Public Methods
         void MInitialize( void );
         void MProcess( const Tu8* aucpData, const Tu32 auiLength );
         void MFinalize( void );

         virtual const Tu8* MGet( void ) const;

      protected:     // Protected Methods
         void mProcessBlock( void );
        
         inline Tu64 mSig1( const Tu64& aulrX )
         {
            return( mROTR( aulrX, 28, 64 ) ^ mROTR( aulrX, 34, 64 ) ^ mROTR( aulrX, 39, 64 ) );
         }

         inline Tu64 mSig2( const Tu64& aulrX )
         {
            return( mROTR( aulrX, 14, 64 ) ^ mROTR( aulrX, 18, 64 ) ^ mROTR( aulrX, 41, 64 ) );
         }

         inline Tu64 mSig3( const Tu64& aulrX )
         {
            return( mROTR( aulrX, 1, 64 ) ^ mROTR( aulrX, 8, 64 ) ^ mSHR( aulrX, 7 ) );
         }

         inline Tu64 mSig4( const Tu64& aulrX )
         {
            return( mROTR( aulrX, 19, 64 ) ^ mROTR( aulrX, 61, 64 ) ^ mSHR( aulrX, 6 ) );
         }

         inline Tu64& mW( const Tu32 auiT )
         {
            return( this->vulBlock[ auiT & 0x0F ] );
         }
      };
   }
}

