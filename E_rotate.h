#include "font.h"

class Rotate{
  private:
    byte *bitmap;
    char step;
    byte image[8];
    void flow();
    void flowToLeft();
    void flowToRight();
  public:
    void set(byte _bitmap[]);
    void setText(char text);
    int print(int down);
};

Rotate rotate;

PROGMEM prog_uchar celldata[40][3] = {
 {0,0,0},
 {1,0,0},
 {2,0,0},
 {3,0,0},
 {4,0,0},
 {5,0,0},
 {6,0,0},
 {7,0,0},
 {8,0,0},
 {9,0,0},
 {10,0,0},
 {9,1,0},
 {8,1,0},
 {7,1,0},
 {6,1,0},
 {5,1,0},
 {4,1,0},
 {3,1,0},
 {2,1,0},
 {1,1,0},
 {0,1,0},
 {1,1,1},
 {2,1,1},
 {3,1,1},
 {4,1,1},
 {5,1,1},
 {6,1,1},
 {7,1,1},
 {8,1,1},
 {9,1,1},
 {10,0,1},
 {9,0,1},
 {8,0,1},
 {7,0,1},
 {6,0,1},
 {5,0,1},
 {4,0,1},
 {3,0,1},
 {2,0,1},
 {1,0,1}
};

PROGMEM prog_uchar layoutData[11][16][3]={
{{0,3,0},{1,3,1},{2,3,2},{3,3,3},{4,3,4},{5,3,5},{6,3,6},{7,3,7},{0,4,0},{1,4,1},{2,4,2},{3,4,3},{4,4,4},{5,4,5},{6,4,6},{7,4,7}},
{{2,4,2},{3,4,3},{4,4,4},{5,4,5},{6,4,6},{7,4,7},{0,3,0},{1,3,1},{2,3,2},{3,3,3},{4,3,4},{5,3,5},{0,0,0},{0,0,0},{0,0,0},{0,0,0}},
{{0,4,0},{0,5,0},{1,4,1},{1,5,1},{2,4,2},{3,3,3},{3,4,3},{4,3,4},{4,4,4},{5,3,5},{6,2,6},{6,3,6},{7,2,7},{7,3,7},{0,0,0},{0,0,0}},
{{0,6,0},{0,5,0},{1,5,1},{1,4,1},{2,5,2},{2,4,2},{3,4,3},{3,3,3},{4,4,4},{4,3,4},{5,3,5},{5,2,5},{6,3,6},{6,2,6},{7,1,7},{7,2,7}},
{{0,6,0},{0,7,0},{1,5,1},{1,6,1},{2,4,2},{2,5,2},{3,4,3},{4,3,4},{5,2,5},{5,3,5},{6,1,6},{6,2,6},{7,0,7},{7,1,7},{0,0,0},{0,0,0}},
{{0,7,0},{1,6,1},{2,5,2},{3,4,3},{4,3,4},{5,2,5},{6,1,6},{7,0,7},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0}},
{{0,7,0},{1,7,0},{1,6,1},{2,6,1},{2,5,2},{3,5,2},{3,4,3},{4,3,4},{4,2,5},{5,2,5},{5,1,6},{6,1,6},{6,0,7},{7,0,7},{0,0,0},{0,0,0}},
{{1,7,0},{2,7,0},{2,6,1},{2,5,2},{3,6,1},{3,5,2},{3,4,3},{3,3,4},{4,4,3},{4,3,4},{4,2,5},{4,1,6},{5,2,5},{5,1,6},{5,0,7},{6,0,7}},
{{2,7,0},{2,6,1},{3,7,0},{3,6,1},{3,5,2},{3,4,3},{3,3,4},{4,4,3},{4,3,4},{4,2,5},{4,1,6},{4,0,7},{5,1,6},{5,0,7},{0,0,0},{0,0,0}},
{{3,7,0},{3,6,1},{3,5,2},{3,4,3},{3,3,4},{3,2,5},{4,5,2},{4,4,3},{4,3,4},{4,2,5},{4,1,6},{4,0,7},{0,0,0},{0,0,0},{0,0,0},{0,0,0}},
{{3,7,0},{3,6,1},{3,5,2},{3,4,3},{3,3,4},{3,2,5},{3,1,6},{3,0,7},{4,7,0},{4,6,1},{4,5,2},{4,4,3},{4,3,4},{4,2,5},{4,1,6},{4,0,7}}
};

