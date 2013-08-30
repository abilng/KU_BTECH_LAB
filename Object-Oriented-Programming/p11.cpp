#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;
class stud
{
  char n[40];
  int r,i;
  int m[5];
  char stat[30];
public:
  int t;
  void getdata()
  {
    strcpy(stat,"passed");
    cout<<"enter name\n";
    cin>>n;
    cout<<"enter num\n";
    cin>>r;
    for(i=0;i<5;i++)
      {
	cout<<"enter mark"<<i+1<<"out of 100\n";
	cin>>m[i];
	if(m[i]<40)
	  {
	    strcpy(stat,"failed");
	  }
      }
    t=m[0]+m[1]+m[2]+m[3]+m[4];
  }
  void putdata()
  {
    cout<<n<<"       ";
    cout<<r<<"         ";
    cout<<t<<"               ";
    cout<<stat<<"\n";
  }
}s[30],tp;
main()
{
  int ch,op=1,i,m,j;
  cout<<"enter num of students\n";
  cin>>m;
  cout<<"enter thr details\n";
  for(i=0;i<m;i++)
    {
      s[i].getdata();
    }
  for(i=0;i<m;i++)
    {
      for(j=i+1;j<m;j++)
	{
	  if(s[i].t<s[j].t)
	    {
	      tp=s[i];
	      s[i]=s[j];
	      s[j]=tp;
	    }
	}
    }
  cout<<"\n";
  cout<<" RANKLIST  \n";
  cout<<"rank      name       num       total marks      status\n";
  for(i=0;i<m;i++)
    {
      cout<<i+1<<"          ";
      s[i].putdata();
      cout<<"\n";
    }
}
