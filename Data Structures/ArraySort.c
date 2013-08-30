#include<stdio.h>
#include<stdlib.h>
int n1;

void display(int a[],int n)
{
  int i;
  for(i=0;i<n;i++)printf("%d ",a[i]);
  printf("\n");
}


void bubblesort(int a[],int n)
{
  int i,j,temp;
  for(i=0;i<n-1;i++)
    for(j=0;j<n-i-1;j++)
      if(a[j]>a[j+1])
	{
	  temp=a[j];
	  a[j]=a[j+1];
	  a[j+1]=temp;
	}
  printf("BUBBLE SORT\n");
  display(a,n);

}

void selectionsort(int a[],int n)
{
  int min,pos,i,j,temp;

  for(i=0;i<n;i++)
    {
      min=a[i];
      pos=i;
      for(j=i+1;j<n;j++)if(a[j]<min){ min=a[j]; pos=j;}
      if(pos!=i)
	{
	  temp=a[pos];
	  a[pos]=a[i];
	  a[i]=temp;
	}
    }
  printf("SELECTION SORT\n");
  display(a,n);
}

void insertionsort(int a[],int n)
{
  int i,j,key;

  for(j=1;j<n;j++)
    {
      key=a[j];
      i=j-1;
      while(i>=0&&key<a[i])
	{
	  a[i+1]=a[i];
	  i--;
	}
      a[i+1]=key;
    }

  printf("INSERTION SORT\n");
  display(a,n);
}

int partition(int a[],int p,int r)
{
  int i,j,key,temp;
  key=a[p];
   i=p;
  j=r+1;
  while(1)
    {
      do{ i++;}while(a[i]<key);
      do{ j--;}while(a[j]>key);
      if(i<j)
	{
	  temp=a[i];
	  a[i]=a[j];
	  a[j]=temp;
	}
      else
	{
	  temp=a[j];
	  a[j]=a[p];
	  a[p]=temp;
	  return j;
	}
    }
}


void quicksort(int a[],int p,int r)
{
  int q;
  if(p<=r)
    {
q=partition(a,p,r);
  quicksort(a,p,q-1);
  quicksort(a,q+1,r);
}
}


void heapify(int a[],int i)
{
  int l,r,largest,temp;

  l=2*i;
  r=2*i+1;

  if((l<n1)&&(a[l]>a[i]))largest=l;
  else largest=i;

  if((r<n1)&&(a[r]>a[largest]))largest=r;

  if(largest!=i)
    {
      temp=a[i];
      a[i]=a[largest];
      a[largest]=temp;
      heapify(a,largest);
    }
}

void buildheap(int a[])
{
  int i;
  for(i=n1/2;i>=0;i--)heapify(a,i);
}

void heapsort(int a[])
{
  int i,temp;
  buildheap(a);
  for(i=n1-1;i>=1;i--)
    {
      temp=a[0];
      a[0]=a[i];
      a[i]=temp;
      n1--;
      heapify(a,0);
    }
}




void merge(int a[],int p,int r,int q)
{
  int i,j,temp[40],k=0;
  i=p;
  j=r+1;
  while((i<=r)&&(j<=q))
    {
      if(a[i]==a[j])
	{
	  temp[k]=a[i];
	  i++;
	  k++;
	}
      else if(a[i]<a[j])
	{
	  temp[k]=a[i];
	  k++;
	  i++;
	}
      else if(a[i]>a[j])
	{
	  temp[k]=a[j];
	  k++;
	  j++;
	}
    }
      while(i<=r)
	{
	  temp[k]=a[i];
	  k++;
	  i++;
	}
      while(j<=q)
	{
	  temp[k]=a[j];
	  k++;
	  j++;
	}

      for(i=p,k=0;i<=r;i++,k++)a[i]=temp[k];
      for(i=r+1,j=k;i<=q;i++,j++)a[i]=temp[j];




}




void mergesort(int a[],int p,int q)
{
  int r;
  if(p<q)
    {
      r=(p+q)/2;
      mergesort(a,p,r);
      mergesort(a,r+1,q);
      merge(a,p,r,q);
    }
}



main()
{
  int a[40],n,i,q,choice,yn;

do
  {
  printf("Enter the number of elements:");
  scanf("%d",&n);
  n1=n;
  printf("Enter the list of numbers:");
  for(i=0;i<n;i++)scanf("%d",&a[i]);
  printf("ARRAY BEFORE SORTING\n");
  display(a,n);

  printf("\n\t**MENU**\n");
  printf("1.Bubble sort\n2.Insertion sort\n3.Selection sort\n4.Quick sort\n5.Merge sort\n6.Heap sort\n7.Exit\nEnter your choice:");
  scanf("%d",&choice);
  switch(choice)
    {
    case 1:
      bubblesort(a,n);
      printf("BUBBLE SORT\n");
      display(a,n);
      break;
    case 2:
      insertionsort(a,n);
      printf("INSERTION SORT\n");
      display(a,n);
      break;
    case 3:
      selectionsort(a,n);
      printf("SELECTION SORT\n");
      display(a,n);
      break;
    case 4:
      quicksort(a,0,n-1);
      printf("QUICK SORT\n");
      display(a,n);
      break;
    case 5:
      mergesort(a,0,n-1);
      printf("MERGE SORT\n");
      display(a,n);
      break;
    case 6:
      heapsort(a);
      printf("HEAP SORT\n");
      display(a,n);
      break;
    case 7:
      return;
    }

  printf("\nDo you want to continue with a different array (enter 1 or 0):");
  scanf("%d",&yn);
  }while(yn==1);
}


