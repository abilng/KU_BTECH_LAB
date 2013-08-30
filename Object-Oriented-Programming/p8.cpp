#include<iostream>
using namespace std;
class complex
{
  int real;
  int imag;
public:
  void getdata()
  {
    cout<<"enter real and imag part";
    cin>>real>>imag;
  }
  void putdata()
  {
    cout<<real<<"+"<<imag<<"i\n";
  }
  complex operator +(complex c1)
  {
    complex c3;
    c3.real=c1.real+real;
    c3.imag=c1.imag+imag;
    return c3;
  }
  complex operator -(complex c4)
  {
    complex c6;
    c6.real=real-c4.real;
    c6.imag=imag-c4.imag;
    return c6;
  }
 void sum(complex c7)
  {
    real=real+c7.real;
    imag=imag+c7.imag;  
  }
  void sub(complex c2)
  {
    real=real-c2.real;
    imag=imag-c2.imag;
  }
  complex sum1(complex c9)
  {
    real=real+c9.real;
    imag=imag+c9.imag;
    return (*this);
  }
  complex sub2(complex c4)
  {
    real=real-c4.real;
    imag=imag-c4.imag;
    return (*this);
  }
};
main()
{
  complex com1,com2,com3,com4,com5;
  int ch,op=1,ab,q;
  while(op==1)
    {
  cout<<"enter choice 1.addition 2.subtraction\n";
  cin>>ch;
  cout<<"enter choice\n 1.return value\n 2.without return value\n 3.using this pointer\n";
  cin>>ab;
  com1.getdata();
  com2.getdata();
  if(ch==1)
    {
      if(ab==1)
	{
  com3=com1+com2;
  cout<<"the sum is\n";
  com3.putdata();
    }
  if(ab==2)
    {
      com1.sum(com2);
  cout<<"the sum is\n";
  com1.putdata();
    }
  if(ab==3)
    {
      com1.sum1(com2);
      cout<<"the sum is\n";
      com1.putdata();
    }
    }
  if(ch==2)
    {
      if(ab==1)
	{
      com4=com1-com2;
      cout<<"the difference is\n";
      com4.putdata();
    }
  if(ab==2)
    {
      com1.sub(com2);
      cout<<"the difference is\n";
      com1.putdata();
    }
  if(ab==3)
    {
      com1.sub2(com2);
      cout<<"the diff is\n";
      com1.putdata();
    }
    }
  cout<<"1.continue 2.exit\n";
  cin>>op;
}
}