byte cellnum[11] = {16,12,14,16,14,8,14,16,14,12,16};

void Rotate::set(byte _bitmap[]){
  bitmap = _bitmap;
}

void Rotate::setText(char text){
  charToBitmap(text,image);
  bitmap = image;
}

    
int Rotate::print(int down=0){
  step++;
  if(step>39) step=0;
  else if(step<0) step=39;
  
  byte cellMax,quad,layout;
  layout = pgm_read_byte(&celldata[step][0]);  //0~40 => 0~10
  cellMax = cellnum[layout];  //cellMax
  quad = (pgm_read_byte(&celldata[step][1])*2) + pgm_read_byte(&celldata[step][2]);  //Quadrant 0~3
  
  noInterrupts();
  clearMatrix();
  if( quad==3 ){
    for(int n=0; n<8; n++){
      for(int cell=0; cell<cellMax; cell++){ 
        matrix[ 7-pgm_read_byte(&layoutData[layout][cell][0]) ][ 7-pgm_read_byte(&layoutData[layout][cell][1]) ][n] = bitRead(bitmap[n],pgm_read_byte(&layoutData[layout][cell][2]));
      }
    }
  }
  else if( quad==2 ){
    for(int n=0; n<8; n++){
      for(int cell=0; cell<cellMax; cell++){ 
        matrix[ 7-pgm_read_byte(&layoutData[layout][cell][0]) ][ pgm_read_byte(&layoutData[layout][cell][1]) ][n] = bitRead(bitmap[n],pgm_read_byte(&layoutData[layout][cell][2]));
      }
    }
  }
  else if( quad==1 ){
    for(int n=0; n<8; n++){
      for(int cell=0; cell<cellMax; cell++){ 
        matrix[ pgm_read_byte(&layoutData[layout][cell][0]) ][ 7-pgm_read_byte(&layoutData[layout][cell][1]) ][n] = bitRead(bitmap[n],pgm_read_byte(&layoutData[layout][cell][2]));
      }
    }
  }
  else {
    for(int n=0; n<8; n++){
      for(int cell=0; cell<cellMax; cell++){ 
        matrix[ pgm_read_byte(&layoutData[layout][cell][0]) ][ pgm_read_byte(&layoutData[layout][cell][1]) ][n] = bitRead(bitmap[n],pgm_read_byte(&layoutData[layout][cell][2]));
      }
    }
  }
  
  Serial.println(down);
  if(down>0) for(int j=0; j<down; j++) flowToLeft();
  else  for(int j=0; j<(-down); j++) flowToRight();
  
  interrupts();
  return 0;
}

void  Rotate::flow(){
  for(int i=0; i<8; i++){
    for(int j=0; j<8; j++){
      for(int k=6; k>=0; k--){
        matrix[i][j][k+1] = matrix[i][j][k];
      }
    }
  }
}
void  Rotate::flowToRight(){
  for(int i=0; i<8; i++){
    for(int j=0; j<8; j++){
      matrix[0][i][j] = 0;
      for(int k=6; k>=0; k--){
        matrix[k+1][i][j] = matrix[k][i][j];
      }
    }
  }
}
void  Rotate::flowToLeft(){
  for(int i=0; i<8; i++){
    for(int j=0; j<8; j++){
      matrix[7][i][j] = 0;
      for(int k=0; k<7; k++){
        matrix[k][i][j] = matrix[k+1][i][j];
      }
    }
  }
}
