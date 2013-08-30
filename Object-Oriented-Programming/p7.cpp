#include<iostream>
using namespace std;
void swap1(int,int);
void swap2(int&,int&);
void swap3(int *a,int *b)
{
  int t;
  t=*a;
  *a=*b;
  *b=t;
}
main()
{
  int a,b;
  cout<<"enter the value in a\n";
  cin>>a;
  cout<<"enter the value in b\n";
  cin>>b;
  swap1(a,b);
  cout<<"values after call by value are :a="<<a<<" and b ="<<b<<"\n"; 
  swap2(a,b);
  cout<<"values after call by reference are a="<<a<<" and b="<<b<<"\n";
  swap3(&a,&b);
  cout<<"values after call by address are:a="<<a<<"and b="<<b<<"\n";
}
void swap1(int c,int d)
{
  int t;
  t=c;
  c=d;
  d=t;
}
void swap2(int &e,int &f)
{
  int t;
  t=e;
  e=f;
  f=t;
} 
