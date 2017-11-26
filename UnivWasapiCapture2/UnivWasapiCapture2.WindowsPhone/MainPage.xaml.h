//
// MainPage.xaml.h
// Declaration of the MainPage class.
//

#pragma once

#include "MainPage.g.h"
//
#include "PhoneWasapiCapture.h"

namespace UnivWasapiCapture2
{
	/// <summary>
	/// An empty page that can be used on its own or navigated to within a Frame.
	/// </summary>
	public ref class MainPage sealed
	{
	public:
		MainPage();

	protected:
		virtual void OnNavigatedTo(Windows::UI::Xaml::Navigation::NavigationEventArgs^ e) override;

	private:
		//std::shared_ptr<PhoneWasapiCapture> pwc;
		//
		PhoneWasapiCapture *pwc;
		//
		void start(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e);
		void stop(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e);
	};
}
