namespace Server.Model
{
   using System;
   using System.Collections.Generic;
   using System.Diagnostics;
   using System.Linq;
   using System.Text;
   using System.Threading.Tasks;
   using Windows.Devices.Gpio;

   class DHT
   {
      public enum Status
      {
         None = 0,
         StartHigh,
         StartLow,
         Timeout,     // Timed out waiting for sample
         MissingData, // Did not catch all falling edges
         InvalidData, // Checksum validation failed
         Success
      }

      private const int   delayHoldLow  = 20;
      private const int   delayHoldHigh = 40;
      private const ulong timeout       = 1000; // 1000 Microseconds
      private const ulong byteCount     = 5;

      private GpioPin inputPin;
      private GpioPin outputPin;
      private GpioPinDriveMode inputDriveMode;
      private GpioChangeReader changeReader;
      private byte[] data;

      public DHT( )
      {
         this.inputPin = null;
         this.outputPin = null;
         this.inputDriveMode = GpioPinDriveMode.Input;
         this.data = new byte[ byteCount ];
      }
      public void Initialize( GpioPin aInputPin, GpioPin aOutputPin )
      {
         /// @par Process Design Language
         /// -# Determine the input drive mode
         ///   - Use InputPullUp if supported, otherwise fall back to Input (floating)
         this.inputDriveMode = aInputPin.IsDriveModeSupported( GpioPinDriveMode.InputPullUp ) ?
                               this.inputDriveMode = GpioPinDriveMode.InputPullUp : 
                               this.inputDriveMode = GpioPinDriveMode.Input;
         
         /// -# Set the Input Pin Drive Mode and obtain Gpio Change Reader
         this.inputPin = aInputPin;
         this.inputPin.SetDriveMode( GpioPinDriveMode.Output );
         this.changeReader = new GpioChangeReader( this.inputPin );

         /// -# Set the Output Pin value to Low and Drive Mode to Output
         this.outputPin.Write( GpioPinValue.Low );
         this.outputPin.SetDriveMode( GpioPinDriveMode.Output );
      }

      public Status Sample( )
      {
         return( Status.None );
      }

      public bool IsValid
      {
         get
         {
            uint index;
            uint checksum = 0;

            for( index = 0; index < ( byteCount - 1 ); index++ )
            {
               checksum += data[ index ];
            }

            return ( ( checksum & 0x000000FF ) == data[ byteCount - 1 ] );
         }
      }

      public double Humidity
      {
         get
         {
            return( ( double )data[ 0 ] + ( ( double )data[ 1 ] / 100.0 ) );
         }
      }

      public double Temperature
      {
         get
         {
            return( ( double )data[ 2 ] + ( ( double )data[ 3 ] ) );
         }
      }

      private bool sendInitialPulse( )
      {
         bool status = true;
         Stopwatch timer = new Stopwatch( );
         
         /// @par Process Design Language
         /// -# Bring the data line low for 18ms
         this.outputPin.Write( GpioPinValue.Low );
         timer.Start( );
         while( timer.ElapsedMilliseconds < 18 )
         {
            ;
         }
         this.outputPin.Write( GpioPinValue.High );

         /// -# Verify initial pulse is less than 30ms
         if( timer.ElapsedMilliseconds > 30 )
         {
            status = false;
         }

         return( status );
      }
   }
}
