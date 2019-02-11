#include "CppUnitTest.h"
#include <Types.h>
#include <DataAuthentication\SHA512.h>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace GNCommon;
using namespace GNCommon::NDataAuthentication;

namespace UTCommon
{
   TEST_CLASS( UTHash )
   {
   public:
      TEST_METHOD( MSHA512TestVector1 )
      {         
         const Tu8* kopInputMsg = reinterpret_cast< const Tu8* >( "abc" );
         const Tu32 kuiInputLen = 3;
         const Tu64 kulExpected[ ] = 
         { 
            0xddaf35a193617aba, 0xcc417349ae204131, 0x12e6fa4e89a97ea2, 0x0a9eeee64b55d39a, 
            0x2192992a274fc1a8, 0x36ba3c23a3feebbd, 0x454d4423643ce80e, 0x2a9ac94fa54ca49f
         };

         TcHash* kopHash;
         Tu32    kuiMismatch;
         
         // Create SHA-512 object
         kopHash = new TcSHA512( );

         // Calculate SHA-512
         kopHash->MInitialize( );
         kopHash->MProcess( kopInputMsg, kuiInputLen );
         kopHash->MFinalize( );

         // Verify SHA-512
         if( !mMatches( reinterpret_cast< const Tu64* >( kopHash->MDigest( ) ), kulExpected, 
                        TcSHA512::XuiLengthHash / sizeof( Tu64 ),               kuiMismatch ) )
         {
            Assert::Fail( ( const wchar_t* )"Digest mismatch" );
         }

         // Delete SHA-512 object
         delete kopHash;
      }

   private:
      static Tb8 mMatches( const Tu64* aulpActual, const Tu64* aulpExpected, 
                           const Tu32  auiWords,   Tu32&       auirMismatch )
      {
         Tu32 kuiIndex;
         Tb8  kbMatches = true;  // Assume match

         for( kuiIndex = 0; kuiIndex < auiWords; kuiIndex++ )
         {
            if( aulpActual[ kuiIndex ] != aulpExpected[ kuiIndex ] )
            {
               auirMismatch = kuiIndex;
               kbMatches    = false;
               break;
            }
         }

         return( kbMatches );
      }
   };
}