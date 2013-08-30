#include<iostream>
using namespace std;
class mat
{
  int a[20][20],i,j,m,n,k,p[20][20];
public:
  void getdata()
  {
    cout<<"enter the size of the matrix"<<"\n";
    cin>>m>>n;
    cout<<"enter the matrix"<<"\n";
    for(i=0;i<m;i++)
      {
	for(j=0;j<n;j++)
	  {
	    cin>>a[i][j];
	  }
      }
  }
  void putdata()
  {
    cout<<"the resulting matrix is"<<"\n";
    for(i=0;i<m;i++)
      {
	for(j=0;j<n;j++)
	  {
	    cout<<a[i][j]<<" ";
	  }
	cout<<"\n";
      }
  }
   void operator +(mat c1)
  {
    if(m==c1.m&&n==c1.n)
      {
    for(i=0;i<m;i++)
      {
	for(j=0;j<n;j++)
	  {
	    a[i][j]=a[i][j]+c1.a[i][j];
	  }
      }
    putdata();
      }
    else
      {
	cout<<"addition not possible\n";
      }
  }
  void operator -(mat c4)
  {
    if(m==c4.m&&n==c4.n)
      {
    for(i=0;i<m;i++)
      {
	for(j=0;j<n;j++)
	  {
	    a[i][j]=a[i][j]-c4.a[i][j];
	  }
      }
    putdata();
      }
    else
      {
	cout<<"subtraction not possible\n";
      }
  }
    void operator *(mat c7)
  {
if(n==c7.m)
{
    for(i=0;i<m;i++)
      {
	for(j=0;j<c7.n;j++)
	  {
	    p[i][j]=0;
	    for(k=0;k<n;k++)
	      {
		p[i][j]+=a[i][k]*c7.a[k][j];
	      }
	  }
      }
    for(i=0;i<m;i++)
      {
	for(j=0;j<c7.n;j++)
	  {
	    cout<<p[i][j]<<"  ";
	  }
	cout<<"\n";
      }
 }
 else
   {
     cout<<"multiplication is not possible\n";
   }
	}
};
main()
{
  mat m1,m2,m3;
  int ch,op=1;
  while(op==1)
    {
  cout<<"enter choice 1.addition 2.subtraction 3.multiplication\n";
  cin>>ch;
  m1.getdata();
  m2.getdata();
  if(ch==1)
    {
        m1+m2;
    }
   if(ch==2)
    {
      m1-m2;
    }
      if(ch==3)
    {
      m1*m2;
     
      }
      cout<<"do you want to continue 1.yes 2.no";
      cin>>op;
    }
}
