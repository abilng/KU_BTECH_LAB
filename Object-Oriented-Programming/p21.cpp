#include<iostream>
#include<fstream>
#include<stdio.h>
using namespace std;
struct stud
{
  char name[20];
  int rno;
  int m[3];
}s[20];
main()
{
  fstream f1,f2;
  f1.open("mark.dat",ios::in|ios::out|ios::binary);
  int n;
  cout<<"enter number of students\n";
  cin>>n;
  for(int i=0;i<n;i++)
    {
      cout<<"enter name \n";
      cin>>s[i].name;
      f1<<s[i].name;
      cout<<"enter roll num\n";
      cin>>s[i].rno;
      f1<<s[i].rno;
      cout<<"enter marks\n";
      cin>>s[i].m[0]>>s[i].m[1]>>s[i].m[2];
      f1<<s[i].m[0]<<s[i].m[1]<<s[i].m[2];
    }
}
