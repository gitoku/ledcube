#ifndef font_h
#define font_h

PROGMEM prog_uchar fontAddress[] = {
  'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z',
  '1','2','3','4','5','6','7','8','9','0',
  '!','?',0x2c,0x2e,0x20,'_',  //「,」  「.」  「 」   
  '>','<','-','@',201
};

PROGMEM prog_uchar fontData[][8] = {
  {  /*  A  */
    0b00000000,  
    0b00011000,  
    0b00100100,  
    0b01000010,  
    0b01111110,
    0b01000010,
    0b01000010,
    0b01000010
  },
  {  /*  b  */
    0b00000000,
    0b01111000,
    0b01000100,
    0b01000100,
    0b01111100,
    0b01000010,
    0b01000010,
    0b01111100
  },
  {  /*  c  */
    0b00000000,
    0b00111100,
    0b01100010,
    0b01000000,
    0b01000000,
    0b01000000,
    0b01100010,
    0b00111100
  },
  {  /*  d  */
    0b00000000,
    0b01111000,
    0b01000100,
    0b01000010,
    0b01000010,
    0b01000010,
    0b01000100,
    0b01111000
  },
  {  /*  e  */
    0b00000000,
    0b01111110,
    0b01000000,
    0b01000000,
    0b01111110,
    0b01000000,
    0b01000000,
    0b01111110
  },
  {  /*  f  */
    0b00000000,
    0b01111110,
    0b01000000,
    0b01000000,
    0b01111110,
    0b01000000,
    0b01000000,
    0b01000000
  },
  {  /*  g  */
    0b00000000,
    0b00111100,
    0b01100010,
    0b01000000,
    0b01000000,
    0b01000110,
    0b01100010,
    0b00111110
  },
  {  /*  h  */
    0b00000000,
    0b01000010,
    0b01000010,
    0b01000010,
    0b01111110,
    0b01000010,
    0b01000010,
    0b01000010
  },
  {  /*  i  */
    0b00000000,
    0b00111000,
    0b00010000,
    0b00010000,
    0b00010000,
    0b00010000,
    0b00010000,
    0b00111000
  },
  {  /*  j  */
    0b00000000,
    0b00001110,
    0b00000100,
    0b00000100,
    0b00000100,
    0b01000100,
    0b01000100,
    0b00111000
  },
  {  /*  k  */
    0b00000000,
    0b01000100,
    0b01001000,
    0b01010000,
    0b01100000,
    0b01010000,
    0b01001000,
    0b01000100
  },
  {  /*  l  */
    0b00000000,
    0b01000000,
    0b01000000,
    0b01000000,
    0b01000000,
    0b01000000,
    0b01000000,
    0b01111110
  },
  {  /*  m  */
    0b00000000,
    0b01000001,
    0b01100011,
    0b01010101,
    0b01001001,
    0b01000001,
    0b01000001,
    0b01000001
  },
  {  /*  n  */
    0b00000000,
    0b01000001,
    0b01100001,
    0b01010001,
    0b01001001,
    0b01000101,
    0b01000011,
    0b01000001
  },
  {  /*  o  */
    0b00000000,
    0b00111100,
    0b01000010,
    0b01000010,
    0b01000010,
    0b01000010,
    0b01000010,
    0b00111100
  },
  {  /*  p  */
    0b00000000,
    0b01111100,
    0b01000010,
    0b01000010,
    0b01111100,
    0b01000000,
    0b01000000,
    0b01000000
  },
  {  /*  q  */
    0b00000000,
    0b00111000,
    0b01000100,
    0b01000100,
    0b01000100,
    0b01010100,
    0b01001100,
    0b00111010
  },
  {  /*  r  */
    0b00000000,
    0b01111000,
    0b01000100,
    0b01000100,
    0b01111000,
    0b01001000,
    0b01000100,
    0b01000010
  },
  {  /*  s  */
    0b00000000,
    0b00111100,
    0b01000010,
    0b01000000,
    0b00111100,
    0b00000010,
    0b01000010,
    0b00111100
  },
  {  /*  t  */
    0b00000000,
    0b01111111,
    0b00001000,
    0b00001000,
    0b00001000,
    0b00001000,
    0b00001000,
    0b00001000
  },
  {  /*  u  */
    0b00000000,
    0b01000010,
    0b01000010,
    0b01000010,
    0b01000010,
    0b01000010,
    0b01000010,
    0b00111100
  },
  {  /*  v  */
    0b00000000,
    0b10000010,
    0b10000010,
    0b11000110,
    0b01000100,
    0b01101100,
    0b00111000,
    0b00010000
  },
  {  /*  w  */
    0b00000000,
    0b01001001,
    0b01010101,
    0b01010101,
    0b01010101,
    0b01100011,
    0b00100010,
    0b00100010
  },
  {  /*  x  */
    0b00000000,
    0b01000001,
    0b00100010,
    0b00010100,
    0b00001000,
    0b00010100,
    0b00100010,
    0b01000001
  },
  {  /*  y  */
    0b00000000,
    0b01000001,
    0b00100010,
    0b00010100,
    0b00001000,
    0b00001000,
    0b00001000,
    0b00001000
  },
  {  /*  z  */
    0b00000000,
    0b01111111,
    0b00000010,
    0b00000100,
    0b00001000,
    0b00010000,
    0b00100000,
    0b01111111
  },
  {  /*  1  */
    0b00000000,
    0b00010000,
    0b00110000,
    0b01010000,
    0b00010000,
    0b00010000,
    0b00010000,
    0b01111100
  },
  {  /*  2  */
    0b00000000,
    0b00111000,
    0b01000100,
    0b00000100,
    0b00001000,
    0b00010000,
    0b00100000,
    0b01111100
  },
  {  /*  3  */
    0b00000000,
    0b01111000,
    0b00000100,
    0b00000100,
    0b01111000,
    0b00000100,
    0b00000100,
    0b01111000
  },
  {  /*  4  */
    0b00000000,
    0b00001000,
    0b00011000,
    0b00101000,
    0b01001000,
    0b01111111,
    0b00001000,
    0b00001000
  },
  {  /*  5  */
    0b00000000,
    0b01111100,
    0b01000000,
    0b01000000,
    0b01111000,
    0b00000100,
    0b00000100,
    0b01111000
  },
  {  /*  6  */
    0b00000000,
    0b00111000,
    0b01000000,
    0b01000000,
    0b01000000,
    0b01111000,
    0b01111000,
    0b00111000
  },
  {  /*  7  */
    0b00000000,
    0b01111100,
    0b01000100,
    0b01000100,
    0b00000100,
    0b00001000,
    0b00001000,
    0b00001000
  },
  {  /*  8  */
    0b00000000,
    0b00111000,
    0b01000100,
    0b01000100,
    0b00111000,
    0b01000100,
    0b01000100,
    0b00111000
  },
  {  /*  9  */
    0b00000000,
    0b00111000,
    0b01000100,
    0b01000100,
    0b00111100,
    0b00000100,
    0b00000100,
    0b00111000
  },
  {  /*  0  */
    0b00000000,
    0b00111000,
    0b01000100,
    0b01100100,
    0b01010100,
    0b01001100,
    0b01000100,
    0b00111000
  },
  {  /*  !  */
    0b00000000,
    0b00010000,
    0b00010000,
    0b00010000,
    0b00010000,
    0b00010000,
    0b00000000,
    0b00010000
  },
  {  /*  ?  */
    0b00000000,
    0b00111000,
    0b01000100,
    0b00001000,
    0b00010000,
    0b00010000,
    0b00000000,
    0b00010000
  },
  {  /*  ,  */
    0b00000000,
    0b00000000,
    0b00000000,
    0b00000000,
    0b00000000,
    0b00110000,
    0b00100000,
    0b01000000
  },
  {  /*  .  */
    0b00000000,
    0b00000000,
    0b00000000,
    0b00000000,
    0b00000000,
    0b00000000,
    0b01100000,
    0b01100000
  },
  {  /*     */
    0b00000000,
    0b00000000,
    0b00000000,
    0b00000000,
    0b00000000,
    0b00000000,
    0b00000000,
    0b00000000
  },
  {  /*  _  */
    0b00000000,
    0b00000000,
    0b00000000,
    0b00000000,
    0b00000000,
    0b00000000,
    0b00000000,
    0b01111110
  },
  {  /*  >  */
    0b01000000,
    0b00100000,
    0b00010000,
    0b00001000,
    0b00010000,
    0b00100000,
    0b01000000,
    0b00000000
  },
  {  /*  <  */
    0b00000000,
    0b00001000,
    0b00010000,
    0b00100000,
    0b01000000,
    0b00100000,
    0b00010000,
    0b00001000
  },
  {  /*  -  */
    0b00000000,
    0b00000000,
    0b00000000,
    0b00000000,
    0b00111100,
    0b00000000,
    0b00000000,
    0b00000000
  },
  {  /*  ■  */
    0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF
  },
  { /* 北 */
    0b00000000,
    0b00101000,
    0b00101111,
    0b11101000,
    0b00101010,
    0b00101110,
    0b01110000,
    0b00000000
  }

};


void charToBitmap(char moji,byte bitmap[]){

  int address,addressMax;
  addressMax = sizeof(fontAddress)/sizeof(fontAddress[0]);
  address = addressMax+1;
  for(int i=0; i<addressMax; i++){
    if((char)pgm_read_byte(&fontAddress[i]) == moji){  
      address = i;  
      break;
    }
  }
  if(address>addressMax) ; //error
  for(byte i=0; i<8; i++) bitmap[i] = pgm_read_byte(&fontData[address][i]);
}


#endif
