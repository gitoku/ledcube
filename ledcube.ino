#include "ledcube.h"


void setup(){
	LEDCUBE::begin();
}


void loop(){
	LEDCUBE::on(0,0,0);
	delay(500);
	LEDCUBE::off(0,0,0);
	delay(500);
}


