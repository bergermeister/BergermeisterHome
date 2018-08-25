/**
 * @file MainPage.xaml.h
 * @brief Package interface for the MainPage class.
 */
#pragma once

#include "MainPage.g.h"

/** @brief Server Namespace */
namespace Server
{
	/** @brief Declaration of the MainPage class */
	public ref class MainPage sealed
	{
	public:
		MainPage();

   protected:     // Protected Methods
      virtual void OnNavigatedTo( Windows::UI::Xaml::Navigation::NavigationEventArgs^ e ) override;
      virtual void OnNavigatingFrom( Windows::UI::Xaml::Navigation::NavigatingCancelEventArgs^ e ) override;
	};
}
