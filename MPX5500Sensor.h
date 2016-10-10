#ifndef MPX5500Sensor_h
#define MPX5500Sensor_h

#include "Arduino.h"

class MPX5500Sensor
{
public:
  MPX5500Sensor(int pin);
  int readRawValue(); // raw value read from the adc, depending on mcu
  int readBarValue(); // 0-5 Bar
  int readKpaValue(); // 0-500kPa
private:
  int _pin;
};

#endif

