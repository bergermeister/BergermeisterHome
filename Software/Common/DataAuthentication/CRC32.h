/**
 * @file CRC32.h
 * @brief Package interface for the CRC32 class
 */
#pragma once

#include <Types.h>

namespace GNCommon
{
   /** @brief Namespace containing Data Authentication and Validity utilities */
   namespace NDataAuthentication
   {
      /** @brief 32-bit Cycle Redundancy Code (CRC) Class */
      class TcCRC32
      {
      public:        // Public Attributes
         static const Tu32 XuiTableSize  = 256;        /**< Number of 4-bit words in the CRC-32 table */
         static const Tu32 XuiPolynomial = 0xEDB88320; /**< Polynomial used to generate the CRC-32 table */

      protected:     // Protected Attributes
         static const Tu32 xuiDefaultSeed = 0xFFFFFFFF;  /**< Default Seed value when calculating a CRC */
         static const Tu32 xuiTableCRC    = 0x6FCF9E13;  /**< CRC of the default look up table */
         static const Tu32 xuiShift8      = 8;           /**< Shift by 8 bits */
         static const Tu32 xuiMaskByte    = 0x000000FF;  /**< Single byte mask */
         static const Tu32 xuiTable[ XuiTableSize ];     /**< Lookup table */
      
      public:        // Public Methods
         TcCRC32( void );
         TcCRC32( const TcCRC32& aorCRC );
         ~TcCRC32( void );

         TcCRC32& operator=( const TcCRC32& aorCRC );

         Tu32 MGet( const Tu8* aucpBuffer, 
                    const Tu32 auiBytes, 
                    const Tu32 auiSeed = xuiDefaultSeed, 
                    const Tu32 auiTable[ XuiTableSize ] = xuiTable ) const;

         Tb8 MVerify( void ) const;

         void MGenerateTable( Tu32 auiTable[ XuiTableSize ], const Tu32 auiPolynomial = XuiPolynomial );
         Tb8  MCompareTable ( const Tu32 auiTable[ XuiTableSize ] );
      };
   }
}
