#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<math.h>
main()
{
int gdriver=DETECT,gmode;
int xa,ya,xb,yb;
int dx,dy;
float p;
float twoDy,twoDyDx;
float x,y,xEnd;
printf("Enter cordinate endpoints:");
scanf("%d%d%d%d",&xa,&ya,&xb,&yb);
initgraph(&gdriver,&gmode,"c:\\tc\\bgi");
//printf("Hello world\n");
dx=abs(xa-xb);
dy=abs(ya-yb);
p=2*dy-dx;
twoDy=2*dy;
twoDyDx=2*(dy-dx);
if(xa>xb)
	{
	 x=xb;
	 y=yb;
	 xEnd=xa;
	}
else
	{
	x=xa;
	y=ya;
	xEnd=xb;
	}
putpixel(x,y,YELLOW);
while(x<xEnd)
	{

	x++;
	if(p<0)
		{
		p+=twoDy;
		}
	else
		{
		y++;
		p+=twoDyDx;
		}
	putpixel(x,y,YELLOW);
	}
getch();
return 0;
}