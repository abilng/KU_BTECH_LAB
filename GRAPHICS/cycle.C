#include<stdio.h>
#include<graphics.h>
#include<math.h>

int getny(int x){
	float x1=x/85.0;
	return 240+sin(x1)*45;
}
void track(){
	int i;
	for(i=0;i<640;i++){
		putpixel(i,getny(i),15);
	}
}

void cycle(int x,int y,int c)
{
	int i;
	int ca[20];
	ca[0]=x-25;
	ca[1]=getny(x-25)-15;
	ca[2]=x-20;
	ca[3]=y-25;
	ca[4]=x+20;
	ca[5]=y-25;
	ca[6]=x;
	ca[7]=y;
	ca[8]=x-20;
	ca[9]=y-25;
	ca[10]=x+20;
	ca[11]=y-25;
	ca[12]=x+25;
	ca[13]=getny(x+25)-15;
	setcolor(c);
	for(i=0;i<6;i++){
		line(ca[i*2],ca[i*2+1],ca[(i+1)*2],ca[(i+1)*2+1]);
	}
	circle(ca[0],ca[1],15);
	circle(ca[12],ca[13],15);
}

void main()
{
  int gdriver=DETECT,gmode,i;
  initgraph(&gdriver,&gmode,"z:\\bgi");
  for(i=1;i<640;i++){
	cycle(i-1,getny(i-1)-25,0);
	cycle(i,getny(i)-25,15);
	track();
	delay(20);
  }
  getch();
  closegraph();
}