#include<iostream>
#include<string.h>
#include<stdio.h>
using namespace std;
class account
{
protected:
  char cname[20];
  int acno;
  char type[30];

}a1;
class current:public account
{
  int checkbook,p,bal,wt,as,ch,t,b,at;
public:
  current()
  {
    strcpy(type,"current");
  }
  void getdata()
  {
    cout<<"enter customer name\n";
    cin>>cname;
    cout<<"enter account num\n";
    cin>>acno;
  }
  void trat()
  {
    as=1;
  while(as==1)
      {
	cout<<"enter the transaction\n 1.deposit 2.withdrawal 3.checkbook\n";
	cin>>ch;
	if(ch==1)
	  {
	    cout<<"enter the amount to be deposited\n";
	    cin>>bal;
	    p=p+bal;
	    cout<<"the current balance is "<<p<<"\n";
	  }
	if(ch==2)
	  {
	    cout<<"enter the money to be withdrawn\n";
	    cin>>wt;
	    t=p-wt;
	    if(t<0)
	      {
		cout<<" insufficient balance\n";
	      }
	    else
	      {
		p=p-wt;
	      }
	    cout<<"the current balance is "<<p<<"\n";
	    if(p<500)
	      {
		cout<<" balnce is below min bal \n fine of Rs.250 imposed\n";
		p=p-250;
		cout<<"current balance is "<<p<<"\n";
	      }
	  }
	if(ch==3)
	  {
	    cout<<" 1.towards credit 2.from credit\n";
	    cin>>b;
	    cout<<" enter the amount \n";
	    cin>>at;
	    if(b==1)
	      {
		p=p+at;
		cout<<"the current balance is "<<p<<"\n";
	      }
	    if(b==2)
	      {
		t=p-at;
		if(t<0)
		  {
		    cout<<" insufficient balance\n";
		  }
		else
		  {
		    p=p-at;
		  }
		cout<<"the current balance is "<<p<<"\n";
		if(p<500)
		  {
		    cout<<" balnce is below min bal \n fine of Rs.250 imposed\n";
		    p=p-250;
		    cout<<"current balance is "<<p<<"\n";
		  }
	      }
	  }
	cout<<"do you want to continue 1.yes 2.no\n";
	cin>>as;
      }
  }
}c1;
class savings:public account
{
  int ch,op;
  float rt,si,r,p,t,wt,bal;
public:
  savings()
  {
    p=0;
    strcpy(type,"savings");
  }
  void getdata()
  {
    cout<<"enter customer name\n";
    cin>>cname;
    cout<<"enter account num\n";
    cin>>acno;
  }
  void opt()
  {
    op=1;
    while(op==1)
      {
	cout<<"enter the transaction\n 1.deposit 2.withdrawal 3.simple interest\n";
	cin>>ch;
	if(ch==1)
	  {
	    cout<<"enter the amount to be deposited\n";
	    cin>>bal;
	    p=p+bal;
	    cout<<"the current balance is "<<p<<"\n";
	  }
	if(ch==2)
	  {
	    cout<<"enter the money to be withdrawn\n";
	    cin>>wt;
	    p=p-wt;
	    cout<<"the current balance is "<<p<<"\n";
	  }
	if(ch==3)
	  {
	    r=12;
	    cout<<"enter the number of days since the deposit was made\n";
	    cin>>t;
	    si=(p*(r/365)*t)/100;
	    cout<<"the interest at the end of "<<t<<"  days is "<<si<<"\n";
	    p=p+si;
	    cout<<"the current balance is "<<p<<"\n";
	  }
	cout<<"do you want to continue 1.yes 2.no\n";
	cin>>op;
      }
  }

}s1;
main()
{
  int i,ch,op=1;
  while(op==1)
    {
      cout<<"enter type of account\n 1.current\n 2.saving\n";
      cin>>ch;
      if(ch==1)
	{
	  c1.getdata();
	  c1.trat();
	}
      if(ch==2)
	{
	  s1.getdata();
	  s1.opt();
	}
      cout<<"do you want to continue 1.yes 2.no\n";
      cin>>op;
    }
}

------------------------------------output-----------------------------------------------------

enter type of account
 1.current
 2.saving
1
enter customer name
dru
enter account num
123
enter the transaction
 1.deposit 2.withdrawal 3.checkbook
1
enter the amount to be deposited
2000
the current balance is 2000
do you want to continue 1.yes 2.no
1
enter the transaction
 1.deposit 2.withdrawal 3.checkbook
1
enter the amount to be deposited
1000
the current balance is 3000
do you want to continue 1.yes 2.no
1
enter the transaction
 1.deposit 2.withdrawal 3.checkbook
2
enter the money to be withdrawn
2600
the current balance is 400
 balnce is below min bal 
 fine of Rs.250 imposed
current balance is 150
do you want to continue 1.yes 2.no
1
enter the transaction
 1.deposit 2.withdrawal 3.checkbook
1
enter the amount to be deposited
1000
the current balance is 1150
do you want to continue 1.yes 2.no
1
enter the transaction
 1.deposit 2.withdrawal 3.checkbook
3
 1.towards credit 2.from credit
1
 enter the amount 
350
the current balance is 1500
do you want to continue 1.yes 2.no
1
enter the transaction
 1.deposit 2.withdrawal 3.checkbook
3
 1.towards credit 2.from credit
2
 enter the amount 
500
the current balance is 1000
do you want to continue 1.yes 2.no
2
do you want to continue 1.yes 2.no
1
enter type of account
 1.current
 2.saving
2
enter customer name
dinku
enter account num
324
enter the transaction
 1.deposit 2.withdrawal 3.simple interest
1
enter the amount to be deposited
3000
the current balance is 3000
do you want to continue 1.yes 2.no
1
enter the transaction
 1.deposit 2.withdrawal 3.simple interest
2
enter the money to be withdrawn
2000
the current balance is 1000
do you want to continue 1.yes 2.no
1
enter the transaction
 1.deposit 2.withdrawal 3.simple interest
1
enter the amount to be deposited
2000
the current balance is 3000
do you want to continue 1.yes 2.no
1
enter the transaction
 1.deposit 2.withdrawal 3.simple interest
3
enter the number of days since the deposit was made
30
the interest at the end of 30  days is 29.589
the current balance is 3029.59
do you want to continue 1.yes 2.no
2
do you want to continue 1.yes 2.no
2



---------------------------------------------------------------------------------------------














































































































