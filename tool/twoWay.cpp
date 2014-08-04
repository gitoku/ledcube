#if defined(ARDUINO) && ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif

#include "pins_arduino.h"
#include "twoWay.h"

#define THRESHOLD_HIGH 765
#define THRESHOLD_LOW 255


twoWay::twoWay(){
  enable = 0;
}

void twoWay::attach(byte _digitalPin, byte _analogPin){
  digitalPin =  _digitalPin;
  analogPin = _analogPin;  
  pinMode(digitalPin,OUTPUT);
  digitalWrite(digitalPin,LOW); 
  output = LOW; 
  enable = 1;
}

void twoWay::detach(){
  pinMode(digitalPin,INPUT);
  digitalWrite(digitalPin,LOW);
  enable = 0;
}


void twoWay::write(byte _data){
  if(enable){
     digitalWrite(digitalPin,_data); 
     output = _data; 
  }
}


byte twoWay::read(){
  int val = analogRead(analogPin);
  if(output == HIGH){
    if(val >= THRESHOLD_HIGH) return(HIGH);
    else return(LOW);
  }
  else {
    if(val >= THRESHOLD_LOW) return(HIGH);
    else return(LOW);
  }
}

#undef THRESHOLD_HIGH
#undef THRESHOLD_LOW
