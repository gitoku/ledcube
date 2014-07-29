#include "ledcube.h"

void setup(){
	LEDCUBE::begin();
}

void loop(){
	blink1();
	//blink2();
}


//アドレス指定で個別にon/offする場合
void blink1(){
	//1つだけ点滅
	LEDCUBE::on(0,0,0);
	delay(500);
	LEDCUBE::off(0,0,0);
	delay(500);
}


//まとめて更新する場合
void blink2(){
	boolean m[8][8][8];	//必ずboolean型の8*8*8多次元配列を用いる

	//リセット
	for(int x=0;x<8;x++){
		for(int y=0;y<8;y++){
			for(int z=0;z<8;z++) m[x][y][z] = 0;
		}
	}

	//1つだけ点滅
	m[0][0][0]=1;
	LEDCUBE::cube(m);	//on
	delay(500);
	m[0][0][0]=0;
	LEDCUBE::cube(m);	//off
	delay(500);
}