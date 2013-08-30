#include<stdio.h>
#include<conio.h>
#include<graphics.h>

main()
{
int gdriver=DETECT,gmode;
int x1,y1,x2,y2,d1,d2;
float m,xk,yk;
printf("Enter endpoint coordinates:\n");
scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
initgraph(&gdriver,&gmode,"c:\\tc\\bgi");

if(x1!=x2)m=(y2-y1)/(x2-x1);
d1=x2-x1;
d2=y2-y1;


if(d1>d2)
{
for(xk=x1,yk=y1;xk<=x2;)
	{
	putpixel(xk,yk,BLUE);
	 xk++;

	 yk=yk+m;
	}
}
else
{
for(xk=x1,yk=y1;yk<=y2;)
	{
	putpixel(xk,yk,BLUE);
	yk++;
	if(x1!=x2)xk=xk+1/m;

	}
}

getch();
return 0;
}