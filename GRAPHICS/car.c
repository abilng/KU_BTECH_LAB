#include<graphics.h>
#include<stdio.h>
#include<dos.h>
#include<iostream.h>
#include<conio.h>
#include<stdlib.h>

int gear=1;
void ROAD(int,int);

class CAR
{	public:
		int lane;
		CAR()
		{	lane=0;
		}
		void drawCAR(int,int,int);
		void moveLeft();
		void moveRight();
		void explode();
}car;

void CAR::drawCAR(int x=107,int y=380,int draw=1)
{       x+=lane*52;
	setcolor(BLACK);
	if(draw) setcolor(YELLOW);
	line(x+25,y,x+40,y+5); 		//outline
	line(x+40,y+5,x+48,y+10);
	line(x+48,y+10,x+50,y+80);
	line(x+50,y+80,x,y+80);
	line(x+25,y,x+10,y+5);
	line(x+10,y+5,x+2,y+10);
	line(x+2,y+10,x,y+80);
	if(draw) setcolor(WHITE);
	line(x+25,y+15,x+45,y+18);	//wind shield
	line(x+45,y+18,x+41,y+35);
	line(x+41,y+35,x+25,y+35);
	line(x+25,y+15,x+5,y+18);
	line(x+5,y+18,x+9,y+35);
	line(x+9,y+35,x+25,y+35);
	line(x+3,y+26,x+8,y+40);			//left glass
	line(x+8,y+40,x+8,y+50);
	line(x+8,y+50,x+3,y+55);
	line(x+3,y+55,x+3,y+26);
	line(x+47,y+26,x+42,y+40);			//right glass
	line(x+42,y+40,x+42,y+50);
	line(x+42,y+50,x+47,y+55);
	line(x+47,y+55,x+47,y+26);
	line(x+25,y+50,x+39,y+50);			//engine right
	line(x+39,y+50,x+37,y+78);
	line(x+37,y+78,x+25,y+78);
	line(x+25,y+78,x+39,y+50);
	line(x+25,y+60,x+38,y+60);
	line(x+25,y+70,x+38,y+70);
	line(x+25,y+50,x+11,y+50);			//engine left
	line(x+11,y+50,x+13,y+78);
	line(x+13,y+78,x+25,y+78);
	line(x+25,y+78,x+11,y+50);
	line(x+25,y+60,x+12,y+60);
	line(x+25,y+70,x+12,y+70);
	if(draw) setcolor(WHITE);
	line(x+25,y+82,x+50,y+82);				 //spoiler
	line(x+50,y+82,x+48,y+84);
	line(x+48,y+84,x+25,y+84);
	line(x+25,y+82,x,y+82);					//spoiler
	line(x,y+82,x+2,y+84);
	line(x+2,y+84,x+25,y+84);
}

void CAR::moveLeft()
{	if(lane>0)
	{       drawCAR(107,380,0);
		lane--;
		drawCAR(107,380,1);
	}
}
void CAR::moveRight()
{	if(lane<3)
	{       drawCAR(107,380,0);
		lane++;
		drawCAR(107,380,1);
	}
}
void CAR::explode()
{	int x=107,y=380;
	x+=lane*52;
	setcolor(RED);
	for(int i=0;i<=50;i++)
	{	circle(x+2,y+50,i/2);
		circle(x+20,y+25,i/3);
		circle(x+40,y,i);
		delay(5);
	}
	setcolor(BLACK);
	for(i=0;i<=50;i++)
	{	circle(x+2,y+50,i/2);
		circle(x+20,y+25,i/3);
		circle(x+40,y,i);
	}
	ROAD(100,0);
}

class ENEMY
{	public:
		int x,lane;
		int y;
		ENEMY()
		{	lane=-1;
		}
		int enemy();
		void draw(int);
}E1,E2;
int ENEMY::enemy()
{       int ret=1;
	if(lane==-1)
	{	lane=random(4);
		y=0;
	}
	draw(1);
	if(y>=380-50 && lane==car.lane)
	{	ret=-1;
		lane=-1;
	}
	if(y>=480) lane=-1;
	delay(5);
	draw(0);
	y+=gear;
	return ret;
}

void ENEMY::draw(int draw=1)
{       x=lane*52+107;
	if(draw==1) setcolor(RED);
	else	setcolor(BLACK);
	rectangle(x,y,x+50,y+50);
}

void ROAD(int x=100,int y=0)
{	setcolor(WHITE);
	rectangle(x,y,x+5,y+480);
	rectangle(x+224,y,x+229,y+480);
}

void divider(int x=211,int y=0)
{	static pos=0;
	setcolor(WHITE);
	for(int i=0;i<8;i++)
		rectangle(x,y+(i*60)+pos,x+2,y+30+(i*60)+pos);
	delay(10);
	setcolor(BLACK);
	for(i=0;i<8;i++)
		rectangle(x,y+(i*60)+pos,x+2,y+30+(i*60)+pos);

	if(pos<30) pos+=gear;
	else pos=0;
}

int main()
{
	int gDriver=DETECT,gMode=0,i;
	initgraph(&gDriver,&gMode,"C:\\TC\\BGI");
	int lives=3,button;
	char *msg;

	car.drawCAR();
	ROAD();
	divider();



	while(lives)
	{
		if(kbhit())
		{       button=getch();
			switch(button)
			{ case 119: if(gear<10) gear++;
				     break;
			  case 115: if(gear>1) gear--;
				     break;
			  case 97: car.moveLeft();
				   break;
			  case 100: car.moveRight();
				   break;
			  case 98: exit(1);
				  break;
			}
		}
		divider();
		if(E1.enemy()==-1||E2.enemy()==-1)
		{       car.explode();
			car.drawCAR(107,380,0);
			lives--;
		}
	}

	getch();
	return 0;
}
