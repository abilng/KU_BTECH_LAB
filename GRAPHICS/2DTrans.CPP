#include<stdio.h>
#include<stdlib.h>
#include<iostream.h>
#include<conio.h>
#include<graphics.h>
#include<math.h>

void main()
{
	int gd=DETECT,gm;
	int pts[50],pts1[50],no_pts,i,j,ch,tx,ty,r_x,r_y;
	float d;
	initgraph(&gd,&gm,"C:\\TC\\BGI");
	cout<<"Enter no of point : ";
	
	no_pts=3;
	pts[0]=20; pts[1]=20;
	pts[2]=20; pts[3]=200;
	pts[4]=200; pts[5]=20;
	pts[6]=20; pts[7]=20;
	//pts[i]=pts[0]; pts[i+1]=pts[1];
	drawpoly(no_pts+1,pts);

	while(1)
	{ cout<<"1.Translate\t 2.Rotate\t 3.Scale\t Enter choice:";
	  cin>>ch;
	  if(ch==4) break;
	  switch(ch)
	  { case 3:   cout<<"Enter Tx and Ty";
		      cin>>tx>>ty;
		      r_x=pts[0];
		      r_y=pts[1];
		      for(i=0;i<no_pts*2;i+=2)
		      {	pts[i]=(pts[i]-r_x)*tx+r_x;
			pts[i+1]=(pts[i+1]-r_y)*ty+r_y;
		      }
		      pts[i]=(pts[i]-r_x)*tx+r_x;
		      pts[i+1]=(pts[i]-r_y)*ty+r_y;
		      setcolor(RED);
		      drawpoly(no_pts+1,pts);
		break;

	    case 2:   cout<<"Enter angle in radians, X ref and Y ref:";
		      cin>>d>>r_x>>r_y;
		      for(i=0;i<no_pts*2;i+=2)
		      {	pts1[i]=((pts[i]-r_x)*cos(d)-(pts[i+1]-r_y)*sin(d))+r_x;
			pts1[i+1]=((pts[i]-r_x)*sin(d)+(pts[i+1]-r_y)*cos(d))+r_y;
		      }
		      pts1[i]=pts1[0]; pts1[i+1]=pts1[1];
		      setcolor(YELLOW);
		      drawpoly(no_pts+1,pts1);
		break;

	    case 1:   cout<<"Enter Sx and Sy";
		      cin>>tx>>ty;
		      for(i=0;i<no_pts*2;i+=2)
		      {	pts[i]+=tx;
			pts[i+1]+=ty;
		      }
		      pts[i]+=tx; pts[i+1]+=ty;
		      setcolor(GREEN);
		      drawpoly(no_pts+1,pts);
		break;
	  }
	}

	getch();
	closegraph();
}