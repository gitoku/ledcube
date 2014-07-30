class Wave{
  private:
    float frequency;
    float amplitude;
    float rad;
  
  public:
    void initialize(float f,float a){
      frequency = f;
      amplitude = a;
      rad = 0;
    }
    
    void change(float f,float a){
      frequency = f;
      amplitude = a;
    }
    
    void print(){
      static int t = 0;
      static int amp[8] = {0};
      
      for(int i=7; i>0; i--){
        amp[i] = amp[i-1];
      }
      amp[0] = (int)( ( sin(rad) + 1 ) * amplitude);
      amp[0] = constrain(amp[0], 0, 7);
      amp[0] = 7 - amp[0];
      
      noInterrupts();
      for(int i=0; i<8; i++){
        for(int j=0; j<8; j++){
          for(int k=0; k<8; k++){
            if(amp[i] >= k){
              matrix[i][j][k] = 0;
            }else{
              matrix[i][j][k] = 1;
            }
          }
        }
      }
      interrupts();
      rad += frequency;
    }
};
