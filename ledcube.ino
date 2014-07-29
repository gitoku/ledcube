#include <MsTimer2.h>
#include <avr/pgmspace.h>
#include "ledcube.h"
// #include "E_rotate.h"
// #include "E_text.h"
// #include "effect_molecule.h"
// #include "effect_bubble.h"
// #include "effect_rain.h"
// #include "effect_wave.h"

boolean matrix[8][8][8];

// TextOut text;
// Molecule bin;
// Bubble bub;
// Rain rain;
// Wave wave;

void setup(){
  ledcube_init();
  Serial.begin(9600);

  //bin.initialize(2);
  //bub.initialize(20,20);
  //rain.initialize(20);
  //wave.initialize(0.3,4);
  //text.set("BRIDE_JAPAN");

  // rotate.setText('B');
}


void loop(){
  //wave.print();
  // rotate.print();
  delay(100);
  //while( (text.print() != -1) )  delay(90);
}


