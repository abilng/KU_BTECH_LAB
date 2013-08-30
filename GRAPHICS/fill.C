#include<graphics.h>
#include<stdio.h>
#include<conio.h>
#include<dos.h>

void boundaryFill(int x,int y,int fill,int boundary)
{
int current;
current=getpixel(x,y);
if(current!=boundary&&current!=fill)
	{
	delay(10);
	putpixel(x,y,fill);
	boundaryFill(x+1,y,fill,boundary);
	boundaryFill(x-1,y,fill,boundary);
	boundaryFill(x,y+1,fill,boundary);
	boundaryFill(x,y-1,fill,boundary);
	}

}

void floodFill(int x,int y,int fillcolor,int oldcolor)
{
if(oldcolor==getpixel(x,y))
	{
	delay(10);
	putpixel(x,y,fillcolor);
	floodFill(x+1,y,fillcolor,oldcolor);
	floodFill(x-1,y,fillcolor,oldcolor);
	floodFill(x,y+1,fillcolor,oldcolor);
	floodFill(x,y-1,fillcolor,oldcolor);

	}
}

main()
{
int gdriver=DETECT,gmode,n,poly[20],i,x,y;
printf("Enter the no of vertices : ");
scanf("%d",&n);
printf("enter the coordinates:\n" );
for(i=0;i<2*n;i=i+2)
{
scanf("%d%d",&poly[i],&poly[i+1]);
}
poly[2*n+1]=poly[1];
poly[2*n]=poly[0];
initgraph(&gdriver,&gmode,"c:\\tc\\bgi");
setcolor(BLUE);
drawpoly(n+1,poly);
getch();
printf("Enter coordinates of an interior point:");
scanf("%d%d",&x,&y);
boundaryFill(x,y,GREEN,BLUE);
getch();
floodFill(x,y,YELLOW,GREEN);
getch();
return;
}