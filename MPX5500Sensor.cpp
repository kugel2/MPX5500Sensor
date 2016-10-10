#include "Arduino.h"
#include "MPX5500Sensor.h"

MPX5500Sensor::MPX5500Sensor(int pin) {
  pinMode(pin, OUTPUT);
  _pin = pin;
}

int MPX5500Sensor::readRawValue() {
  return analogRead(_pin);
}

int MPX5500Sensor::readBarValue() {
  return readKpaValue() / 100;
  //TODO return barValue as float or shift the integer value to allow some bits after the comma
}

int MPX5500Sensor::readKpaValue() {
  unsigned long v;
  
  // multiply first and then divide to keep the resolution high, but don't overflow the unsigned long variable
  
  v = readRawValue();
  v = v * (5600 + 22000);
  v = v / 1024; // ADC resolution
  v = v * 1000; // Vref [mV]
  v = v / 5600; // R1 [ohm]
  v = v / 9; // mV per kPa
  
  return v; // truncate unsigned long to int, sensor max kPa value is 500, so v should be in int range
  
  //TODO: make adc resolution, vref and voltage devider configurable
  //TODO: optimise values to get better resolution (may reduce resolution of voltage divider in favor of others?)
}

