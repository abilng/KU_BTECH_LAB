#include<iostream>
using namespace std;
template<class t>
class stack
{
  t a[30];
  int top;
public:
    stack()
  {
    top=-1;
    }
  void push()
  {
    t item;
    if(top==29)
      {
	cout<<"stack overflow\n";
      }
    else
      {
	cout<<"enter the element\n";
	cin>>item;
	top++;
	a[top]=item;
      }
  }
  void pop()
  {
     t ele;
    if(top==-1)
      {
	cout<<"stack empty\n";
      }
    else
      {
	ele=a[top];
	cout<<"the popped value is"<<ele<<"\n";
	top--;
      }
  }
  void display()
  {
    cout<<"the elements of the stack are\n";
    for(int i=0;i<=top;i++)
      {
	cout<<a[i]<<"\n";
      }
  }
};
main()
{
  int ch=0,op=1,ab,xy;
  while(op==1)
    {
      cout<<"enter choice\n1.integer\n2.character\n3.float\n";
      cin>>ch;
      xy=1;
      if(ch==1)
	{
	  stack <int>a1;
	  while(xy==1)
	    {
	  cout<<"enter coice 1.push 2.pop 3.display\n";
	  cin>>ab;
	  if(ab==1)
	    {
	      a1.push();
	    }
	  if(ab==2)
	    {
	      a1.pop();
	    }
	  if(ab==3)
	    {
	      a1.display();
	    }
	  cout<<"1.continue 2.exit\n";
	  cin>>xy;
	    }
	}
      if(ch==2)
	{
	  stack <char>b1;
	  while(xy==1)
	    {
	  cout<<"enter coice 1.push 2.pop 3.display\n";
	  cin>>ab;
	  if(ab==1)
	    {
	      b1.push();
	    }
	  if(ab==2)
	    {
	      b1.pop();
	    }
	  if(ab==3)
	    {
	      b1.display();
	    }
	  cout<<"1.continue 2.exit\n";
	  cin>>xy;
	    }
	}
      if(ch==3)
	{
	  stack <float>c1;
	  while(xy==1)
	    {
	  cout<<"enter coice 1.push 2.pop 3.display\n";
	  cin>>ab;
	  if(ab==1)
	    {
	      c1.push();
	    }
	  if(ab==2)
	    {
	      c1.pop();
	    }
	  if(ab==3)
	    {
	      c1.display();
	    }
	  cout<<"1.continue 2.exit\n";
	  cin>>xy;
	    }
	}
      cout<<"do you want to continue with a diff stack??\n1.yes\n2.no\n";
      cin>>op;
    }
}
/*
-----------------------------------------OUTPUT----------------------------------------


enter choice
1.integer
2.character
3.float
1
enter coice 1.push 2.pop 3.display
1
enter the element
1
1.continue 2.exit
1
enter coice 1.push 2.pop 3.display
1
enter the element
2
1.continue 2.exit
1
enter coice 1.push 2.pop 3.display
1
enter the element
3
1.continue 2.exit
1
enter coice 1.push 2.pop 3.display
1
enter the element
4
1.continue 2.exit
1
enter coice 1.push 2.pop 3.display
3
the elements of the stack are
1
2
3
4
1.continue 2.exit
1
enter coice 1.push 2.pop 3.display
2
the popped value is4
1.continue 2.exit
1
enter coice 1.push 2.pop 3.display
2
the popped value is3
1.continue 2.exit
1
enter coice 1.push 2.pop 3.display
2
the popped value is2
1.continue 2.exit
1
enter coice 1.push 2.pop 3.display
2
the popped value is1
1.continue 2.exit
1
enter coice 1.push 2.pop 3.display
2
stack empty
1.continue 2.exit
1
enter coice 1.push 2.pop 3.display
1
enter the element
6
1.continue 2.exit
1
enter coice 1.push 2.pop 3.display
3
the elements of the stack are
6
1.continue 2.exit
2
do you want to continue with a diff stack??
1.yes
2.no
1
enter choice
1.integer
2.character
3.float
2
enter coice 1.push 2.pop 3.display
1
enter the element
d
1.continue 2.exit
1
enter coice 1.push 2.pop 3.display
1
enter the element
r
1.continue 2.exit
1
enter coice 1.push 2.pop 3.display
1
enter the element
u
1.continue 2.exit
1
enter coice 1.push 2.pop 3.display
1
enter the element
s
1.continue 2.exit
1
enter coice 1.push 2.pop 3.display
1
enter the element
y
1.continue 2.exit
1
enter coice 1.push 2.pop 3.display
1
enter the element
a
1.continue 2.exit
1
enter coice 1.push 2.pop 3.display
3
the elements of the stack are
d
r
u
s
y
a
1.continue 2.exit
1
enter coice 1.push 2.pop 3.display
2
the popped value isa
1.continue 2.exit
1
enter coice 1.push 2.pop 3.display
2
the popped value isy
1.continue 2.exit
2
enter coice 1.push 2.pop 3.display
3
the elements of the stack are
d
r
u
s
1.continue 2.exit
1
do you want to continue with a diff stack??
1.yes
2.no
1
enter choice
1.integer
2.character
3.float
3
enter coice 1.push 2.pop 3.display
1
enter the element
1.2
1.continue 2.exit
1
enter coice 1.push 2.pop 3.display
1
enter the element
2.2
1.continue 2.exit
1
enter coice 1.push 2.pop 3.display
1
enter the element
3.4
1.continue 2.exit
1
enter coice 1.push 2.pop 3.display
3
the elements of the stack are
1.2
2.2
3.4
1.continue 2.exit
1
enter coice 1.push 2.pop 3.display
2
the popped value is3.4
1.continue 2.exit
2
do you want to continue with a diff stack??
1.yes
2.no
2


----------------------------------------------------------------------------------
*/








































































