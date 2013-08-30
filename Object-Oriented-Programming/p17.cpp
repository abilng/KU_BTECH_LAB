#include<iostream>
#include<stdio.h>
using namespace std;
class add
{
public:
  int x;
  add()
  {
    x=5;
  }
  void getdata()
  {
    cout<<"enter the value of x\n";
    cin>>x;
  }
  add operator++(int)
  {
    x++;
    return (*this);
    
  }
  add operator++()
  {
    add f;
    f.x=x;
    x++;
    return f;
  }
  add operator--(int)
  {
   x=x--;
   return (*this);
  }
  add operator--()
  {
    add f;
    f.x=x;
    x--;
    return f;
  }
  void putdata()
  {
    cout<<"x :"<<x<<"\n";
  }
  int operator+(add b)
  {
   
    x=x+b.x;
    return x;
  }
  int operator-(add c)
  {
    x=x-c.x;
    return x;
  }
}a1,a2;
main()
{
  int op=1,c,ch;
  while(op==1)
    {
      cout<<"enter choice 1.++x + x++\n2.--x -x--\n3.x++ -x--\n";
      cin>>ch;
      if(ch==1)
	{
	  a1.getdata();
	  c=++a1+a1++;
	  cout<<c;
	}
      if(ch==2)
	{
	  a1.getdata();
	  c=--a1-a1--;
	  cout<<c;
	}
      if(ch==3)
	{
	  a1.getdata();
	  c=++a1-a1--;
	  cout<<c;
	}
      cout<<"\n";
      cout<<"1.continue 2.exit\n";
      cin>>op;
	}

}

----------------------------------output------------------------------------------------


enter choice 1.++x + x++
2.--x -x--
3.x++ -x--
1
enter the value of x
3
8
1.continue 2.exit
1
enter choice 1.++x + x++
2.--x -x--
3.x++ -x--
2
enter the value of x
3
0
1.continue 2.exit
1
enter choice 1.++x + x++
2.--x -x--
3.x++ -x--
3
enter the value of x
4
0
1.continue 2.exit
2

----------------------------------------------------------------------------------------























































