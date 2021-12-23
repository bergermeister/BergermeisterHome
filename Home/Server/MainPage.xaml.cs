

// The Blank Page item template is documented at https://go.microsoft.com/fwlink/?LinkId=402352&clcid=0x409

namespace Server
{
   using System;
   using System.Collections.Generic;
   using System.IO;
   using System.Linq;
   using System.Runtime.InteropServices.WindowsRuntime;
   using Windows.Devices.Gpio;
   using Windows.Foundation;
   using Windows.Foundation.Collections;
   using Windows.UI.Xaml;
   using Windows.UI.Xaml.Controls;
   using Windows.UI.Xaml.Controls.Primitives;
   using Windows.UI.Xaml.Data;
   using Windows.UI.Xaml.Input;
   using Windows.UI.Xaml.Media;
   using Windows.UI.Xaml.Navigation;

   /// <summary>
   /// An empty page that can be used on its own or navigated to within a Frame.
   /// </summary>
   public sealed partial class MainPage : Page
   {
      private const int LED_PIN = 5;
      private GpioPin pin;
      private GpioPinValue pinValue;
      private DispatcherTimer timer;
      private SolidColorBrush redBrush = new SolidColorBrush(Windows.UI.Colors.Red);
      private SolidColorBrush grayBrush = new SolidColorBrush(Windows.UI.Colors.LightGray);
      private Model.DHT sensor = new Model.DHT();

      public MainPage( )
      {
         this.InitializeComponent( );

         timer = new DispatcherTimer( );
         timer.Interval = TimeSpan.FromMilliseconds( 5000 );
         timer.Tick += Timer_Tick;
         InitGPIO( );
         if( pin != null )
         {
            timer.Start( );
         }
      }

      private void InitGPIO( )
      {
         var gpio = GpioController.GetDefault();

         // Show an error if there is no GPIO controller
         if( gpio == null )
         {
            pin = null;
            //GpioStatus.Text = "There is no GPIO controller on this device.";
            return;
         }

         pin = gpio.OpenPin( LED_PIN );
         pinValue = GpioPinValue.High;
         pin.Write( pinValue );
         pin.SetDriveMode( GpioPinDriveMode.Output );
         sensor.Initialize( gpio.OpenPin( 6 ), gpio.OpenPin( 13 ) );
      }

      private void Timer_Tick( object sender, object e )
      {
         Model.DHT.Status status = sensor.Sample( );
         txtDHTStatus.Text      = string.Format( "Status:      {0}", status );
         txtDHTTemperature.Text = string.Format( "Temeprature: {0}", sensor.Temperature );
         txtDHTHumidity.Text    = string.Format( "Humidity:    {0}", sensor.Humidity );

         if( pinValue == GpioPinValue.High )
         {
            pinValue = GpioPinValue.Low;
            pin.Write( pinValue );
            //LED.Fill = redBrush;
         }
         else
         {
            pinValue = GpioPinValue.High;
            pin.Write( pinValue );
            //LED.Fill = grayBrush;
         }
      }
   }
}
