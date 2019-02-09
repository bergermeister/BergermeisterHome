#include "CppUnitTest.h"
#include <Types.h>
#include <DataAuthentication\SHA512.h>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UTCommon
{
   TEST_CLASS( UTHash )
   {
   public:
      TEST_METHOD( MTestSHA512 )
      {
         using GNCommon::NDataAuthentication::TcHash;
         using GNCommon::NDataAuthentication::TcSHA512;
         using GNCommon::Tu8;
         using GNCommon::Tu32;
         using GNCommon::Tu64;
         
         const Tu8* kopInputMsg = "abc";
         const Tu32 kuiInputLen = 3;
         TcHash*    kopHash = new TcSHA512( );

         kopHash->MInitialize( );
         kopHash->MProcess( kopInputMsg, kuiInputLen );
         kopHash->MFinalize( );
      }
   };
}