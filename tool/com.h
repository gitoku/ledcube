#include "twoWay.h"

#define TRANS_END 99


#define DIG_La 8
#define DIG_Lb 7
#define DIG_Lc 6

#define DIG_Ra 2
#define DIG_Rb 3
#define DIG_Rc 4

#define ANA_La 0
#define ANA_Lb 1
#define ANA_Lc 2

#define ANA_Ra 5
#define ANA_Rb 4
#define ANA_Rc 3


twoWay wireDataLowR;
twoWay wireDataHighR;
twoWay wireSendR;
twoWay wireDataLowL;
twoWay wireDataHighL;
twoWay wireSendL;


void wire_init(){
  wireDataLowR.attach( DIG_Rc,   ANA_Rc  );
  wireDataHighR.attach( DIG_Rb,  ANA_Rb  );
  wireSendR.attach(       DIG_Ra,  ANA_Ra  );
  wireDataLowL.attach(  DIG_Lc,   ANA_Lc  );
  wireDataHighL.attach( DIG_Lb,   ANA_Lb  );
  wireSendL.attach(        DIG_La,   ANA_La  );
}



byte getDataR(){
  static boolean old_trans;
  boolean trans;
  byte data=0;

  trans = wireSendR.read();

  if(trans > old_trans){
    data = wireDataLowR.read() + (wireDataHighR.read() << 1);
   }
  old_trans = trans;
  /*
  if(data){
    Serial.print("<r,");
    Serial.print(data,DEC);
    Serial.print(">");
  }
  */
  return( data );
}



byte getDataL(){
  static boolean old_trans;
  boolean trans;
  byte data=0;

  trans = wireSendL.read();

  if(trans > old_trans){
    data = wireDataLowL.read() + (wireDataHighL.read() << 1);
  }
  old_trans = trans;
  /*
  if(data){
    Serial.print("<l,");
    Serial.print(data,DEC);
    Serial.print(">");
  }
  */
  return( data );
}



void sendDataR(byte data){
  static byte old_data;
  if(old_data != data){//直前と同じ内容なら不実行
    //送信終了
    if(data == TRANS_END){
      wireSendR.write(LOW);
      wireDataLowR.write(LOW);
      wireDataHighR.write(LOW);
      //Serial.println(".");
    }
    //送信開始
    else {
      wireDataLowR.write( data&B01 );
      wireDataHighR.write( (data>>1)&B01 );
      wireSendR.write(HIGH);
      /*
      Serial.print("[l,");
      Serial.print(data,DEC);
      Serial.print("]");
      */
    }
    old_data = data;
  }
}



void sendDataL(byte data){
  static byte old_data;
  if(old_data != data){//直前と同じ内容なら不実行
    //送信終了
    if(data == TRANS_END){
      wireSendL.write(LOW);
      wireDataLowL.write(LOW);
      wireDataHighL.write(LOW);
      //Serial.println(".");
    }
    //送信開始
    else {
      wireDataLowL.write( data&B01 );
      wireDataHighL.write( (data>>1)&B01 );
      wireSendL.write(HIGH);
      /*
      Serial.print("[l,");
      Serial.print(data,DEC);
      Serial.print("]");
      */
    }
    old_data = data;
  }
}

