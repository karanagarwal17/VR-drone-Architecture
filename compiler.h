#include<string.h>
#include<unistd.h>
#include<math.h>

int obstacle[5][2]={0};
int power = 0;
int current_x = 0;
int current_y = 0;
int battery = 100;
int PC=0;
int light = 0;
int MAR=0;
char MDR[17] = {0};
char IR[17] = {0};
int speaker = 0;
int memory[1024] = {0};
int speed = 1;
int registers[16] = {0};
int flag[2]={0};
FILE *out;

void output();

void TAKE(){
	fprintf(out,"TAKE() function has been called.\n\n");
	if (battery==100 && power == 0) {
		flag[0]=1;
		fprintf(out,"Drone is taking off.\n");
		battery--;
		fprintf(out,"ALU signal for subtact is generated.\n");
		output();
    power = 1;
	}
	else if(battery != 100){
		flag[1]=1;
		fprintf(out,"ALU signal for subtact is generated.\n");
		fprintf(out,"need 100%% battery for take off\n");
		output();
	}
  else{
		fprintf(out,"ALU signal for subtact is generated.\n");
    fprintf(out, "The drone is already in the air.\n");
  }
}

void LAND(){
	fprintf(out,"LAND() function has been called.\n\n");
  if(power == 1){
		flag[0]=1;
		fprintf(out,"ALU signal for subtact is generated.\n");
	 fprintf(out,"The drone has landed\n");
  	current_x = 0;
  	current_y = 0;
  	speaker = 0;
  	light = 0;
  	battery -= 1;
    power = 0;
    output();
  }
  else{
		flag[1]=0;
		fprintf(out,"ALU signal for subtact is generated.\n");
    fprintf(out, "The drone was already on the land\n");
  }
}

void ILU(){
	fprintf(out,"Illuminate() function has been called\n\n");
	fprintf(out,"ALU signal for subtact is generated.\n");
	if(light == 1) {
		flag[0]=1;
		fprintf(out,"The light has been turned off\n");
		light = 0;
	}
	else{
		flag[1]=1;
		fprintf(out,"The drone has been illuminated\n");
		light = 1;
	}
	battery -= 1;
  output();
}

void SPK(){
	fprintf(out,"SPEAKER() function has been called.\n\n");
	fprintf(out,"ALU signal for subtact is generated.\n");
	if(speaker == 1) {
		flag[0]=1;
		fprintf(out,"The speaker has been turned off\n");
		speaker = 0;
	}
	else{
		flag[1]=1;
		fprintf(out,"The speaker has been turned on\n");
		speaker = 1;
	}
	battery -= 1;
  output();
}

void MVR(int x2, int x3, int s){
	fprintf(out,"MoveToRegister() function has been called.\n\n");
	registers[x3] = x2;
	fprintf(out,"The value %d has been stored in register %d\n",x2,x3);
  battery -= 1;
  output();
}

void LDB(int x2, int x3, int s){
	fprintf(out, "LoadIntoRegister() function has been called.\n\n");
	if(s == 6) {
		registers[x3] = memory[registers[x2]];
		fprintf(out,"The value at memory location at register %d has been stored in register %d\n",x2,x3);
	}
	if(s == 7) {
		registers[x3] = memory[x2];
		fprintf(out,"The value at memory location at register %d has been stored in register %d\n",x2,x3);
	}
  output();
}

void STR(int x2, int x3, int s){
	fprintf(out, "StoreInMemory() function has been called.\n\n" );
	if(s == 4) {
		memory[x3] = x2;
		fprintf(out,"The value %d has been stored at memory location %d\n",x2,x3);
	}
	if(s == 7) {
		memory[registers[x3]] = x2;
		fprintf(out,"The value %d has been stored at address given by register %d\n",x2,x3);
	}
  output();
}

void REST(int t,int s){
	fprintf(out, "Rest() function has been called.\n\n");
	if(s == 3) {
		t = registers[t];
	}
	if(s == 2) {
		t = memory[registers[t]];
	}
	fprintf(out,"Now, the drone will rest\n");
	sleep(t);
  output();
}

void SPD(int x, int s){
	fprintf(out, "Speed() function has been called.\n\n");
	if(s == 3) {
		x = registers[x];
	}
	if(s == 2) {
		x = memory[registers[x]];
	}
	fprintf(out,"ALU signal for subtact is generated\n");
	if(speed < x) {
		fprintf(out,"The speed of the drone has beeen increamented to %d\n",x);
	}
	else if(speed > x) {
		flag[1]=1;
		fprintf(out,"The speed of the drone has been decremented to %d\n",x);
	}
	else{
		flag[0]=1;
		fprintf(out,"There is no change in the speed of the drone. It is %d\n",x);
	}
	speed = x;
	battery -= 1;
  output();
}

void BINF(){
	fprintf(out, "BatteryInfo() function has been called.\n\n");
	fprintf(out,"The battery remaining in the drone is %d%%\n",battery);
	battery -= 1;
  output();
}

