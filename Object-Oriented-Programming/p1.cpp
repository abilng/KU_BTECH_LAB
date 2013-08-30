#include<iostream>
using namespace std;
class employee
{
public:
  char empname[20];
  int empcode;
  float bsal;
  float hra;
  float da;
  float tot;
  void getdata()
  {
    cout<<"enter name\n";
    cin>>empname;
    cout<<"enter employee code\n";
    cin>>empcode;
    cout<<"enter basic salary\n";
    cin>>bsal;
  }
  void totsalary()
  {
    hra=200;
    da=0.6*bsal;
    tot=bsal+hra+da;
  }
  void putdata()
  {
    cout<<empname<<"        "<<empcode<<"     "<<tot<<"\n";
  }
}e[20],t;
main()
{
  int n,i,j;
  cout<<"enter the num of employees"<<"\n";
  cin>>n;
  for(i=0;i<n;i++)
    {
  e[i].getdata();
  e[i].totsalary();
    }
  for(i=0;i<n;i++)
    {
      for(j=i+1;j<n;j++)
	{
	  if(e[i].tot<e[j].tot)
	    {
	      t=e[i];
	      e[i]=e[j];
	      e[j]=t;
	    }
	}
    }
  cout<<"sorted list is"<<"\n";
  cout<<"NAME    "<<"code   "<<"total salary\n";
  for(i=0;i<n;i++)
    {
      e[i].putdata();
      cout<<"\n";
    }

}
