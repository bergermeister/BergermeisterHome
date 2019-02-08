//
// MainPage.xaml.cpp
// Implementation of the MainPage class.
//

#include "pch.h"
#include "MainPage.xaml.h"
#include <DataAuthentication/CRC32.h>
#include <DataAuthentication/SHA512.h>
#include <DataAuthentication/UInt512.h>

using namespace Client;

using namespace Platform;
using namespace Windows::Foundation;
using namespace Windows::Foundation::Collections;
using namespace Windows::UI::Xaml;
using namespace Windows::UI::Xaml::Controls;
using namespace Windows::UI::Xaml::Controls::Primitives;
using namespace Windows::UI::Xaml::Data;
using namespace Windows::UI::Xaml::Input;
using namespace Windows::UI::Xaml::Media;
using namespace Windows::UI::Xaml::Navigation;

// The Blank Page item template is documented at https://go.microsoft.com/fwlink/?LinkId=402352&clcid=0x409

MainPage::MainPage()
{
   using GNCommon::Tu8;
   using GNCommon::Tu32;
   using GNCommon::Tu64;
   using GNCommon::NDataAuthentication::TcCRC32;
   using GNCommon::NDataAuthentication::TcUInt512;
   using GNCommon::NDataAuthentication::TcSHA512;

   TcSHA512  koSHA512;
   TcCRC32   koCRC;
   TcUInt512 koA;
   TcUInt512 koB;
   TcUInt512 koC;
   TcUInt512 koD;
   Tu32      kuiIndex; 

	InitializeComponent();

   koCRC.MVerify( );
   
   koA = ( GNCommon::Tu64 )0;
   koB = 0xFFFFFFFFFFFFFFFF;
   koC = 0xFFFFFFFFFFFFFFFF;
   koD = 0x0000000100000000;

   for( kuiIndex = 0; kuiIndex < 10; kuiIndex++ )
   {
      koA += koB;
      koC -= koD;
   }

   Tu64 kulLE = 0x0123456789ABCDEF;
   Tu64 kulBE = koSHA512.MSwap( kulLE );

   koSHA512.MInitialize( );
   koSHA512.MProcess( ( Tu8* )"abc", 3 );
   koSHA512.MFinalize( );

   koSHA512.MInitialize( );
   koSHA512.MProcess( ( Tu8* )"", 0 );
   koSHA512.MFinalize( );
}

