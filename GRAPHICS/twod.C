#include <stdio.h>
#include<graphics.h>
#include <conio.h>
#include<math.h>
void main()
{
int gd=DETECT,gm,n,i,choice,poly[20],tx,ty,xc,yc;
float t,sx,sy;
//int far * poly;
initgraph(&gd,&gm,"C:\\TC\\BGI");
printf("Enter the no of vertices : ");
scanf("%d",&n);
//poly=(int far *)malloc(2*n*sizeof(int));
printf("enter the coordinates" );
for(i=0;i<2*n;i=i+2)
{
scanf("%d%d",&poly[i],&poly[i+1]);
}
poly[2*n+1]=poly[1];
poly[2*n]=poly[0];
drawpoly(n+1,poly);
do
{
printf("Enter the menu : \n1.Scaling 2.Translation 3.Rotation 4.Exit \n");
scanf("%d",&choice);
switch(choice)
{
case 1:printf("enter the scaling coeeficients\n");
scanf("%f %f",&sx,&sy);
for(i=0;i<2*n;i+=2)
{
poly[i]=poly[i]*sx;
poly[i+1]=poly[i+1]*sy;
}
poly[2*n]=poly[0];
poly[2*n+1]=poly[1];
setcolor(BLUE);
drawpoly(n+1,poly);
break;
  case 2:printf("enter the translation coeeficients\n");
scanf("%d %d",&tx,&ty);
for(i=0;i<2*n;i+=2)
{
poly[i]=poly[i]+tx;
poly[i+1]=poly[i+1]+ty;
}
poly[2*n]=poly[0];
poly[2*n+1]=poly[1];
setcolor(YELLOW);
drawpoly(n+1,poly);
break;
case 3: printf("enter the angle\n");
scanf("%f",&t);
printf("enter the wrt point\n");
scanf("%d %d",&xc,&yc);
//t=(t*3.14)/180;
for(i=0;i<2*n;i+=2)
{
poly[i]=(poly[i]-xc)*cos(t)-(poly[i+1]-yc)*sin(t);
poly[i]=poly[i]+xc;
poly[i+1]=(poly[i]-xc)*sin(t)+(poly[i+1]-yc)*cos(t);
poly[i+1]=poly[i+1]+yc;
}
poly[2*n]=poly[0];
poly[2*n+1]=poly[1];
setcolor(GREEN);
drawpoly(n+1,poly);
break;
case 4:exit(0);
}
}
 while(choice!=4);


getch();
       }
