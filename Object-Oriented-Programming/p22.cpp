#include<iostream>
#include<cstring>
using namespace std;

class stack
{
  //int a[20];
  int top;
public:
  int a[20];
  stack() { top = -1; }
  stack(stack &s)
  {
    top = s.top;
    int i=0;
    for(i=0;i<s.top;i++)
      a[i]=s.a[i];
  }
  ~stack(){}
  void push(int);
  int pop();
  int isempty();
  int isfull();
  int sizeof_();
  void print();
  void cdisplay();
  void display();
  friend stack add(stack,stack);
};

int stack::isempty()
{
  if(top<0)
    return 1;
  else
    return 0;
}

int stack::isfull()
{
  if(top>=20)
    return 1;
  else 
    return 0;
}

int stack::sizeof_()
{
  return top-1;
}

void stack::push(int d)
{
  if(top==-1) top=0;
  if(this->isfull())
    {
      cout<<"\nStack Full error ...!!!\n";
      return;
    }
  else
    {
      a[top]=d;
      top++;
    }
}

int stack::pop()
{
  if(this->isempty())
    {
      cout<<"\nStack Empty error ...!!!\n";
      return -1;
    }
  else
    {
      int p = a[top];
      top--;
      return p;
    }
}

void stack::print()
{
  cout<<"\nStack : ";
  int i = 0;
  for(i=0;i<top;i++)
    {
      cout<<a[i]<<" - ";
    }
}

char* reverse(char a[])
{
  stack b;
  int i;
  char c;
  const int len = strlen(a);
  char *p;
  p=new char[len];
  for(i=0;i<len;i++)
    {
      b.push(int(a[i]));
    }
  i = 0;
  b.pop();
  while(1)
    {
      char c = char(b.pop());
      p[i]=c;
      i++;
      if(b.isempty())
	break;
    }

  return p;
}

int checkpal(char a[])
{
  const int len = strlen(a);
  char *b;
  b = reverse(a);
  for(int i=0;i<len;i++)
    {
      if(b[i]!=a[i])
	return 0;
    }
  return 1;
 
}

stack add(stack a,stack b)
{
  stack c(a);
  for(int i=0;i<b.top;i++)
    c.push(b.a[i]);
  return c;
}

void stack::cdisplay()
{
  int i;
  char c;
  cout<<"\n Stack ... : ";
  for(i=0;i<top;i++)
    {
      c = char(a[i]);
      cout<<c<<" ";
    }
}
void stack::display()
{
  int i;
  cout<<"\nStack ... : ";
  for(i=0;i<top;i++)
    {
      cout<<a[i]<<" ";
    }
}
      

main()
{
  stack s1,s2,sum;
  int ch,ch2,d,k,val;
  char y = 'y',pa = 'y',str[20],a[20],b[20],*t;
  while(y == 'y'||y == 'Y')
    {
      cout<<"\n1 >>> Reverse string\t2 >>> Check Palindrome";
      cout<<"\n3 >>> add two stacks \nEnter choice : ";
      cin>>ch;
      switch(ch)
	{
	case 1:cout<<"\nEnter the string : ";
	  cin>>str;
	  t = reverse(str);
	  cout<<"\nReversed string : "<<t;
	  break;
	case 2:cout<<"\nEnter the string : ";
	  cin>>str;
	  if(checkpal(str))
	    cout<<"\n string is a palindrome\n";
	  else
	    cout<<"\n string is not a palindrome\n";
	  break;
	case 3:cout<<"\n 1>>> Character stack\t2>>>Integer stack";
	  cout<<"\nChoice ? (1/2) : ";
	  cin>>ch2;
	  if(ch2 == 1)
	    {
	      cout<<"\nEnter the input stack 1 : ";
	      cin>>a;
	      cout<<"\nEnter the input stack 2 : ";
	      cin>>b;
	      int i;
	      for(i=0;i<strlen(a);i++) 
		  s1.push(int(a[i]));
		
	      for(i=0;i<strlen(b);i++)
		  s2.push(int(b[i]));
	      sum=add(s1,s2);
	      sum.cdisplay();
	    }
	  if(ch2 == 2)
	    {
	      cout<<"\nEnter stack 1 contents ... \n";
	      while(pa == 'y'||pa == 'Y')
		{
		  cout<<"Value : ";
		  cin>>val;
		  s1.push(val);
		  cout<<"\nPush again ? (y/n) : ";
		  cin>>pa;
		}
	      cout<<"\nEnter stack 2 contents ...\n";
	      pa = 'y';
	      while(pa == 'y'||pa == 'Y')
		{
		  cout<<"Value : ";
		  cin>>val;
		  s2.push(val);
		  cout<<"\nPush again ? (y/n) : ";
		  cin>>pa;
		}
	      sum = add(s1,s2);
	      sum.display();
	    }
	  break; 
	  
	default:cout<<"\nInvalid Input ...!!! \n";
	  break;
	}
      cout<<"\nContinue ? (y/n) : ";
      cin>>y;
    }
}


-----------------------------------------------output---------------------------------------------------



1 >>> Reverse string	2 >>> Check Palindrome
3 >>> add two stacks 
Enter choice : 1

Enter the string : drusya

Reversed string : aysurd
Continue ? (y/n) : y

1 >>> Reverse string	2 >>> Check Palindrome
3 >>> add two stacks 
Enter choice : 1

Enter the string : 1234

Reversed string : 4321
Continue ? (y/n) : y

1 >>> Reverse string	2 >>> Check Palindrome
3 >>> add two stacks 
Enter choice : 2

Enter the string : malayalam

 string is a palindrome

Continue ? (y/n) : y

1 >>> Reverse string	2 >>> Check Palindrome
3 >>> add two stacks 
Enter choice : 2

Enter the string : drusya

 string is not a palindrome

Continue ? (y/n) : y

1 >>> Reverse string	2 >>> Check Palindrome
3 >>> add two stacks 
Enter choice : 3

 1>>> Character stack	2>>>Integer stack
Choice ? (1/2) : 1

Enter the input stack 1 : drusya

Enter the input stack 2 : vijayan

 Stack ... : d r u s y a v i j a y a n 
Continue ? (y/n) : n

----------------------------------------------------------------------------------------------------------
