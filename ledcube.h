#ifndef ledcube_h
#define ledcube_h

#include "MsTimer2.h"
#include "fastShiftOut.h"
#include "cube.h"

#define STR_PIN 10

#define STAGE_ACTIVE LOW
#define STAGE_DISACTIVE HIGH


namespace LEDCUBE {
  void begin();
  void clear();  //matrixをすべてLOW
  void update(boolean mat[8][8][8]);
  void update(Cube mat);
  void update(int x,int y,int z,boolean value);
  void set(int x,int y,int z);
  void clr(int x,int y,int z);
  void drawingStage();

  boolean buffer[72];
  boolean matrix[8][8][8];
  fastShiftOut ledcube;
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
       buffer[(i*8) + j] = matrix[i][j][stage];
    }
  }

  //データ送信
  ledcube.send();

  //次回の発光段の指定
  stage = (++stage) % 8;
}


//matrixをすべてLOW
void LEDCUBE::clear(){
  Cube c;
  update(c);
}

void LEDCUBE::update(boolean mat[8][8][8]){
  for(int x=0;x<8;x++){
    for(int y=0;y<8;y++){
      for(int z=0;z<8;z++) matrix[x][y][z] = mat[x][y][z];
    }
  }
}

void LEDCUBE::update(Cube mat){
  update(mat.matrix);
}

void LEDCUBE::update(int x,int y,int z,boolean value){
  matrix[x][y][z]= value;
}

void LEDCUBE::set(int x,int y,int z){
  matrix[x][y][z]= HIGH;
}

void LEDCUBE::clr(int x,int y,int z){
  matrix[x][y][z]= LOW;
}

#undef STR_PIN

#endif
