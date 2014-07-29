#include "MsTimer2.h"
#include <avr/pgmspace.h>
#include "ledcube.h"

boolean matrix[8][8][8];

void setup(){
	ledcube_init();
	Serial.begin(9600);
}


void loop(){
	delay(100);
}


