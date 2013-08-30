#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;
class a
{
  char b[20];
public:
  void getdata()
  {
    cout<<"enter the string        :";
    gets(b);
  }
  void putdata()
  {
    cout<<"string after concatination is:"<<"\n";
    puts(b);
  }
  void operator +(a a3)
  {
    a a4;
    strcat(b,a3.b); 
  }
};
main()
{
  a a1,a2;
  a1.getdata();
  a2.getdata();
  a1+a2;
  a1.putdata();
}
