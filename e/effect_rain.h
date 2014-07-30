class Rain{
  private:
    boolean ledMatrix[8][8][8];
    int hindoSet;
  
  public:
    void initialize(int hindo){
      hindoSet = hindo;
      for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
          for(int k=0;k<8;k++){
            ledMatrix[i][j][k] = 0;
          }
        }
      }
    }
    void hindoChange(int hindo){
      hindoSet = hindo;
    }
    
    void print(){
      for(int i=0; i<8; i++){
        for(int j=0; j<8; j++){
          for(int k=6; k>=0; k--){
            ledMatrix[i][j][k+1] = ledMatrix[i][j][k];
          }
        }
      }
      for(int i=0; i<8; i++){
        for(int j=0; j<8; j++){
          if(random(hindoSet) == 1){
            ledMatrix[i][j][0] = 1;
          }else{
            ledMatrix[i][j][0] = 0;
          }
        }
      }
      noInterrupts();
      for(int i=0; i<8; i++){
        for(int j=0; j<8; j++){
          for(int k=0; k<8; k++){
            matrix[i][j][k] = ledMatrix[i][j][k];
          }
        }
      }
      interrupts();
    }
};

