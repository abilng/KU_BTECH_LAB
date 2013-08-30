#include<stdio.h>
#include<conio.h>
#include<graphics.h>

#define LEFT 0
#define RIGHT 1
#define BOTTOM 2
#define TOP 3

#define OUT_IN 1
#define IN_IN 2
#define IN_OUT 3
#define OUT_OUT 4

int outlist[100];
int outListSize;

void addPoint(int x,int y)
{
outlist[2*outListSize]=x;
outlist[2*outListSize+1]=y;
outListSize++;
}

int checkLinePos(int p1,int p2,int clipper,int clipperPos)
{
int linePos;

if(p1==clipperPos && p2==clipperPos)linePos=IN_IN;
else if(p1<=clipperPos && p2<=clipperPos)
	{
	if(clipper==LEFT || clipper==TOP)linePos=OUT_OUT;
	else if(clipper==RIGHT || clipper==BOTTOM)linePos=IN_IN;
	}
else if(p1<clipperPos && p2>clipperPos)
	{
	if(clipper==LEFT || clipper==TOP)linePos=OUT_IN;
	else if(clipper==RIGHT || clipper==BOTTOM)linePos=IN_OUT;

	}
else if(p1>clipperPos && p2<clipperPos)
	{
	if(clipper==LEFT || clipper==TOP)linePos=IN_OUT;
	else if(clipper==RIGHT || clipper==BOTTOM)linePos=OUT_IN;

	}
else if(p1>=clipperPos && p2>=clipperPos)
	{
	if(clipper==LEFT || clipper==TOP)linePos=IN_IN;
	else if(clipper==RIGHT || clipper==BOTTOM)linePos=OUT_OUT;

	}
return linePos;
}

void clipEdge(int x1,int y1,int x2,int y2,int clipper,int clipperPos)
{
int p1,p2,linePos;
int xp,yp;

if(clipper==LEFT || clipper==RIGHT)
	{
	p1=x1;
	p2=x2;
	}
else if(clipper==BOTTOM || clipper==TOP)
	{
	p1=y1;
	p2=y2;
	}
linePos=checkLinePos(p1,p2,clipper,clipperPos);

if(linePos==OUT_IN || linePos==IN_OUT)
	{
	if(clipper==LEFT || clipper==RIGHT)
		{
		xp=clipperPos;
		yp=(y2-y1)*(xp-x1)/(x2-x1)+y1;
		}
	else if(clipper==TOP || clipper==BOTTOM)
		{
		yp=clipperPos;
		xp=(x2-x1)*(yp-y1)/(y2-y1)+x1;
		}
	addPoint(xp,yp);
	if(linePos==OUT_IN)addPoint(x2,y2);
	}
else if(linePos==IN_IN)
	{
	addPoint(x2,y2);
	}
}

void clipPolygon(int n,int poly[],int xmin,int ymin,int xmax,int ymax)
{
int i,k;
int clipperPos[4];
clipperPos[LEFT]=xmin;
clipperPos[RIGHT]=xmax;
clipperPos[BOTTOM]=ymax;
clipperPos[TOP]=ymin;

drawpoly(n+1,poly);
rectangle(xmin,ymin,xmax,ymax);
getch();
for(k=0;k<4;k++)
{
outListSize=0;
for(i=0;i<2*n;i+=2)
clipEdge(poly[i],poly[i+1],poly[i+2],poly[i+3],k,clipperPos[k]);
for(i=0;i<2*outListSize;i++)poly[i]=outlist[i];
n=outListSize;
poly[2*n]=poly[0];
poly[2*n+1]=poly[1];
cleardevice();
drawpoly(n+1,poly);
rectangle(xmin,ymin,xmax,ymax);
getch();
}
cleardevice();
printf("Final Clipped Polygon\n");
setcolor(RED);
drawpoly(n+1,poly);
getch();
}

main()
{
int gdriver=DETECT,gmode;
int n,poly[100];
int i;
printf("Enter the no of vertices : ");
scanf("%d",&n);
printf("enter the vertex coordinates one by one:\n" );
for(i=0;i<2*n;i=i+2)scanf("%d%d",&poly[i],&poly[i+1]);
poly[2*n]=poly[0];
poly[2*n+1]=poly[1];
initgraph(&gdriver,&gmode,"c:\\tc\\bgi");
clipPolygon(n,poly,200,200,400,400);
getch();
return;
}

