#ifndef ledcube_h
#define ledcube_h

#include "fastShiftOut.h"

#define STR_PIN 10

#define STAGE_ACTIVE LOW
#define STAGE_DISACTIVE HIGH


class LEDCUBE {
public:
  void begin();
  void clear();  //matrixをすべてLOW
  void cube(boolean* mat);
  void cube(int i,int j,int k,boolean value);

private:
  void drawingStage();
  fastShiftOut ledcube;
  boolean buffer[72];
  boolean* matrix;
};




void LEDCUBE::begin(){
  ledcube.begin(STR_PIN);
  ledcube.dataLink(buffer,72);  //(8+1)*8bit

  clear();
  for(byte i=0; i<8; i++) {
    drawingStage();
    delay(1);
  }
  Serial.begin(9600);

  MsTimer2::set(1,drawingStage);
  MsTimer2::start();
}


void LEDCUBE::drawingStage(){
  static byte stage = 0;

  //発光させる段の選択(一段だけアクティブに)[64~71]
  for(byte i=64; i<72; i++)  buffer[i] = STAGE_DISACTIVE;
  buffer[64+stage] = STAGE_ACTIVE;

  //選択した段の発光箇所データ反映[0~63]
  for(byte i=0; i<8; i++){
    for(byte j=0; j<8; j++){
       buffer[(i*8) + j] = *(matrix + (i*64 + j*8 + stage));
    }
  }

  //データ送信
  ledcube.send();

  //次回の発光段の指定
  stage = (++stage) % 8;
}


//matrixをすべてLOW
void LEDCUBE::clear(){
  for(int i=0; i<256; i++) *(matrix + i) = 0;
}

void LEDCUBE::cube(boolean* mat){
  matrix = mat;
}

void LEDCUBE::cube(int i,int j,int k,boolean value){
  *(matrix + (i*64 + j*8 + k) ) = value;
}

#undef STR_PIN

#endif
