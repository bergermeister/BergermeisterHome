#pragma once

namespace GNCommon
{
   namespace GNDrivers
   {
      class GQHVACDriverDLL GTcDHTSensor
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
         static const GNCommon::GTu64 xulThreshold     = 110LL;
         static const GNCommon::GTu64 xulMicros        = 1000000LL;
         static const GNCommon::GTu32 xuiDelayHoldLow  = 20; 
         static const GNCommon::GTu32 xuiDelayHoldHigh = 40;
         static const GNCommon::GTu32 xuiDelayPoll     = 80;
         static const GNCommon::GTu32 xuiDelayRead     = 30;
         static const GNCommon::GTu64 xuiTimeout       = 1000; // 1000 Microseconds
         static const GNCommon::GTu64 xulTimeoutEdge   = 1; // 1 Milliseconds
         static const GNCommon::GTu64 xulTimeoutSample = 10; // 10 Milliseconds
         static const GNCommon::GTu32 xuiByteCount     = 5;

         Windows::Devices::Gpio::GpioPin^         vopPin;
         Windows::Devices::Gpio::GpioPinDriveMode veInputDriveMode;
         GTu8                                     vucData[ xuiByteCount ];
         GNCommon::GTcStopWatch                   voTimer;

      public:        // Public Methods
         GTcDHTSensor( void );
         GTcDHTSensor( const GTcDHTSensor& aorSensor );
         GTcDHTSensor& operator=( const GTcDHTSensor& aorSensor );
         ~GTcDHTSensor( void );

         void MInitialize ( Windows::Devices::Gpio::GpioPin^ aopPin );

         TeStatus        MSample ( void );
         GNCommon::GTb8  MPullResistorRequired ( void ) const;
         GNCommon::GTb8  MIsValid ( void ) const;
         GNCommon::GTf64 MHumidity ( void ) const;
         GNCommon::GTf64 MTemperature ( void ) const;

      protected:     // Protected Method
         void  mSleep( GNCommon::GTu64 aulMicroseconds );
         GTu32 mCheckPulse( Windows::Devices::Gpio::GpioPinValue keLevel );
      };
   }
}