/**
 * @file MainPage.xaml.cpp
 * @brief Package implementation for the MainPage class
 */

#include "pch.h"
#include "MainPage.xaml.h"
#include <Types.h>
#include <DataAuthentication\CRC32.h>

using namespace Server;

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
   using GNCommon::Tb8;
   using GNCommon::Tu32;
   using GNCommon::NDataAuthentication::TcCRC32;

	InitializeComponent();
   
   Tu32    kuiCRCTable[ TcCRC32::XuiTableSize ];
   TcCRC32 koCRC;
   Tb8     kbMatch;
   
   koCRC.MGenerateTable( kuiCRCTable );
   kbMatch = koCRC.MCompareTable( kuiCRCTable );
   kbMatch = koCRC.MVerify( );
}

void MainPage::OnNavigatedTo( Windows::UI::Xaml::Navigation::NavigationEventArgs^ e )
{
   Windows::Networking::Sockets::DatagramSocket^ aopSocket;
}

void MainPage::OnNavigatingFrom( Windows::UI::Xaml::Navigation::NavigatingCancelEventArgs^ e )
{
}

