#include<iostream>
#include<stdio.h>
using namespace std;
float l,b,s,r,b1,h,at,ar,as,ac;
void area(int a)
{
  as=a*a;
}
void putdata(int a)
{
  cout<<"area of square is\n"<<a;
}
void area()
{
  ac=3.14*r*r;
}
void putdata()
{
  cout<<"area of circle \n"<<ac;
} 
void area(int a,int b)
{
+  ar=l*b;
}
void putdata(int a,int b)
{
  cout<<"area of rectangle\n"<<b;
}
void area(int a,int b,int c)
{
  at=0.5*a*b;
}
void putdata(int a,int b,int c)
{
  cout<<"area of triangle is\n"<<at;
}
main()
{
  int ch,op=1,c=0;
  while(op==1)
    {
      cout<<"area\n";
      cout<<"1.triangle 2.rectangle 3.circle 4.square\n";
      cin>>ch;
      if(ch==1)
	{
	  cout<<"enter base and height\n";
	  cin>>b1>>h;
	  area(b1,h,c);
	  putdata(b1,h,at);
	  cout<<"\n";
	}
      if(ch==2)
	{
	  cout<<"enter length and breadth\n";
	  cin>>l>>b;
	  area(l,b);
	  putdata(l,ar);
	  cout<<"\n";
	}
      if(ch==3)
	{
	  cout<<"enter radius\n";
	  cin>>r;
	  area();
	  putdata();
	  cout<<"\n";
	}
      if(ch==4)
	{
	  cout<<"enter the side\n";
	  cin>>s;
	  area(s);
	  putdata(as);
	  cout<<"\n";
	}
      cout<<"1.continue 2.exit\n";
      cin>>op;
    }
}
