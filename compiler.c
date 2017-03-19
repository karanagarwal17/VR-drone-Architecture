#include<stdio.h>


binarytodecimal(){

}

decode(char *a){
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
      case 9: STR(x2,x3,4);break;
      case 10: STR(x2,x3,7);break;
      case 11: LDB(x2,x3,6);break;
      case 12: LDB(x2,x3,7);break;
    }
  }
}

main(){

}
