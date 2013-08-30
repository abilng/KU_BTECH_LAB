#include<iostream>
#include<stdio.h>
using namespace std;
class stack
{
public:
  int a[20],top;
  stack()
  {
    top=-1;
  }
  ~stack()
  {
  }
  stack(stack &s)
  {
    top=s.top;
    int i;
    for(i=top;i>=0;i--)
      {
	a[i]=s.a[i];
      }
  }
  void push()
  {
    top++;
    int item,t;
    t=isfull(a);
    if(t==0)
      {
	cout<<"stack is full\n";
      }
    else
      {
    cout<<"enter item\n";
    cin>>item;
    a[top]=item;
      }
  }
  void pop()
  {
    int t;
    t=isempty(a);
    if(t==0)
      {
	cout<<"stack is empty\n";
      }
    else
      {
    int item;
    item=a[top];
    cout<<item<<"\n";
    top--;
      }
  }
 int isempty(int b[])
  {
    if(top==-1)
      {
	cout<<"stack is empty\n";
	return 0;
       
      }
    else
      {
	return 1;
      }

  }
  int isfull(int b[])
  {
    if(top==19)
      {
	cout<<"stack is full\n";
	return 0;
    
      }
    else
      {
	cout<<"stack is not full\n";
	return 1;
      }
  }
  void size()
  {
    cout<<"size is"<<top+1<<"\n";
  }
  void print(int b[])
  {
    int i;
    for(i=0;i<=top;i++)
      {
	cout<<a[i]<<"\n";
      }
  }
    void ispal()
    {
      int i,j,f=0;
      j=top;
      for(i=0,j=top;i<top/2;i++,j--)
	{
	  if(a[i]!=a[j])
	    {
	      f=1;
	    }
	}
      if(f==1)
	{
	  cout<<"not a palindrome\n";
	}
      else cout<<"it is a palindrome\n";
  }
  friend void merge();
}st[20];

void merge()
{ 
       stack s3,s4,s5;
      int u=1,v=1,c=0,d=0;
      cout<<"stack1\n";
      while(u==1)
	{
	  s3.push();
	  c++;
	  cout<<"1.push more 2.exit\n";
	  cin>>u;
	}
      cout<<"stack 2\n";
      while(v==1)
	{
	  s4.push();
	  d++;
	  cout<<"1.push more 2.exit\n";
	  cin>>v;
	}
      cout<<"stack 1 is\n";
      s3.print(s3.a);
      cout<<"stack 2 is\n";
      s4.print(s4.a);
      s5=s3;
      int i=0;
      while(d>0)
	{
	  s5.top++;
	  s5.a[s5.top]=s4.a[i];
	  i++;
	  d--;
	}
      cout<<"stack after addition is\n";

      s5.print(s5.a);
}

main()
{
  int ch,op=1,c=0;
  char a;
  while(op==1)
    {
      cout<<"enter choice\n1.reverse\n2.palindrome\n3.addition\n";
  cin>>ch;
  if(ch==1)
    {
      int u=1;
      stack s1;
      while(u==1)
	{
	 s1.push();
	 c++;
	  cout<<"1.to enter more 2.exit\n";
	  cin>>u;
	}
      cout<<"the stack is\n";
     s1.print(s1.a);
     cout<<"reversed string is\n";
      while(c>0)
	{
	 s1.pop();
	  c--;
	}

    }
  if(ch==2)
    {
      int u=1,c=0;
      stack s2;
      while(u==1)
	{
	  s2.push();
	  c++;
	  cout<<"1.enter more 2.exut\n";
	  cin>>u;
	}
      cout<<"the stack is\n";
      s2.print(s2.a);
      s2.ispal();
    }
  if(ch==3)
    {
      merge();
    }
      cout<<"1.continue 2.exit\n";
      cin>>op;
    }
}
----------------------------------OUTPUT---------------------------------------------



enter choice
1.reverse
2.palindrome
3.addition
1
stack is not full
enter item
1
1.to enter more 2.exit
1
stack is not full
enter item
2
1.to enter more 2.exit
1
stack is not full
enter item
3
1.to enter more 2.exit
1
stack is not full
enter item
4
1.to enter more 2.exit
1
stack is not full
enter item
5
1.to enter more 2.exit
2
the stack is
1
2
3
4
5
reversed string is
5
4
3
2
1
1.continue 2.exit
1
enter choice
1.reverse
2.palindrome
3.addition
2
stack is not full
enter item
1
1.enter more 2.exut
1
stack is not full
enter item
2
1.enter more 2.exut
1
stack is not full
enter item
3
1.enter more 2.exut
1
stack is not full
enter item
2
1.enter more 2.exut
1
stack is not full
enter item
1
1.enter more 2.exut
2
the stack is
1
2
3
2
1
it is a palindrome
1.continue 2.exit
1
enter choice
1.reverse
2.palindrome
3.addition
2
stack is not full
enter item
1
1.enter more 2.exut
1
stack is not full
enter item
2
1.enter more 2.exut
1
stack is not full
enter item
3
1.enter more 2.exut
2
the stack is
1
2
3
not a palindrome
1.continue 2.exit
1
enter choice
1.reverse
2.palindrome
3.addition
3
stack1
stack is not full
enter item
1
1.push more 2.exit
1
stack is not full
enter item
2
1.push more 2.exit
1
stack is not full
enter item
3
1.push more 2.exit
1
stack is not full
enter item
4
1.push more 2.exit
2
stack 2
stack is not full
enter item
5
1.push more 2.exit
1
stack is not full
enter item
6
1.push more 2.exit
1
stack is not full
enter item
7
1.push more 2.exit
1
stack is not full
enter item
8
1.push more 2.exit
2
stack 1 is
1
2
3
4
stack 2 is
5
6
7
8
stack after addition is
1
2
3
4
5
6
7
8
1.continue 2.exit
2
-----------------------------------------------------------------------------------








































































