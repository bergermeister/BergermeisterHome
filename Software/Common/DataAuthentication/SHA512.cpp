#include <Types.h>
#include <DataAuthentication\SHA.h>
#include <DataAuthentication\SHA512.h>

using namespace GNCommon;
using namespace GNCommon::NDataAuthentication;

const Tu64 TcSHA512::xulConstant[ xuiConstCnt ] =
{
   0x428a2f98d728ae22, 0x7137449123ef65cd, 0xb5c0fbcfec4d3b2f, 0xe9b5dba58189dbbc, 
   0x3956c25bf348b538, 0x59f111f1b605d019, 0x923f82a4af194f9b, 0xab1c5ed5da6d8118, 
   0xd807aa98a3030242, 0x12835b0145706fbe, 0x243185be4ee4b28c, 0x550c7dc3d5ffb4e2, 
   0x72be5d74f27b896f, 0x80deb1fe3b1696b1, 0x9bdc06a725c71235, 0xc19bf174cf692694, 
   0xe49b69c19ef14ad2, 0xefbe4786384f25e3, 0x0fc19dc68b8cd5b5, 0x240ca1cc77ac9c65, 
   0x2de92c6f592b0275, 0x4a7484aa6ea6e483, 0x5cb0a9dcbd41fbd4, 0x76f988da831153b5, 
   0x983e5152ee66dfab, 0xa831c66d2db43210, 0xb00327c898fb213f, 0xbf597fc7beef0ee4, 
   0xc6e00bf33da88fc2, 0xd5a79147930aa725, 0x06ca6351e003826f, 0x142929670a0e6e70, 
   0x27b70a8546d22ffc, 0x2e1b21385c26c926, 0x4d2c6dfc5ac42aed, 0x53380d139d95b3df, 
   0x650a73548baf63de, 0x766a0abb3c77b2a8, 0x81c2c92e47edaee6, 0x92722c851482353b, 
   0xa2bfe8a14cf10364, 0xa81a664bbc423001, 0xc24b8b70d0f89791, 0xc76c51a30654be30, 
   0xd192e819d6ef5218, 0xd69906245565a910, 0xf40e35855771202a, 0x106aa07032bbd1b8,
   0x19a4c116b8d2d0c8, 0x1e376c085141ab53, 0x2748774cdf8eeb99, 0x34b0bcb5e19b48a8,
   0x391c0cb3c5c95a63, 0x4ed8aa4ae3418acb, 0x5b9cca4f7763e373, 0x682e6ff3d6b2b8a3, 
   0x748f82ee5defb2fc, 0x78a5636f43172f60, 0x84c87814a1f0ab72, 0x8cc702081a6439ec, 
   0x90befffa23631e28, 0xa4506cebde82bde9, 0xbef9a3f7b2c67915, 0xc67178f2e372532b, 
   0xca273eceea26619c, 0xd186b8c721c0c207, 0xeada7dd6cde0eb1e, 0xf57d4f7fee6ed178, 
   0x06f067aa72176fba, 0x0a637dc5a2c898a6, 0x113f9804bef90dae, 0x1b710b35131c471b, 
   0x28db77f523047d84, 0x32caab7b40c72493, 0x3c9ebe0a15c9bebc, 0x431d67c49c100d4c, 
   0x4cc5d4becb3e42b6, 0x597f299cfc657e2a, 0x5fcb6fab3ad6faec, 0x6c44198c4a475817 
};

const Tu64 TcSHA512::xulDefaultHash[ XuiLengthHash / sizeof( Tu64 ) ] =
{
   0x6A09E667F3BCC908, 0xBB67AE8584CAA73B, 0x3C6EF372FE94F82B, 0xA54FF53A5F1D36F1,
   0x510E527FADE682D1, 0x9B05688C2B3E6C1F, 0x1F83D9ABFB41BD6B, 0x5BE0CD19137E2179
};

const Tu8 TcSHA512::xucPadding[ xuiLengthBlock ]
{
   0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};

void TcSHA512::MInitialize( void )
{
   Tu32 kuiIndex;

   // Preprocess
   // 1. Set the initial hash to the default
   for( kuiIndex = 0; kuiIndex < ( XuiLengthHash / sizeof( Tu64 ) ); kuiIndex++ )
   {
      this->vulHash[ kuiIndex ] = xulDefaultHash[ kuiIndex ];
   }

   // Clear the working block
   for( kuiIndex = 0; kuiIndex < ( xuiLengthBlock / sizeof( Tu64 ) ); kuiIndex++ )
   {
      this->vulBlock[ kuiIndex ] = 0;
   }

   // Reset the digested byte count and block count
   this->vuiDigested  = 0;
   this->vuiBlockSize = 0;
}

