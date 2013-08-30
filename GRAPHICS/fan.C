#include<stdio.h>
#include<graphics.h>
#include<conio.h>
int midx,midy;
void drawfan()
{
   setfillstyle(1,15);
   pieslice(midx,midy,0,30,150);
   floodfill(midx,midy,15);

   setfillstyle(1,15);
   pieslice(midx,midy,120,150,150);
   floodfill(midx,midy,15);

   setfillstyle(1,15);
   pieslice(midx,midy,240,270,150);
   floodfill(midx,midy,15);

}
void speedfan(int d)
{
    int i=0;
    while(1)
    {
      if(i==360) break;
      setfillstyle(1,15);
      pieslice(midx,midy,0+i,30+i,150);
      floodfill(midx,midy,15);

      setfillstyle(1,15);
      pieslice(midx,midy,120+i,150+i,150);
      floodfill(midx,midy,15);

      setfillstyle(1,15);
      pieslice(midx,midy,240+i,270+i,150);
      floodfill(midx,midy,15);



      delay(d);
      cleardevice();
      i=i+30;
    }


}

void main()
{
  int gdriver=DETECT,gmode,i,d=150;
  initgraph(&gdriver,&gmode,"c:\\tc\\bgi");
  midx=getmaxx()/2;
  midy=getmaxy()/2;
  drawfan();
  while(1)
  {
    if(kbhit()&&d>0)
    {
     getch();
     d=d-50;
    }
    if(d<=0) break;
    speedfan(d);
  }
  drawfan();

  getch();
}