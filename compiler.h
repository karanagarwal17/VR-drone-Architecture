#include<string.h>
#include<unistd.h>

char output[40];
int current_x = 0;
int current_y = 0;
int battery = 100;
int light = 0;
int speaker = 0;
int memory[1024] = {0};
int speed = 1;
int registers[16] = {0};

void TAKE(){

}

void LAND(){
  strcpy("The drone has landed.",output);
  current_x = 0;
  current_y = 0;
  speaker = 0;
  light = 0;
  battery -= 1;
}

void ILU(){
  if(light == 1){
    strcpy("The light has been turned off",output);
    light = 0;
  }
  else{
    strcpy("The drone has been illuminated",output);
    light = 1;
  }
  battery -= 1;
}

void SPK(){
  if(speaker == 1){
    strcpy("The speaker has been turned off",output);
    speaker = 0;
  }
  else{
    strcpy("The speaker has been turned on",output);
    speaker = 1;
  }
  battery -= 1;
}

void MVR(int x2, int x3, int s){
  registers[x3] = x2;
  strcpy("The value x2 has been stored in registers x3",output);
}

void LDB(int x2, int x3, int s){
  if(s == 6){
    registers[x3] = memory[registers[x2]];
    strcpy("The value at memory location at registers x2 has been stored in registers x3",output);
  }
  if(s == 7){
    registers[x3] = memory[x2];
    strcpy("The value at memory location at registers x2 has been stored in registers x3",output);
  }
}

void STR(int x2, int x3, int s){
  if(s == 4){
    memory[x3] = x2;
    strcpy("The value x2 has been stored at memory location x3",output);
  }
  if(s == 7){
    memory[registers[x3]] = x2;
    strcpy("The value x2 has been stored at address given by registers x3",output);
  }
}

void REST(int t,int s){
  if(s == 3){
    t = registers[t];
  }
  if(s == 2){
    t = memory[t];
  }
  strcpy("Now, the drone will rest",output);
  sleep(t);
}

void SPD(int x, int s){
  if(s == 3){
    x = registers[x];
  }
  if(s == 2){
    x = memory[x];
  }
  if(speed > x){
    strcpy("The speed of the drone has beeen increamented",output);
  }
  else if(speed < x){
    strcpy("The speed of the drone has been decremented",output);
  }
  else{
    strcpy("There is no change in the speed of the drone",output);
  }
  speed = x;
  battery -= 1;
}

void BINF(){
  strcpy("The battery remaining in the drone is - ",output);
  battery -= 1;
}

void PRO(int x, int s){

}

void GES(int x, int s){

}

void MOV(int x2, int x3, int s){

}

void OBS(int x2, int x3, int s){

}

void FP(int x2, int x3, int s){

}
