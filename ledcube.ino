#include "ledcube.h"

void setup(){
	LEDCUBE::begin();
}

void loop(){
	//どちらも同じ動作
	//blink1();	//アドレス指定で個別にon/offする場合
	//blink2();	//まとめて更新する場合
	blink3();
}


//アドレス指定で個別にon/offする場合
void blink1(){
	//1つだけ点滅
	LEDCUBE::set(0,0,0);
	delay(500);
	LEDCUBE::clr(0,0,0);
	delay(500);
}


//[推奨]まとめて更新する場合(Cubeオブジェクトを使用)
void blink2(){
	Cube cube;

	//1つだけ点滅
	cube.set(0,0,0);
	LEDCUBE::update(cube);	//on
	delay(500);
	cube.clr(0,0,0);
	LEDCUBE::update(cube);	//off
	delay(500);
}



void blink3(){
	Cube cube;

	for(int i=0;i<8;i++){
		LEDCUBE::pull(cube);
		cube.line(LINE,i,i,1);
		LEDCUBE::update(cube);
		delay(50);
	}

	for(int i=0;i<8;i++){
		LEDCUBE::pull(cube);
		cube.line(LINE,i,i,0);
		LEDCUBE::update(cube);
		delay(50);
	}

	for(int i=0;i<8;i++){
		LEDCUBE::pull(cube);
		cube.line(i,LINE,i,1);
		LEDCUBE::update(cube);
		delay(50);
	}

	for(int i=0;i<8;i++){
		LEDCUBE::pull(cube);
		cube.line(i,LINE,i,0);
		LEDCUBE::update(cube);
		delay(50);
	}

	for(int i=0;i<8;i++){
		LEDCUBE::pull(cube);
		cube.line(i,i,LINE,1);
		LEDCUBE::update(cube);
		delay(50);
	}

	for(int i=0;i<8;i++){
		LEDCUBE::pull(cube);
		cube.line(i,i,LINE,0);
		LEDCUBE::update(cube);
		delay(50);
	}


}