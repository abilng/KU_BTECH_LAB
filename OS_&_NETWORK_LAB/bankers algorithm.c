#include<stdio.h>
#include<stdlib.h>
#include<semaphore.h>
#include<pthread.h>
#define false 0
#define true 1

int max[10][10],avail[10],need[10][10],allocate[10][10],request[10][10];
int work[10],finish[10];

int compare(int a[],int b[],int n)
{
  int i;
  for(i=0;i<n;i++)
    if(a[i]>b[i])return 0;
  return 1;
}

int main()
{
  int r,p,i,j,flag;
  printf("\nenter the no of resources :");
  scanf("%d",&r);
  printf("\nenter the no of processes :");
  scanf("%d",&p);
  for(i=0;i<p;i++)
    finish[i]=false;
  if(r<10 && p<10)
    {
      printf("\nenter the available instances for each resources");
      for(i=0;i<r;i++)
	{
	  printf("\nResource:%d ",i+1);
	  scanf("%d",&avail[i]);
	}
    }
  else
    {
    printf("\nsorry,max no of resources available is 10");
    exit(0);
    }
  //get resource requirment for each process
  for(i=0;i<p;i++)
    {
      for(j=0;j<r;j++)
	{
	  printf("\nEnter d Requirment of Resource %d for Process %d",j+1,i+1);
	  printf("\nMaximum :");
	  scanf("%d",&max[i][j]);
	  printf("\nAllocated :");
	  scanf("%d",&allocate[i][j]);
	  need[i][j]=max[i][j]-allocate[i][j];
	}
    }
  //check whether allocation is possible
  for(i=0;i<r;i++)
    work[i]=avail[i];
  for(i=0;i<p;i++)
    {
      if(finish[i]==false && compare(need[i],work,r))
	{
	  for(j=0;j<r;j++)
	    {
	      work[j]+=allocate[i][j];
	      allocate[i][j]=0;
	      finish[i]=true;
	      i=0;
	    }
	}
    }
      
  printf("\nneed matrix\n");
  for(i=0;i<p;i++)
    {
      for(j=0;j<r;j++)
	{
	  printf("%d ",need[i][j]);
	}
      printf("\n");
    }
  flag=0;
  for(i=0;i<p;i++)
    {
      if(!finish[i])
	{
	flag=1;
	break;
	}
    }
  if(flag)
    printf("\nsystem is in unsafe state");
  else
    printf("\nsystem is in safe state");
}
