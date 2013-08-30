#include<iostream>
#include<stdio.h>
using namespace std;
class shape
{
public:
  int a;
  int b;
  void getdata()
  {
    cout<<"enter the dimensions\n";
    cin>>a>>b;
  }
  virtual void display()
  {
  }
};
class triangle:public shape
{
public:
 void display()
  {
    int area;
    area=a*b*0.5;
    cout<<"area of triangle is"<<area<<"\n";
  }
};
class rectangle:public shape
{
public:
 void display()
  {
    int area;
    area=a*b;
    cout<<"area of ractangle is"<<area<<"\n";
  }
};
main()
{
  int op=1,ch;
  shape *s1,*s2;
  triangle t;
  rectangle r;
  while(op==1)
    {
      cout<<"enter the choice \n1.triangle\n2.rectangle\n";
      cin>>ch;
      if(ch==1)
	{ 
  s1=&t;
  s1->getdata();
  s1->display();
	}
      if(ch==2)
	{
	  s2=&r;
  s2->getdata();
  s2->display();
	}
      cout<<"1.continue 2.exit\n";
      cin>>op;
    }
}

/*----------------------------output----------------------------------------



enter the choice 
1.triangle
2.rectangle
1
enter the dimensions
2
3
area of triangle is3
1.continue 2.exit
1
enter the choice 
1.triangle
2.rectangle
2
enter the dimensions
4
5
area of ractangle is20
1.continue 2.exit
2

-----------------------------------------------------------------------------
*/





























































