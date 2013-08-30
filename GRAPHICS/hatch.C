#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<stdlib.h>



void hatchFill(int x,int y,int fillcolor,int oldcolor,int xinc,int yinc,int xc,int yc )
{
if(oldcolor==getpixel(x,y))
	{
	delay(1);
	putpixel(x,y,fillcolor);
	hatchFill(x+xinc,y+yinc,fillcolor,oldcolor,xinc,yinc,xc,yc);
	hatchFill(x-xinc,y-yinc,fillcolor,oldcolor,xinc,yinc,xc,yc);
	hatchFill(x+xc,y-yc,fillcolor,oldcolor,xinc,yinc,xc,yc);
	hatchFill(x-xc,y+yc,fillcolor,oldcolor,xinc,yinc,xc,yc);

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
fillpoly(n+1,poly);
getch();
printf("Enter coordinates of an interior point:");
scanf("%d%d",&x,&y);
clrscr();
cleardevice();
fillpoly(n+1,poly);
printf("Horizontal hatch fill\n");
hatchFill(x,y,RED,WHITE,1,0,0,3);
getch();
cleardevice();
clrscr();
fillpoly(n+1,poly);
printf("Vertical hatch fill\n");
hatchFill(x,y,RED,WHITE,0,1,3,0);
getch();
cleardevice();
clrscr();
fillpoly(n+1,poly);
printf("Diagonal hatch fill\n");
hatchFill(x,y,RED,WHITE,1,1,3,3);
getch();
return;
}