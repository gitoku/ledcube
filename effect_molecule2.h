/*********************************************
気体粒子のような振る舞いをします。（たぶん）
*********************************************/
#define MOLMAX 10

class Molecule2{
  private:
    long frame;
    int number;
    int particle[MOLMAX][7];
    int particlePosition[MOLMAX][3];
    
    void molSet(int oldNum,int newNum){
      for(int i=0; i<MOLMAX; i++){
        particle[i][6] = 0;//ステータス：停止
      }
      for(int i=0;i<oldNum;i++){
        particle[i][6] = 1;//ステータス：ワンショット
      }
      
      for(int i = 0; i < newNum; i++){
        if(i == -1){
          ;
        }else{
          particle[i][0] = random(50,751);//x軸
          particle[i][1] = random(50,751);//y軸
          particle[i][2] = random(50,751);//z軸
          if(random(2) == 1){
            particle[i][random(3)] = 50;
          }else{
            particle[i][random(3)] = 750;
          }
          particle[i][3] = random(10,100);//x軸速度
          particle[i][4] = random(10,100);//y軸速度
          particle[i][5] = random(10,100);//z軸速度
          if(random(2)==1){particle[i][3] *= -1;}
          if(random(2)==1){particle[i][4] *= -1;}
          if(random(2)==1){particle[i][5] *= -1;}
          particle[i][6] = 2;//ステータス：連続
        }
      }
    }
  public:
    void initialize(int n){
      number = n;
      
      for(int i=0;i<MOLMAX;i++){
        /*
        for(int j=0;j<7;j++){
          particle[i][j] = 0;
        }
        */
        for(int j=0;j<3;j++){
          particlePosition[i][j] = 0;
        }
      }
      
      molSet(0,number);
      
    }
    
    void numChange(int newNum){
      molSet(number,newNum);
      number = newNum;
    }
    
    void print(){
      for(int i=0; i < MOLMAX; i++){
        if(particle[i][6] != 0){
          for(int j=0;j<3;j++){  
            particle[i][j] += particle[i][j+3];
            if(particle[i][j] > 750){
              particle[i][j] = 750 - (particle[i][j] - 750);
              if(particle[i][j+3] > 0){
                particle[i][j+3] *= -1;
              }
            }else if(particle[i][j] < 50){
              particle[i][j] = 50 + (50 - particle[i][j]);
              if(particle[i][j+3] < 0){
                particle[i][j+3] *= -1;
              }
            }
          }
        }
        
        for(int j=0;j<3;j++){
          particlePosition[i][j] = particle[i][j] / 100;
          if(particlePosition[i][j] < 0){particlePosition[i][j] = 0;}
          if(particlePosition[i][j] > 7){particlePosition[i][j] = 7;}
          /**
          if(particlePosition[i][j] == 7 || particlePosition[i][j] == 0){
            if(particle[i][6] == 1){particle[i][6] = 0;}
          }
          /**/
        }
        /**/
        if(particlePosition[i][2] == 7 && particle[i][6] == 1){
          particle[i][6] = 0;
        }
        if(particlePosition[i][2] == 0 && particle[i][6] == 1){
          particle[i][6] = 0;
        }
        /**/
        
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
      for(int i=0; i < MOLMAX; i++){ 
        if(particle[i][6] != 0){
          x = particlePosition[i][0];
          y = particlePosition[i][1];
          z = particlePosition[i][2];
          matrix[x][y][z] = 1;
        }
      }
      interrupts();
      
    }
};
