#include<stdio.h>
#include<string.h>

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

void binary(int decimalno)
{
    int d[20]={0};
    int i=0;
    while(decimalno>0)
    {
         d[i]=decimalno%2;
         i++;
         decimalno=decimalno/2;
    }
    for(int j=5;j>=0;j--)
    {
          printf("%d",d[j]);
    }

}

void otob(char a[]){
  int n,i=0,x;
  char t[30],b[30],c[30];
  strcpy(t,a);
  while(a[i]!=' ' && a[i]!='\0'){
    i++;
  }
  i++;
  n = idstate(a,i);
  i--;
  a[i]=',';
  i++;
  a[i]='0'+n;
  i++;
  a[i]='\0';
  printf("%s\n",a);
  FILE *fp;
  fp = fopen("MNEMONICS.txt","r");
  while(1){
    fscanf(fp,"%[^-]",c);
    fseek(fp,sizeof(char),SEEK_CUR);
    fscanf(fp,"%s\n",b);
    i=strlen(c);
    c[i]='\0';
    if(strcmp(c,a)==0){
      break;
    }
    if(feof(fp))
      break;
  }
  printf("%s\n",b);
  i=0;
  switch(n){
    case 0: break;
    case 1: {
      while(t[i]!='#'){
        i++;
      }
      i++;
      x=0;
      while(t[i]!='\0'){
        x*=10;
        x+=t[i]-'0';
        i++;
      }
      binary(x);
    }break;
    case 2: {
      while(t[i]!='@'){
        i++;
      }
      i+=2;
      x=0;
      while(t[i]!='\0'){
        x*=10;
        x+=t[i]-'0';
        i++;
      }
      binary(x);
    }break;
    case 3:{
      while(t[i]!='R'){
        i++;
      }
      i++;
      x=0;
      while(t[i]!='\0'){
        x*=10;
        x+=t[i]-'0';
        i++;
      }
      binary(x);
    }break;
    case 4: {
      while(t[i]!='#'){
        i++;
      }
      i++;
      x=0;
      while(t[i]!=','){
        x*=10;
        x+=t[i]-'0';
        i++;
      }
      binary(x);
      i+=2;
      x=0;
      while(t[i]!='\0'){
        x*=10;
        x+=t[i]-'0';
        i++;
      }
      binary(x);
    }break;
    case 5: {
      while(t[i]!='@'){
        i++;
      }
      i+=2;
      x=0;
      while(t[i]!=','){
        x*=10;
        x+=t[i]-'0';
        i++;
      }
      binary(x);
      i+=3;
      x=0;
      while(t[i]!='\0'){
        x*=10;
        x+=t[i]-'0';
        i++;
      }
      binary(x);
    }break;
    case 6: {
      while(t[i]!='R'){
        i++;
      }
      i++;
      x=0;
      while(t[i]!=','){
        x*=10;
        x+=t[i]-'0';
        i++;
      }
      binary(x);
      i+=2;
      x=0;
      while(t[i]!='\0'){
        x*=10;
        x+=t[i]-'0';
        i++;
      }
      binary(x);
    }break;
    case 7: {
      while(t[i]!='#'){
        i++;
      }
      i++;
      x=0;
      while(t[i]!=','){
        x*=10;
        x+=t[i]-'0';
        i++;
      }
      binary(x);
      i+=2;
      x=0;
      while(t[i]!='\0'){
        x*=10;
        x+=t[i]-'0';
        i++;
      }
      binary(x);
    }break;
  }
}

void main(){
  FILE*file;
 char str[20];
 file=fopen("instr.txt","r");
 while(fgets(str,20,file)!=NULL){
      otob(str);}
 fclose(file);
}
