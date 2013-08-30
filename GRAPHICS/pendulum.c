#include<graphics.h>
#include<dos.h>
#include<iostream.h>
#include<conio.h>
#include<stdlib.h>
#include<math.h>

#define R 20
#define L 200
#define T (3.14/6)


void background()
{       setcolor(WHITE);
	rectangle(200,80,440,100);
}

void drawString(int x,int y)
{	setcolor(YELLOW);
	line(320,100,x,y);
}

void eraseString(int x,int y)
{	setcolor(BLACK);
	line(320,100,x,y);
}

void drawBall(int x,int y)
{	setcolor(GREEN);
	circle(x,y,R);
	ellipse(x,y,180,360,R-2,R-2);
	ellipse(x,y,190,350,R-4,R-4);
	ellipse(x,y,200,340,R-6,R-6);
	ellipse(x,y,210,330,R-8,R-8);
}

void eraseBall(int x,int y)
{	setcolor(BLACK);
	circle(x,y,R);
	ellipse(x,y,180,360,R-2,R-2);
	ellipse(x,y,190,350,R-4,R-4);
	ellipse(x,y,200,340,R-6,R-6);
	ellipse(x,y,210,330,R-8,R-8);
}

int main()
{
	int gDriver=DETECT,gMode=0,i;
	initgraph(&gDriver,&gMode,"C:\\TC\\BGI");

	float rad=0.01;
	int string_bottom_x,string_bottom_y;
	int ball_x,ball_y,sign=1;

	background();
	drawString(320,300);
	eraseString(320,300);
	//drawBall(320,320);

	for(rad=0.01;rad<T;rad+=(sign*0.01))
	{	string_bottom_y=cos(rad)*L;
		string_bottom_x=sin(rad)*L;
		ball_y=cos(rad)*(L+20);
		ball_x=sin(rad)*(L+20);
		//cout<<"("<<ball_x<<"|"<<ball_y<<")";
		drawString(320-string_bottom_x,100+string_bottom_y);
		drawBall(320-ball_x,100+ball_y);
		delay(60);
		eraseString(320-string_bottom_x,100+string_bottom_y);
		eraseBall(320-ball_x,100+ball_y);
		if(ball_y==190&&ball_x==109)
		{	sign=-1;
		}
		if(ball_y==190&&ball_x==-109)
		{	sign=1;
			//getch();
		}
	}


	getch();
	return 0;
}