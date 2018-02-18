//
// MainPage.xaml.cpp
// Implementation of the MainPage class.
//

#include "pch.h"
#include "MainPage.xaml.h"

using namespace Thermostat;

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
using namespace Windows::UI::Core;
using namespace Windows::System::Threading;
using namespace Windows::Devices::Gpio;
using namespace GNCommon;
using namespace GNCommon::GNDrivers;

using namespace 
// The Blank Page item template is documented at https://go.microsoft.com/fwlink/?LinkId=402352&clcid=0x409

MainPage::MainPage()
{
	InitializeComponent();
}


void MainPage::Page_Loaded( Object^ aopSender, RoutedEventArgs^ aopArgs )
{
   GTb8            kbSuccess     = true; // Assume success
   GpioController^ kopController = GpioController::GetDefault( );
   GpioPin^        kopPin;
   TimeSpan        koPeriod = { 2LL * 10000000LL }; // Periodic timer to sample from the DHT11 every 2 seconds

   if ( kopController == nullptr )
   {
      this->statusText->Text = L"GPIO is not available on this sytem";
      kbSuccess = false;
   }

   if ( kbSuccess )
   {
      try
      {
         kopPin = kopController->OpenPin ( xuiDHTPinNumber );
      }
      catch ( Exception^ aopException )
      {
         this->statusText->Text = L"Failed to open GPIO pin: " + aopException->Message;
         kbSuccess = false;
      }
   }

   if ( kbSuccess )
   {
      this->voSensor.MInitialize( kopPin );
      if ( this->voSensor.MPullResistorRequired ( ) )
      {
         this->pullResistorText->Text = L"10k pull-up resistor required.";
      }
      else
      {
         this->pullResistorText->Text = L"Pull-up resistor not required.";
      }

      this->voTimer = ThreadPoolTimer::CreatePeriodicTimer( ref new TimerElapsedHandler( this, &MainPage::MTimerElapsed ), koPeriod );

      this->statusText->Text = L"Status: Initialized Successfully";
   }
}


void MainPage::MTimerElapsed( ThreadPoolTimer^ aopTimer )
{
   static GTb8 kbRunning = false;
   GTcDHTSensor::TeStatus keStatus;
   GTu32                  kuiRetryCount = 0;
   String^                kopStrStatus;
   String^                kopStrHumidity;
   String^                kopStrTemp;
   GTf64                  kdHumidity;
   GTf64                  kdTemperature;
   HRESULT                koResult;
   wchar_t                kcpBuffer[ 128 ];                    

   if ( kbRunning == true )
      return;

   kbRunning = true;

   do
   {
      keStatus = this->voSensor.MSample( );
   } while ( ( keStatus != GTcDHTSensor::QeStatusSuccess ) && ( kuiRetryCount++ < 20 ) );

   if ( keStatus == GTcDHTSensor::QeStatusSuccess )
   {
      kdHumidity    = this->voSensor.MHumidity( );
      kdTemperature = ( this->voSensor.MTemperature( ) * 9.0 / 5.0 ) + 32;

      koResult = StringCchPrintfW( kcpBuffer,
         ARRAYSIZE( kcpBuffer ),
         L"Humidity: %.1f%% RH",
         kdHumidity );
      if ( FAILED( koResult ) )
      {
         throw ref new Exception( koResult, L"Failed to print string" );
      }
      kopStrHumidity = ref new String( kcpBuffer );

      koResult = StringCchPrintfW( kcpBuffer,
         ARRAYSIZE( kcpBuffer ),
         L"Temperature: %.1f \u00B0F",
         kdTemperature );
      if ( FAILED( koResult ) )
      {
         throw ref new Exception( koResult, L"Failed to print string" );
      }
      kopStrTemp = ref new String( kcpBuffer );

      koResult = StringCchPrintfW( kcpBuffer,
         ARRAYSIZE( kcpBuffer ),
         L"Succeeded (%d %s)",
         kuiRetryCount,
         ( kuiRetryCount == 1 ) ? L"retry" : L"retries" );
      if ( FAILED( koResult ) )
      {
         throw ref new Exception( koResult, L"Failed to print string" );
      }
      kopStrStatus = ref new String( kcpBuffer );
   }
   else
   {
      kopStrHumidity = L"Humidity: (failed)";
      kopStrTemp     = L"Temperature: (failed)";

      switch ( keStatus )
      {
      case GTcDHTSensor::QeStatusTimeout:
         kopStrStatus = L"Timed out waiting for sample";
         break;
      case GTcDHTSensor::QeStatusMissingData:
         kopStrStatus = L"Did not catch all falling edges";
         break;
      case GTcDHTSensor::QeStatusInvalidData:
         kopStrStatus = L"Checksum validation failed";
         break;
      case GTcDHTSensor::QeStatusStartHigh:
         kopStrStatus = L"Pin Started High";
         break;
      case GTcDHTSensor::QeStatusStartLow:
         kopStrStatus = L"Pin Stayed Low on Start-up";
         break;
      default:
         kopStrStatus = L"Failed to get reading";
         break;
      }
   }

   this->Dispatcher->RunAsync( CoreDispatcherPriority::Normal,
      ref new DispatchedHandler( [ = ] ( )
   {
      this->statusText->Text = kopStrStatus;
      this->humidityText->Text = kopStrHumidity;
      this->temperatureText->Text = kopStrTemp;
   } ) );

   kbRunning = false;
}

