/*********************************************
気体粒子のような振る舞いをします。（たぶん）
*********************************************/
class Molecule{
  private:
    long frame;
    int number;
    int particle[10][6];
    int particlePosition[10][3];
  public:
    void initialize(int n){
      number = n;
      
      for(int i=0;i<10;i++){
        for(int j=0;j<6;j++){
          particle[i][j] = 0;
        }
        for(int j=0;j<3;j++){
          particlePosition[i][j] = 0;
        }
      }
      
      for(int i=0; i < number; i++){
        particle[i][0] = random(799);//x軸
        particle[i][1] = random(799);//y軸
        particle[i][2] = random(799);//z軸
        particle[i][3] = random(10,100);//x軸速度
        particle[i][4] = random(10,100);//y軸速度
        particle[i][5] = random(10,100);//z軸速度
        if(random(2)==1){particle[i][3] *= -1;}
        if(random(2)==1){particle[i][4] *= -1;}
        if(random(2)==1){particle[i][5] *= -1;}
      }
      
    }
    
    void print(){
      for(int i=0; i < number; i++){
        for(int j=0;j<3;j++){  
          particle[i][j] += particle[i][j+3];
          if(particle[i][j] > 750){
            particle[i][j] = 750 - (particle[i][j] - 750);
            particle[i][j+3] *= -1;
          }else if(particle[i][j] < 50){
            particle[i][j] == 50 + (50 - particle[i][j]);
            particle[i][j+3] *= -1;
          }
        }
      }
      
      for(int i=0; i < number; i++){ 
        for(int j=0;j<3;j++){
          particlePosition[i][j] = particle[i][j] / 100;
          if(particlePosition[i][j] < 0){particlePosition[i][j] = 0;}
          if(particlePosition[i][j] > 7){particlePosition[i][j] = 7;}
        }
      }
      
      
      int x; 
      int y; 
      int z;
      
      noInterrupts();
      for(int i=0; i<8; i++){
        for(int j=0; j<8; j++){
          for(int k=0; k<8; k++){
            matrix[i][j][k]=0;
          }
        }
      }
      for(int i=0; i < number; i++){ 
        x = particlePosition[i][0];
        y = particlePosition[i][1];
        z = particlePosition[i][2];
        matrix[x][y][z] = 1;
      }
      interrupts();
      
    }
};