void TcSHA512::MProcess( const Tu8* aucpMessage, const Tu32 auiLength )
{
   Tu32 kuiRemaining = auiLength;
   Tu32 kuiBytes;
   Tu32 kuiIndex;
   Tu8* kucpBlock = reinterpret_cast< Tu8* >( this->vulBlock ) ;
   Tu8* kucpData  = const_cast< Tu8* >( aucpMessage );

   kucpBlock += this->vuiBlockSize;

   // Process the incoming data
   while( kuiRemaining > 0 )
   {
      // The buffer can hold at most 128 bytes
      kuiBytes = xuiLengthBlock - vuiBlockSize;
      if( kuiBytes > kuiRemaining )
      {
         kuiBytes = kuiRemaining;
      }

      // Copy the data to the buffer
      for( kuiIndex = 0; kuiIndex < kuiBytes; kuiIndex++ )
      {
         kucpBlock[ kuiIndex ] = kucpData[ kuiIndex ];
      }

      // Update the SHA-512 context
      this->vuiBlockSize += kuiBytes;
      this->vuiDigested  += kuiBytes;

      // Advance the data pointer
      kucpData += kuiBytes;

      // Remaining bytes to process
      kuiRemaining -= kuiBytes;

      //Process message in 16-word blocks
      if( this->vuiBlockSize == xuiLengthBlock )
      {
         // Transform the 16-word block
         this->mProcessBlock( );

         // Empty the buffer
         this->vuiBlockSize = 0;
      }
   }
}

void TcSHA512::MFinalize( )
{
   Tu32 kuiIndex;
   Tu32 kuiPadSize;
   Tu32 kuiTotal;
 
   // Length of the original message (before padding)
   kuiTotal = this->vuiDigested * sizeof( Tu64 );
 
   // Pad the message so that its length is congruent to 112 modulo 128
   if( this->vuiBlockSize < 112 )
   {
      kuiPadSize = 112 - this->vuiBlockSize;
   }
   else
   {
      kuiPadSize = 128 + 112 - this->vuiBlockSize;
   }
 
   // Append padding
   this->MProcess( xucPadding, kuiPadSize );
 
   // Append the length of the original message
   this->vulBlock[ 14 ] = 0;
   this->vulBlock[ 15 ] = MSwap( kuiTotal ); // TODO: Convert to big endian
 
   // Calculate the message digest
   this->mProcessBlock( );
 
   // Convert from host byte order to big-endian byte order
   for( kuiIndex = 0; kuiIndex < 8; kuiIndex++ )
   {
      this->vulHash[ kuiIndex ] = MSwap( this->vulHash[ kuiIndex ] ); // TODO: Convert to big endian
   }
}

const Tu8* TcSHA512::MDigest( void ) const
{
   return( reinterpret_cast< const Tu8* >( const_cast< const Tu64* >( this->vulHash ) ) );
}

void TcSHA512::mProcessBlock( void )
{
   Tu32 kuiT;
   Tu64 kulTemp1;
   Tu64 kulTemp2;
 
   // Initialize the 8 working registers
   Tu64 kulA = this->vulHash[ 0 ]; 
   Tu64 kulB = this->vulHash[ 1 ];
   Tu64 kulC = this->vulHash[ 2 ];
   Tu64 kulD = this->vulHash[ 3 ];
   Tu64 kulE = this->vulHash[ 4 ];
   Tu64 kulF = this->vulHash[ 5 ];
   Tu64 kulG = this->vulHash[ 6 ];
   Tu64 kulH = this->vulHash[ 7 ];
 
   // Process message in 16-word blocks
   Tu64* kulW = this->vulBlock;
 
   // Convert from big-endian byte order to host byte order
   for( kuiT = 0; kuiT < ( xuiLengthBlock / sizeof( Tu64 ) ); kuiT++ )
   {
      kulW[ kuiT ] = MSwap( kulW[ kuiT ] ); // TODO: Convert to little endian
   }
 
   // SHA-512 hash computation (alternate method)
   for( kuiT = 0; kuiT < xuiConstCnt; kuiT++ )
   {
      // Prepare the message schedule
      if( kuiT >= ( xuiLengthBlock / sizeof( Tu64 ) ) )
      {
         mW( kuiT ) += mSig4( mW( kuiT + 14 ) ) + mW( kuiT + 9 ) + mSig3( mW( kuiT + 1 ) );
      }

      // Calculate T1 and T2
      //*
      Tu64 kulTemp3 = mSig1( kulA );
      Tu64 kulTemp4 = mMaj( kulA, kulB, kulC );

      kulTemp1 = kulH + mSig2( kulE ) + mCh( kulE, kulF, kulG ) + xulConstant[ kuiT ] + mW( kuiT );
      kulTemp2 = kulTemp3 + kulTemp4; //mSig1( kulA ) + mMaj( kulA, kulB, kulC );
      //*/

      // Update the working registers
      kulH = kulG;
      kulG = kulF;
      kulF = kulE;
      kulE = kulD + kulTemp1;
      kulD = kulC;
      kulC = kulB;
      kulB = kulA;
      kulA = kulTemp1 + kulTemp2;
   }
 
   // Update the hash value
   this->vulHash[ 0 ] += kulA;
   this->vulHash[ 1 ] += kulB;
   this->vulHash[ 2 ] += kulC;
   this->vulHash[ 3 ] += kulD;
   this->vulHash[ 4 ] += kulE;
   this->vulHash[ 5 ] += kulF;
   this->vulHash[ 6 ] += kulG;
   this->vulHash[ 7 ] += kulH;
}

