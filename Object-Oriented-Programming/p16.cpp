
#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;
class person
{
protected:
  char name[20];
  int code;
};
class account:virtual public person
{
protected:
  int pay;
};
class admin:virtual public  person
{
protected:
  int exp;
};
class master: virtual public account,virtual public admin
{
public:
  void getdata()
  {
    cout<<"enter name\n";
    cin>>name;
    cout<<"enter code\n";
    cin>>code;
    cout<<"enter pay\n";
    cin>>pay;
    cout<<"enter experience\n";
    cin>>exp;
  }
  void putdata()
  {
    cout<<"name is       :"<<name<<"\n";
    cout<<"code is       :"<<code<<"\n";
    cout<<"pay is        :"<<pay<<"\n";
    cout<<"experience is :"<<exp<<"\n";
  }
  void friend update();
}m[20],m2;
void update()
{
  int num,ch,n1,c1,p1,e1;
  cout<<"enter the employee whose data is to be modified\n";
  cin>>num;
  cout<<"enter choice for updating 1.name 2.code 3.pay 4.experience\n";
  cin>>ch;
  if(ch==1)
    {
      cout<<"enter new name\n";
      cin>>m[num].name;
     
    }
  if(ch==2)
    {
      cout<<"enter new code\n";
      cin>>c1;
      m[num].code=c1;
    }
  if(ch==3)
    {
      cout<<"enter new pay\n";
      cin>>p1;
      m[num].pay=p1;
    }
  if(ch==4)
    {
      cout<<"enter new experience\n";
      cin>>e1;
      m[num].exp=e1;
    }
}
main()
{
  int op,i,n;
  cout<<"enter number of employees\n";
  cin>>n;
  for(i=1;i<=n;i++)
    {
      cout<<"enter detail num"<<i+1<<"\n";
      m[i].getdata();
    }
  cout<<"do you want to update any content ???\n 1.yes 2.exit\n";
  cin>>op;
  while(op==1)
    {
      update();
      cout<<"do you want to continue updating \n1.yes 2.exit";
      cin>>op;
    }
  cout<<"employee details are\n";
  for(i=1;i<=n;i++)
    {
      m[i].putdata();
    }
}

------------------------------------------------------------output---------------------------------------------------------------------


enter number of employees
3
enter detail num2
enter name
dinku
enter code
1
enter pay
3000
enter experience
3
enter detail num3
enter name
lak
enter code
2
enter pay
2000
enter experience
2
enter detail num4
enter name
anna
enter code
3
enter pay
5000
enter experience
4
do you want to update any content ???
 1.yes 2.exit
1
enter the employee whose data is to be modified
1
enter choice for updating 1.name 2.code 3.pay 4.experience
2
enter new code
5
do you want to continue updating 
1.yes 2.exit1
enter the employee whose data is to be modified
2
enter choice for updating 1.name 2.code 3.pay 4.experience
3
enter new pay
2500
do you want to continue updating 
1.yes 2.exit1
enter the employee whose data is to be modified
3
enter choice for updating 1.name 2.code 3.pay 4.experience
4
enter new experience
5
do you want to continue updating 
1.yes 2.exit2
employee details are
name is       :dinku
code is       :5
pay is        :3000
experience is :3
name is       :lak
code is       :2
pay is        :2500
experience is :2
name is       :anna
code is       :3
pay is        :5000
experience is :5

-----------------------------------------------------------------------------------------------------------------------







































































