#include<iostream>
using namespace std;
class a
{
  int h;
  int m;
  int s,j,k,i,q,w,e;
public:
  void getdata()
  {
    cout<<"enter hour minute and seconds";
    cin>>h>>m>>s;
  }
  void putdata()
  {
    cout<<i<<"hr  "<<j<<" min "<<k<<" sec\n";
  }
  void operator +(a c1)
  {
    
    i=h+c1.h;
    j=m+c1.m;
    k=s+c1.s;
    q=(k/60);
    k=(k%60);
    j=j+q;
    w=(j/60);
    j=(j%60);
    i=i+w;
    i=(i%12);
    if(i==0)
      {
	i=12;
      }
 }
  
};
main()
{
  a a1,a2,a3;
  a1.getdata();
  a2.getdata();
  a1+a2;
  a1.putdata();
}
