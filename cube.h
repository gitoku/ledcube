#ifndef cube_h
#define cube_h

#if defined(ARDUINO) && ARDUINO >= 100
  #include "Arduino.h"
#else
  #include "WProgram.h"
#endif

#define LINE (-1)

class Cube{
	public:
		boolean matrix[8][8][8];
		Cube();
		void clearAll();
		void set(int x,int y,int z);
		void set(int x,int y,int z,boolean value);
		void clr(int x,int y,int z);
		boolean get(int x,int y,int z);
		void arrayImport(boolean mat[8][8][8]);
		void arrayExport(boolean mat[8][8][8]);
		Cube& operator=(Cube& c);
		void line(int x,int y,int z,boolean data);
};

Cube::Cube(){
	clearAll();
}

void Cube::clearAll(){
	for(int x=0;x<8;x++){
		for(int y=0;y<8;y++){
			for(int z=0;z<8;z++) matrix[x][y][z] = 0;
		}
	}
}

void Cube::set(int x,int y,int z,boolean value){
  matrix[x][y][z]= value;
}

void Cube::set(int x,int y,int z){
  matrix[x][y][z]= HIGH;
}

void Cube::clr(int x,int y,int z){
  matrix[x][y][z]= LOW;
}

boolean Cube::get(int x,int y,int z){
  return matrix[x][y][z];
}

void Cube::arrayImport(boolean mat[8][8][8]){
	for(int x=0;x<8;x++){
		for(int y=0;y<8;y++){
			for(int z=0;z<8;z++) matrix[x][y][z] = mat[x][y][z];
		}
	}
}

void Cube::arrayExport(boolean mat[8][8][8]){
	for(int x=0;x<8;x++){
		for(int y=0;y<8;y++){
			for(int z=0;z<8;z++) mat[x][y][z] = matrix[x][y][z];
		}
	}
}


Cube& Cube::operator = (Cube& c){
	arrayImport(c.matrix);
}

void Cube::line(int x,int y,int z,boolean data){
	if(x==LINE) for(int x=0;x<8;x++) matrix[x][y][z] = data;
	else if(y==LINE) for(int y=0;y<8;y++) matrix[x][y][z] = data;
	else  for(int z=0;z<8;z++) matrix[x][y][z] = data;
}


#endif