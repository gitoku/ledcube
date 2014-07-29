#ifndef fastShiftOut_h
#define fastShiftOut_h

#if defined(ARDUINO) && ARDUINO >= 100
  #include "Arduino.h"
#else
  #include "WProgram.h"
#endif

#include "pins_arduino.h"
#include "fastShiftOut.h"

#define DATA_PIN 11
#define CLK_PIN 13

class fastShiftOut {
public:
  void begin(byte _rachPin);
  void send();
  void dataLink(boolean *_buffer, byte _dataBit);
  
private:
  volatile byte *rachPort;
  byte rachBit;
  boolean* buffer;
  byte dataSize;
};  //4bytes


//begin "fastShiftOut" and register rach pin number
void fastShiftOut::begin(byte _rachPin){
  pinMode( DATA_PIN, OUTPUT);
  pinMode( CLK_PIN, OUTPUT);
  pinMode( _rachPin, OUTPUT);
  
  rachBit = digitalPinToBitMask( _rachPin );
  rachPort = portOutputRegister(digitalPinToPort( _rachPin ));
   
  //SPI clock => fOSC/4 =4[MHz]
  SPCR = 0b01010000;
  SPSR = 0b00000001;
}

//link variable data to be sent and define data size(bit)
void fastShiftOut::dataLink(boolean *_buffer, byte _dataBit){
  buffer = _buffer;
  dataSize =  _dataBit/8;
}

//send data by SPI
void fastShiftOut::send(){
  byte data;
  unsigned int cnt = 0;
  
  for(byte i=0; i<dataSize; i++){
    data=0;
    for(byte j=0; j<8; j++){  //data copy[data<=buffer] by 8bit
      if( buffer[cnt] ) bitSet(data,j);
      cnt++;
    }
    SPDR = data;  //data(8bit) send 
    while(!(SPSR & (1<<SPIF))); 
  }
  
  //toggle rach pin 2 times
  *rachPort |= rachBit;
  *rachPort &= ~rachBit;
}  //4bytes

/* 8bytes */

#undef DATA_PIN
#undef CLK_PIN

#endif
