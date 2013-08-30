#include<stdio.h>
#include<iostream>
using namespace std;
class staff
{
  int code;
  char name[30];
public:
  void getd()
  {
    cout<<"enter name\n";
    cin>>name;
    cout<<"etner code\n";
    cin>>code;
  }
  void putd()
  {
    cout<<"name      :"<<name<<"\n";
    cout<<"code      :"<<code<<"\n";
  }
}s1;
class education
{
  char qual[30];
  char proed[30];
public:
  void get1()
  {
  cout<<"enter the qualification in general\n";
  cin>>qual;
  cout<<"enter the highest professional qualification\n";
  cin>>proed;
  }
  void put1()
  {
    cout<<"highest qualification is :"<<qual<<"\n";
    cout<<"proffesional qualification is  :"<<proed<<"\n";
  }
}e1;
class teacher:public staff,public education
{
  char sub[20];
public:
  void getdata()
  {
    getd();
    cout<<"enter the subject\n";
    cin>>sub;
    get1();
  }
  void putdata()
  {
    putd();
    cout<<"sub         :"<<sub<<"\n";
    put1();
  }
}t1[30];
class typist:public staff
{
  int speed;
public:
  void get2()
  {
    getd();
    cout<<"enter speed : words per min\n";
    cin>>speed;
  }
  void put2()
  {
    putd();
    cout<<"speed is :(words per min is)"<<speed<<"\n";
  }

}tp1;
class officer:public staff,public education
{
  char grade;
public:
  void getdata()
  {
    getd();
    cout<<"enter the grade\n";
    cin>>grade;
    get1();
  }
  void putdata()
  {
    putd();
    cout<<"the officer grade is :"<<grade<<"\n";
    put1();
  }
}o1[30];
class regular:public typist
{
  int salary;
public:
  void getdata()
  {
    get2();
    cout<<"enter salary\n";
    cin>>salary;
  }
  void putdata()
  {
    put2();
    cout<<"salry is :"<<salary<<"\n";
  }
}r1[30];
class casual:public typist
{
  int dailywage;
public:
  void getdata()
  {
    get2();
    cout<<"enter the daily wage\n";
    cin>>dailywage;
  }
  void putdata()
  {
    put2();
    cout<<"the daily wage :"<<dailywage;
  }
}c1[30];
main()
{
  int ch[30],ab[30],n,i,op=1,y;
  cout<<"enter the num of staff \n";
  cin>>n;
  for(i=0;i<n;i++)
    {
      cout<<"enter the staff details\n1.teacher\n2.typist\n3.officer\n";
      cin>>ch[i];
      if(ch[i]==1)
	{
	  t1[i].getdata();
	}
      if(ch[i]==2)
	{
	  cout<<"enter choice\n 1.casual\n 2.regular\n";
	  cin>>ab[i];
	  if(ab[i]==1)
	    {
	      c1[i].getdata();
	    }
	  if(ab[i]==2)
	    {
	      r1[i].getdata();
	    }
	}
      if(ch[i]==3)
	{
	  o1[i].getdata();
	}
	}
  cout<<"\n\n";
  cout<<"           the staff details are            \n\n";
  cout<<"the details of teachers are \n";
  for(i=0;i<n;i++)
    {
      if(ch[i]==1)
	{
	  t1[i].putdata();
	  cout<<"--------------------------------------\n";
	}
    }
  cout<<"the details of typist are\n";
  for(i=0;i<n;i++)
    {
      if(ch[i]==2)
	{
	  if(ab[i]==1)
	    {
	      c1[i].putdata();
	    }
	  if(ab[i]==2)
	    {
	      r1[i].putdata();
	    }
	  cout<<"-----------------------------------\n";
	}
    }
  cout<<"the details of officers are\n";
  for(i=0;i<n;i++)
    {
      if(ch[i]==3)
	{
	  o1[i].putdata();
	  cout<<"----------------------------------------\n";
	}
    }

}


-------------------------------OUTPUT---------------------------------------


enter the num of staff 
5
enter the staff details
1.teacher
2.typist
3.officer
1
enter name
dru
etner code
1
enter the subject
maths
enter the qualification in general
ba
enter the highest professional qualification
ma
enter the staff details
1.teacher
2.typist
3.officer
2
enter choice
 1.casual
 2.regular
1
enter name
anna
etner code
2
enter speed : words per min
24
enter the daily wage
150
enter the staff details
1.teacher
2.typist
3.officer
3
enter name
dinku
etner code
3
enter the grade
a
enter the qualification in general
bsc
enter the highest professional qualification
mscx
enter the staff details
1.teacher
2.typist
3.officer
1
enter name
lakshmi
etner code
4
enter the subject
eng
enter the qualification in general
ba
enter the highest professional qualification
ma
enter the staff details
1.teacher
2.typist
3.officer
3
enter name
alphy
etner code
5
enter the grade
b
enter the qualification in general
bsc
enter the highest professional qualification
msc


           the staff details are            

the details of teachers are 
name      :dru
code      :1
sub         :maths
highest qualification is :ba
proffesional qualification is  :ma
--------------------------------------
name      :lakshmi
code      :4
sub         :eng
highest qualification is :ba
proffesional qualification is  :ma
--------------------------------------
the details of typist are
name      :anna
code      :2
speed is :(words per min is)24
the daily wage :150
-----------------------------------
the details of officers are
name      :dinku
code      :3
the officer grade is :a
highest qualification is :bsc
proffesional qualification is  :msc
----------------------------------------
name      :alphy
code      :5
the officer grade is :b
highest qualification is :bsc
proffesional qualification is  :msc
----------------------------------------

























































































