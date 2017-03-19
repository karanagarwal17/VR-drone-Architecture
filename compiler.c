#include<stdio.h>
#include"compiler.h"

int binarytodecimal(){
  return 0;
}

void decode(char *a){
  char b1[4],b2[6],b3[6];
  int i,x1,x2,x3;
  for(i=0;i<4;i++){
    b1[i]=a[i];
  }
  for(i=0;i<6;i++){
    b2[i]=a[i+4];
  }
  for(i=0;i<6;i++){
    b3[i]=a[i+10];
  }
  x1 = binarytodecimal(b1);
  x2 = binarytodecimal(b2);
  x3 = binarytodecimal(b3);
  if(x1 == 15){
    if(x2 == 63){
      switch(x3){
        case 0: TAKE();break;
        case 1: LAND();break;
        case 2: ILU();break;
        case 3: SPK();break;
        case 4: BINF();break;
      }
    }
    else{
      switch(x2){
        case 0: PRO(x3,1);break;
        case 1: PRO(x3,2);break;
        case 2: PRO(x3,3);break;
        case 3: SPD(x3,1);break;
        case 4: SPD(x3,2);break;
        case 5: SPD(x3,3);break;
        case 6: GES(x3,1);break;
        case 7: GES(x3,2);break;
        case 8: GES(x3,3);break;
        case 9: REST(x3,1);break;
        case 10: REST(x3,2);break;
        case 11: REST(x3,3);break;
      }
    }
  }
  else{
    switch(x1){
      case 0: MOV(x2,x3,4);break;
      case 1: MOV(x2,x3,5);break;
      case 2: MOV(x2,x3,6);break;
      case 3: OBS(x2,x3,4);break;
      case 4: OBS(x2,x3,5);break;
      case 5: OBS(x2,x3,6);break;
      case 6: FP(x2,x3,4);break;
      case 7: FP(x2,x3,5);break;
      case 8: FP(x2,x3,6);break;
      case 9: MVR(x2,x3,7);break;
      case 10: STR(x2,x3,4);break;
      case 11: STR(x2,x3,7);break;
      case 12: LDB(x2,x3,6);break;
      case 13: LDB(x2,x3,7);break;
    }
  }
}

void main(){
  int n;
  FILE *file;
  char str[30];
  file = fopen("binary.txt","r");
  //reading the instructions file and getting the instructions one by one
  while(fgets(str,30,file)!=NULL){
    n = strlen(str);
    str[n-1]='\0';
    decode(str);
  }
  fclose(file);
}
