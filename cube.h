#ifndef cube_h
#define cube_h

class Cube{
	public:
		boolean matrix[8][8][8];
		Cube();
		void clearAll();
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

#endif