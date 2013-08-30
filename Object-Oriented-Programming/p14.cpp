#include<iostream>
#include<stdio.h>
using namespace std;
class book
{
  char name[20];
  int im,id,iy,d;
  int dm,dy,dd;
public:
  void getdata()
  {
    cout<<"enter the name of book\n";
    cin>>name;
    cout<<"enter the hire date as data-month-year\n";
    cin>>id>>im>>iy;
    cout<<"enter the due day\n";
    cin>>d;
    if(d>=365)
      {
	dd=id+d;
	dd=dd%365;
	dm=im;
	dy=iy+(d%365+1);
      }
    else
      {
    dd=id+d;
    if(im==1||im==3||im==5||im==7||im==8||im==10||im==12)
      {
	if(dd>31)
	  {
	    dd=dd%31;
	    dm=im+1;
	  }
	else dm=im;
      }
    if(im==4||im==6||im==9||im==11)
      {
	if(dd>30)
	  {
	    dd=dd%30;
	    dm=im+1;
	  }
	else dm=im;
      }
    if(im==2)
      {
	if(iy%4==0||iy%100==0)
	  {
	    if(dd>29)
	      {
		dd=dd%29;
		dm=im+1;
	      }
	    else dm=im;
	  }
	else
	  {
	    if(dd>28)
	      {
		dd=dd%28;
		dm=im+1;
	      }
	    else dm=im;
	  }
      }
    if(dm>12)
      {
	dm=dm%12;
	dy=iy+1;
      }
    else
      dy=iy;
      }
  }
  void display()
  {
    cout<<"due date is\n";
    cout<<dd<<"-"<<dm<<"-"<<dy<<"\n";
  }
};
main()
{
  int op=1,ch;
  book b1;
  while(op==1)
    {
  b1.getdata();
  b1.display();
  cout<<"1.conitnue 2.exit\n";
  cin>>op;
    }

}


-------------------------------OUTPUT------------------------------


enter the name of book
hp
enter the hire date as data-month-year
27
2
2000
enter the due day
5
due date is
3-3-2000
1.conitnue 2.exit
1
enter the name of book
asd
enter the hire date as data-month-year
2
1
2011
enter the due day
365
due date is
2-1-2012
1.conitnue 2.exit
2

--------------------------------------------------------------------

























































