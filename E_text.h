#include "font.h"
#include "effect_moji.h"

#define set(x) initialize((x),sizeof(x));

class TextOut{
  private:
    byte bitmap[8];
    byte matrixOut[8][2];
    int textSize;
    int mojiCount;
    int siftCounter;
    char *textArray;
  
  public:
    void initialize(char textIn[],int num){
      textSize = num;
      textArray = textIn;
      mojiCount = 0;
      siftCounter = 0;
      for(int i=0;i<8;i++){
        bitmap[i] = 0;
        for(int j=0;j<2;j++){
           matrixOut[i][j] = 0;
        }
      }
    }
    
    int print(){
      if(siftCounter == -8){
        initialize(textArray,textSize);
        return -1;
      }
      Serial.println(textSize,DEC);
      if(siftCounter == 0 && mojiCount < textSize - 1){
        //文字ビットマップデータ読み込み
        charToBitmap(*(textArray + mojiCount),bitmap);
        
        //文字ビットマップデータをキューへ送る
        for(int i=0;i<8;i++){
          byte a = bitmap[i];
          matrixOut[i][1] = a;
        }
        mojiCount++;
        siftCounter = 8;
      }
      
      //キューをシフト
      for(int i=0;i<8;i++){
        int a = matrixOut[i][0];
        int b = matrixOut[i][1];
        a = a << 1;
        a = a | (b >> 7);
        b = b << 1;
        matrixOut[i][0] = a;
        matrixOut[i][1] = b;
      }
      
     //matrixへ転送
     noInterrupts();
     for(int i=0;i<8;i++){
       for(int j=0;j<8;j++){
           //matrix[j][0][i] = ( matrixOut[i][1] & (0b10000000 >> j) ) >> ( 7 - j );
           byte a = matrixOut[i][0];
           a &= 0b10000000 >> j;
           if(a == 0){
             matrix[j][0][i] = 0;
             matrix[j][1][i] = 0;
             matrix[j][2][i] = 0;
             matrix[j][3][i] = 0;
             matrix[j][4][i] = 0;
             matrix[j][5][i] = 0;
             matrix[j][6][i] = 0;
             matrix[j][7][i] = 0;
           }else{
             matrix[j][0][i] = 0;
             matrix[j][1][i] = 0;
             matrix[j][2][i] = 1;
             matrix[j][3][i] = 1;
             matrix[j][4][i] = 1;
             matrix[j][5][i] = 1;
             matrix[j][6][i] = 0;
             matrix[j][7][i] = 0;
           }
         }  
       }
      siftCounter--;
      interrupts();
      return 0;
  }
};
