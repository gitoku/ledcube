#include "ledcube.h"

void setup(){
	LEDCUBE::begin();
}

void loop(){

	//どちらも同じ動作
	blink1();	//アドレス指定で個別にon/offする場合
	//blink2();	//まとめて更新する場合
	//blink3();	//まとめて更新する場合
}


//アドレス指定で個別にon/offする場合
void blink1(){
	//1つだけ点滅
	LEDCUBE::set(0,0,0);
	delay(500);
	LEDCUBE::clr(0,0,0);
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
	LEDCUBE::update(m);	//on
	delay(500);
	m[0][0][0]=0;
	LEDCUBE::update(m);	//off
	delay(500);
}


//まとめて更新する場合(Cubeオブジェクトを使用)
void blink3(){
	Cube cube;

	//1つだけ点滅
	cube.set(0,0,0);
	LEDCUBE::update(cube);	//on
	delay(500);
	cube.clr(0,0,0);
	LEDCUBE::update(cube);	//off
	delay(500);
}