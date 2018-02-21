//
// MainPage.xaml.h
// Declaration of the MainPage class.
//

#pragma once

#include "MainPage.g.h"

namespace Thermostat
{
	/// <summary>
	/// An empty page that can be used on its own or navigated to within a Frame.
	/// </summary>
	public ref class MainPage sealed
	{
   private:     // Protected Attributes
      static const GNCommon::GTu32                 xuiDHTPinNumber = 21;
      GNCommon::GNDrivers::GTcDHTSensor            voSensor;
      Windows::System::Threading::ThreadPoolTimer^ voTimer;

      GNCommon::GNDriver::GTcUDPClient voSend;
      GNCommon::GNDriver::GTcUDPClient voRecv;

   public:        // Public Methods
      MainPage();

   protected:     // Protected Methods
      void Page_Loaded( Platform::Object^ aopSender, Windows::UI::Xaml::RoutedEventArgs^ aopArgs );
      void mTimerElapsed( Windows::System::Threading::ThreadPoolTimer^ aopTimer );

   private:
      void mInitUDPClients()
      {
         GNCommon::GNDriver::GTcEndPoint^ koLocal  = ref new GNCommon::GNDriver::GTcEndPoint( L"localhost", L"30000" );
         GNCommon::GNDriver::GTcEndPoint^ koRemote = ref new GNCommon::GNDriver::GTcEndPoint( L"localhost", L"40000" );

         this->voSend.MOpen( koLocal,  koRemote );
         this->voRecv.MOpen( koRemote, koLocal );

         delete koLocal;
         delete koRemote;
      }

      void mStartClient()
      {
         Platform::String^                  kopMessage = "Hello World!";
         GNCommon::GTu32                    kuiIndex;
         Platform::Array< GNCommon::GTu8 >^ kucpBuffer = ref new Platform::Array< GNCommon::GTu8 >( kopMessage->Length( ) );

         for ( kuiIndex = 0; kuiIndex < kopMessage->Length( ); kuiIndex++ )
         {
            kucpBuffer[ kuiIndex ] = static_cast< GNCommon::GTu8 >( kopMessage->Data( )[ kuiIndex ] );
         }
         
         this->voSend.MSend( kucpBuffer );
      }
	};
}
