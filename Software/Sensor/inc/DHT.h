#pragma once

namespace GNCommon
{
   namespace NSensor
   {
      class TcDHT
      {
      public:        // Public Type Definitions
         enum TeStatus
         {
            QeStatusNone = 0,
            QeStatusStartHigh,
            QeStatusStartLow,
            QeStatusTimeout,     // Timed out waiting for sample
            QeStatusMissingData, // Did not catch all falling edges
            QeStatusInvalidData, // Checksum validation failed
            QeStatusSuccess
         };

      protected:     // Protected Attributes
         static const Tu64 xulThreshold     = 110LL;
         static const Tu64 xulMicros        = 1000000LL;
         static const Tu32 xuiDelayHoldLow  = 20; 
         static const Tu32 xuiDelayHoldHigh = 40;
         static const Tu32 xuiDelayPoll     = 80;
         static const Tu32 xuiDelayRead     = 30;
         static const Tu64 xuiTimeout       = 1000; // 1000 Microseconds
         static const Tu64 xulTimeoutEdge   = 1; // 1 Milliseconds
         static const Tu64 xulTimeoutSample = 10; // 10 Milliseconds
         static const Tu32 xuiByteCount     = 5;

         // Requires "Consume Windows Runtime Extension"
         //NGPIO::TcPin 
         Windows::Devices::Gpio::GpioPin^         vopPin;
         Windows::Devices::Gpio::GpioPinDriveMode veInputDriveMode;
         Tu8                                     vucData[ xuiByteCount ];
         GNCommon::GTcStopWatch                   voTimer;

      public:        // Public Methods
         TcDHT( void );
         TcDHT( const TcDHT& aorSensor );
         TcDHT& operator=( const TcDHT& aorSensor );
         ~TcDHT( void );

         void MInitialize ( Windows::Devices::Gpio::GpioPin^ aopPin );

         TeStatus        MSample ( void );
         GNCommon::Tb8  MPullResistorRequired ( void ) const;
         GNCommon::Tb8  MIsValid ( void ) const;
         GNCommon::Tf64 MHumidity ( void ) const;
         GNCommon::Tf64 MTemperature ( void ) const;

      protected:     // Protected Method
         void  mSleep( GNCommon::Tu64 aulMicroseconds );
         Tu32 mCheckPulse( Windows::Devices::Gpio::GpioPinValue keLevel );
      };
   }
}