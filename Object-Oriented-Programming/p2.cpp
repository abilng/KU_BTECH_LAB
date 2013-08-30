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
  complex operator *(complex c7)
  {
    complex c9;
    c9.real=(real*c7.real)-(imag*c7.imag);
    c9.imag=(real*c7.imag)+(imag*c7.real);
      return c9;
  }
  /* complex operator /(complex c10,complex c11)
  {
    complex c12;
    c12.real=((c10.real*c11.real)+(c10.imag*c11.imag))/((c11.real*c11.real)-(c11.imag*c11.imag));
    c12.imag=((c10.real*c11.real)-(c10.imag*c11.imag))/((c11.real*c11.real)-(c11.imag*c11.imag));
    return c12;
    }*/
};
main()
{
  complex com1,com2,com3,com4,com5;
  int ch;
  cout<<"enter choice 1.addition 2.subtraction 3.multiplication\n";
  cin>>ch;
  com1.getdata();
  com2.getdata();
  if(ch==1)
    {
  com3=com1+com2;
  cout<<"the sum is\n";
  com3.putdata();
    }
  if(ch==2)
    {
  com4=com1-com2;
  cout<<"the difference is\n";
  com4.putdata();
    }
  if(ch==3)
    {
  com5=com1*com2;
  cout<<"the product is\n";
  com5.putdata();
}
}
