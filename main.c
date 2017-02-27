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

void binary(FILE *f, int decimalno){
  char d[6] = "000000";
  int i = 0;
  if(decimalno <= 63){
    while(decimalno > 0){
      d[i] = decimalno%2 + '0';
      i++;
      decimalno = decimalno / 2;
    }
    fprintf(f,"%s",d);
  }
  else{
    printf("The limit for the operands is 63, which has been exceeded ");
  }
}

void mnemonicToBinary(char a[]){
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
  FILE *fp,*fop,*fb;
  fp = fopen("MNEMONICS.txt","r");
  fop = fopen("opcode.txt","a");
  fseek(fop,0,SEEK_END);
  fb = fopen("binary.txt","a");
  fprintf(fop,"%-30s",t);
  fprintf(fop,"%-30s \t",a);
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
  fprintf(fb,"%s",b);
  fprintf(fop,"%-30s\n",b);
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
      binary(fb,x);
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
      binary(fb,x);
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
      binary(fb,x);
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
      binary(fb,x);
      i+=2;
      x=0;
      while(t[i]!='\0'){
        x*=10;
        x+=t[i]-'0';
        i++;
      }
      binary(fb,x);
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
      binary(fb,x);
      i+=3;
      x=0;
      while(t[i]!='\0'){
        x*=10;
        x+=t[i]-'0';
        i++;
      }
      binary(fb,x);
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
      binary(fb,x);
      i+=2;
      x=0;
      while(t[i]!='\0'){
        x*=10;
        x+=t[i]-'0';
        i++;
      }
      binary(fb,x);
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
      binary(fb,x);
      i+=2;
      x=0;
      while(t[i]!='\0'){
        x*=10;
        x+=t[i]-'0';
        i++;
      }
      binary(fb,x);
    }break;
  }
  fprintf(fb,"\n");
  fclose(fop);
  fclose(fb);
  fclose(fp);
}

void main(){
  int n;
  FILE *file,*fop,*fb;
  char str[30];
  file = fopen("instruction.txt","r");
  fop = fopen("opcode.txt","w");
  fb = fopen("binary.txt","w");
  fclose(fop);
  fclose(fb);
  while(fgets(str,30,file)!=NULL){
    n = strlen(str);
 	  str[n-1]='\0';
    mnemonicToBinary(str);
  }
  fclose(file);
}
