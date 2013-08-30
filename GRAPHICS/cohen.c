#include<graphics.h>
#include<stdio.h>
#include<conio.h>

typedef int OutCode;
const int INSIDE=0;
const int LEFT=1;
const int RIGHT=2;
const int BOTTOM=4;
const int TOP=8;
int xmin,ymin,xmax,ymax;

OutCode computeOutCode(double x,double y)
{
OutCode code;
code=INSIDE;
if(x<xmin)code|=LEFT;
else if(x>xmax)code|=RIGHT;
else if(y<ymin)code|=BOTTOM;
else if(y>ymax)code|=TOP;
return code;

}

void clipLine(float x0,float y0,float x1,float y1)
{
OutCode outcode0=computeOutCode(x0,y0);
OutCode outcode1=computeOutCode(x1,y1);
int accept=0;
rectangle(xmin,ymin,xmax,ymax);
line(x0,y0,x1,y1);
while(1)
{
if(!(outcode0|outcode1))
	{
	accept=1;
	break;
	}
else if(outcode0&outcode1)break;
else
	{
	float x,y;
	OutCode outcodeout=outcode0?outcode0:outcode1;
	if(outcodeout&TOP)
		{
		x=x0+(x1-x0)*(ymax-y0)/(y1-y0);
		y=ymax;
		}
	else if(outcodeout&BOTTOM)
		{
		x=x0+(x1-x0)*(ymin-y0)/(y1-y0);
		y=ymin;
		}
	else if(outcodeout&RIGHT)
		{
		y=y0+(y1-y0)*(xmax-x0)/(x1-x0);
		x=xmax;
		}
	else if(outcodeout&LEFT)
		{
		y=y0+(y1-y0)*(xmin-x0)/(x1-x0);
		x=xmin;
		}
	if(outcodeout==outcode0)
		{
		x0=x;
		y0=y;
		outcode0=computeOutCode(x0,y0);
		}
	else
		{
		x1=x;
		y1=y;
		outcode1=computeOutCode(x1,y1);
		}
	cleardevice();
	rectangle(xmin,ymin,xmax,ymax);
	line(x0,y0,x1,y1);
	getch();
	}
}
if(accept)
	{
	cleardevice();
	rectangle(xmin,ymin,xmax,ymax);
	line(x0,y0,x1,y1);
	}

}

main()
{
int gdriver=DETECT,gmode;
float x0,y0,x1,y1;
xmin=ymin=200;
xmax=ymax=400;
printf("Enter coordinates of line:");
scanf("%f%f%f%f",&x0,&y0,&x1,&y1);
initgraph(&gdriver,&gmode,"c:\\tc\\bgi");
clipLine(x0,y0,x1,y1);
getch();
return;
}
