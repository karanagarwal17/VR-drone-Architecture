#include<string.h>

char output[40];
int current_x;
int current_y;
int battery;
int light;

LAND(){
  strcpy("The drone has landed.",output);
  current_x = 0;
  current_y = 0;
  speaker = 0;
  light = 0;
  battery -= 1;
}

ILU(){
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

SPK(){
  if(speaker == 1){
    strcpy("The speaker has been turned off",output);
    speaker = 0;
  }
  else{
    strcpy("The speaker has been turned on",output);
    speaer = 1;
  }
  battery -= 1;
}

LDB(int x2, int x3, int s){
  
}

STR(int x2, int x3, int s){

}
