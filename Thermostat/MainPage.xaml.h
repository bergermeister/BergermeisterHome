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

   public:        // Public Methods
      MainPage();

   protected:     // Protected Methods
      void Page_Loaded( Platform::Object^ aopSender, Windows::UI::Xaml::RoutedEventArgs^ aopArgs );
      void MTimerElapsed( Windows::System::Threading::ThreadPoolTimer^ aopTimer );
	};
}
