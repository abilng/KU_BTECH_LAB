#include<stdio.h>
#include<graphics.h>
#include<conio.h>
void main()
{
int gdriver=DETECT,gmode;
float x,y,xc,yc,p,r;
initgraph(&gdriver,&gmode,"c:\\tc\\bgi");
printf("Enter the centre coordinates:");
scanf("%f %f",&xc,&yc);
printf("Enter the radius:");
scanf("%f",&r);
p=(5/4)-r;
x=0;
y=r;
putpixel(xc,yc+r,WHITE);
while(x<y)
{
if(p<0)
{
x++;
p=p+2*(x+1)+1;
putpixel(x+xc,y+yc,WHITE);
putpixel(y+xc,x+yc,WHITE);
putpixel(y+xc,yc-x,WHITE);
putpixel(x+xc,yc-y,WHITE);
putpixel(xc-x,yc-y,WHITE);
putpixel(xc-y,yc-x,WHITE);
putpixel(xc-y,yc+x,WHITE);
putpixel(xc-x,y+yc,WHITE);
}
else
{
x++;
y--;
p=p+2*(x+1)+1-2*(y-1);
putpixel(x+xc,y+yc,WHITE);
putpixel(y+xc,x+yc,WHITE);
putpixel(y+xc,yc-x,WHITE);
putpixel(x+xc,yc-y,WHITE);
putpixel(xc-x,yc-y,WHITE);
putpixel(xc-y,yc-x,WHITE);
putpixel(xc-y,yc+x,WHITE);
putpixel(xc-x,y+yc,WHITE);
}
}
getch();
}
