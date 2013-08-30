#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;
class a
{
  char st[30];
public:
  void getdata()
  {
    cout<<"enter the string\n";
    gets(st);
  }
  void putdata()
  {
    puts(st);
  }
  void operator +(a a1)
  {
    strcat(st,a1.st);
 
  }
  void operator =(a a1)
  {
    strcpy(st,a1.st);
    puts(st);
  }
  void operator -(a a1)
  {
    int i,l,j,p,m,n;
    l=strlen(st);
    p=strlen(a1.st);
    for(i=0;i<l;i++)
      {
	for(j=0;j<p;j++)
	  {
	    if(st[i]==a1.st[j])
	      {
		for(m=i;m<l;m++)
		  {
		    st[m]=st[m+1];
		  }
		l--;
		/*	for(n=j;n<p;n++)
		  {
		    a1.st[n]=a1.st[n+1];
		  }
		  p--;*/
	      }
	  }
      }
  }
};
main()
{
  int ch=1,op;
  a a2,a3;
  while(ch==1)
    {
  a2.getdata();
  a3.getdata();
  cout<<"1.addition 2.subtraction 3.copy\n";
  cin>>op;
  if(op==1)
    {
  a2+a3;
  cout<<"addition of string\n";
    a2.putdata();
    }
  if(op==2)
    {
  a2-a3;
  cout<<"subtraction of strings give\n";
  a2.putdata();
    }
  if(op==3)
    {
cout<<"equating two strings give\n";
 a2=a3;
    }
  printf("1.continue 2.exit\n");
  scanf("%d",&ch);
    }
}
