#ifndef twoWay_h
#define twoWay_h

#if defined(ARDUINO) && ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif


class twoWay {
public:
  twoWay();
  void attach(byte _digitalPin, byte _analogPin);
  void detach();
  void write(byte _data);
  byte read();
  
private:
  byte digitalPin;
  byte analogPin;
  boolean enable;
  byte output;
};


#endif
