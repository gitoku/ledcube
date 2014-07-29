class Bubble{
  private:
    boolean ledMatrix[8][8][8];
    int in;
    int out;
  public:
    void initialize(int inHindo,int outHindo){
      in = inHindo;
      out = outHindo;
      for(int i=0; i<8; i++){
        for(int j=0; j<8; j++){
          for(int k=0; k<7; k++){
            ledMatrix[i][j][k] = 0;
          }
        }
      }
    }
    
    void hindoChange(int inHindo,int outHindo){
      in = inHindo;
      out = outHindo;
    }
    
    void print(){
      for(int i=0; i<8; i++){
        for(int j=0; j<8; j++){
          for(int k=0; k<7; k++){
            ledMatrix[i][j][k] = ledMatrix[i][j][k+1];
          }
        }
      }
      
      for(int i=1; i<7; i++){
        for(int j=1; j<7; j++){
          if(random(in) == 1){
            ledMatrix[i][j][7] = 1;
          }else{
            ledMatrix[i][j][7] = 0;
          }
        }
      }
      noInterrupts();
      for(int i=0; i<8; i++){
        for(int j=0; j<8; j++){
          for(int k=0; k<8; k++){
            matrix[i][j][k] = 0;
          }
        }
      }
      
      int a,b,c,d,e,f;
      for(int i=0; i<8; i++){
        for(int j=0; j<8; j++){
          for(int k=0; k<8; k++){
            if(ledMatrix[i][j][k] == 1){
              if(random(out)==1 && k>0 && k<7){
                a = i + 1;
                b = i - 1;
                c = j + 1;
                d = j - 1;
                e = k + 1;
                f = k - 1;
                ledMatrix[i][j][k] = 0;
                matrix[i][j][k] = 0;
                if(a < 8){
                  matrix[a][j][k] = 1;
                }
                if(b > 0){
                  matrix[b][j][k] = 1;
                }
                if(c < 8){
                  matrix[i][c][k] = 1;
                }
                if(d > 0){
                  matrix[i][d][k] = 1;
                }
                if(e < 8){
                  matrix[i][j][e] = 1;
                }
                if(f > 0){
                  matrix[i][j][f] = 1;
                }
              }else{
                matrix[i][j][k] = 1;
              }
            }
          }
        }
      }
      interrupts();
    }
};