void PRO(int x, int s){
	fprintf(out, "Project() function has been called.\n\n");
	char c[20];
	int b;
	FILE *fp;
	fp = fopen("projects.txt","r");
	if(s==3)
		x=registers[x];
	if(s==2)
		x=memory[registers[x]];
	while(1)
	{
		fscanf(fp,"%[^-]",c);
		fseek(fp,sizeof(char),SEEK_CUR);
		fscanf(fp,"%d\n",&b);
    if(x == 0 || x > 10){
      break;
    }
		if(b==x)
		{
			fprintf(out,"PROJECTING THE %s\n",c);
			break;
		}
	}
	battery-=1;
	output();
}

void GES(int x, int s){
	fprintf(out, "Gesture() function has been called.\n\n");
	char c[20];
	int b;
	FILE * fp;
	fp = fopen("projects.txt","r");
	if(s==3)
		x=registers[x];
	if(s==2)
		x=memory[registers[x]];
	while(1)
	{
		fscanf(fp,"%[^-]",c);
		fseek(fp,sizeof(char),SEEK_CUR);
		fscanf(fp,"%d\n",&b);
		if(b==x)
		{
			fprintf(out,"The gesture corresponding to id number %d is: %s\n",b,c);
			break;
		}
	}
	battery-=1;
	output();
}

void MOV(int x, int y, int s){
	fprintf(out, "Move() function has been called.\n\n");
	int i,j=0;
	switch(s) {
  	case 4: break;
  	case 5: {
      x=memory[registers[x]];
  		y=memory[registers[y]];
    }break;
  	case 6: {
      y=registers[y];
  		x=registers[x];
    }break;
	}
	int y1 = y - current_y;
	int x1 = x - current_x;
	float m = (float) y1 / x1;

	int d1 = x1*x1;
	int d2 = y1*y1;
	d1 = d1+d2;
	float d = sqrt(d1);

	for(i=0; i<5; i++) {
    if(obstacle[i][0] != 0 || obstacle[i][1] != 0){
			flag[1]=1;
  		float k0 = ( m * (obstacle[i][0]-current_x));
  		int k2= (int)k0;
  		k2=k2+current_y;
  		if(obstacle[i][1]==k2) {
				flag[0]=1;
  			fprintf(out,"Obstacle (%d,%d) in the path\n",obstacle[i][0],obstacle[i][1]);
  			fprintf(out,"Taking alternate path\n");
  			j=1;
        break;
  		}
    }
	}
	if(j!=1) {
		fprintf(out,"No obstacle in the path\n");
		fprintf(out,"Taking the path having equation:y = %d(x - %d) + %d\n",(int)m,current_x,current_y);
		fprintf(out,"Distance covered= %.2f units\n",d);
	}
	fprintf(out,"Drone has moved from (%d,%d) to (%d,%d)\n",current_x,current_y,x,y);
	current_x = x;
	current_y = y;
	battery--;
	output();
}

void OBS(int x, int y, int s){
	fprintf(out, "Obstacle() function has been called.\n\n");
	int i,j;
	switch(s) {
	case 4:break;
	case 5:{
    x=memory[registers[x]];
		y=memory[registers[y]];
  }break;
	case 6:{
    y=registers[y];
		x=registers[x];
  }break;
	}
	for(i=0; i<5; i++){
		if(obstacle[i][0]==0 && obstacle[i][1]==0) {
			flag[0]=1;
			obstacle[i][0]=x;
			obstacle[i][1]=y;
			fprintf(out,"The obstacle has been set at (%d,%d)\n",x,y);
			battery--;
			output();
			break;
		}
	}
}

void FP(int x, int y, int s){
	fprintf(out, "Follow_player() function has been called.\n\n");
	switch(s){
  	case 4: break;
  	case 5:{
      x=memory[registers[x]];
  		y=memory[registers[y]];
    }break;
  	case 6:{
      y=registers[y];
  		x=registers[x];
    }break;
	}
	battery -=1;
	fprintf(out,"Drone will follow the player from the location (%d,%d) to the location (%d,%d)\n",current_x,current_y,x,y);
  current_x = x;
  current_y = y;
	output();
}

void output(){
  fprintf(out,"\n***************************************\n");
	fprintf(out,"Battery          :  %d %%\n",battery);
	fprintf(out,"Speaker status   :  %d\n",speaker);
	fprintf(out,"Torch status     :  %d\n",light);
	fprintf(out,"Program Counter  :  %d\n",PC);
  fprintf(out,"MAR              :  %d\n",MAR);
  fprintf(out,"MDR              :  %s\n",MDR);
  fprintf(out,"IR               :  %s\n",IR);
	fprintf(out,"ALU flag status  :Z=%d \t N=%d\n",flag[0],flag[1]);
  fprintf(out,"\n***************************************\n\n");
  fprintf(out,"***********************\n");
	for(int i=0; i<16; i++)
		fprintf(out,"| R%02d        | %05d  |\n",i,registers[i]);
  fprintf(out,"***********************\n");
  fprintf(out,"\n----------------------------------------------------------------------\n\n");
	flag[0]=0;flag[1]=0;
}
