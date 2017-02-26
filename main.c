#include<stdio.h>

int idstate(char a[],int i){
  if(a[i]=='\0'){
    return 0;
  }
  else if(a[i]=='#'){
    while(a[i]!='\0'){
      if(a[i]==','){
        if(a[i+1]=='#')
          return 4;
        else if(a[i+1]=='R')
          return 7;
      }
      i++;
    }
    return 1;
  }
  else if(a[i]=='R'){
    while(a[i]!='\0'){
      if(a[i]==','){
        if(a[i+1]=='R')
          return 6;
      }
      i++;
    }
    return 3;
  }
  else if(a[i]=='@'){
    while(a[i]!='\0'){
      if(a[i]==','){
        if(a[i+1]=='@')
          return 5;
      }
      i++;
    }
    return 2;
  }
  else{
    return -1;
  }
}

void otob(char a[]){
  int n,i=0;
  while(a[i]!=' '){
    i++;
  }
  i++;
  n = idstate(a,i);
  i--;
  a[i]=',';
  i++;
  a[i]='0'+n;
  i++;
  a[i]='-';
  i++;
  a[i]='\0';
  printf("%s\n",a);
  FILE *fp;
  fp = fopen("mnemonics.txt","r");
  printf("%d\n",n);
}

void main(){
  char a[15] = "MOVE #55,R2";
  otob(a);
}
