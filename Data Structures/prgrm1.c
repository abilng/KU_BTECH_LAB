#include<stdio.h>
void traverse(int a[],int len);
int insert(int a[],int len);
int delete(int a[],int len);
void sort(int *a,int len);
void search(int a[],int len);
int merge(int *a,int len);
main()
{
  int a[100],n,pos,len,i,ch;
  printf("\nEnter the number of numbers:");
  scanf("%d",&len);
  for(i=0;i<len;i++)
    {
      printf("Enter the %dth element:",i+1);
      scanf("%d",&a[i]);
    }
  do
  {
    printf("\n**MENU**\n\n1.INSERT\n2.DELETE\n3.SORT\n4.SEARCH");
    printf("\n5.MERGE\n6.EXIT\n");
    printf("\nEnter your choice:");
    scanf("%d",&ch);
    switch(ch)
      {
      case 1:
	len=insert(a,len);
	traverse(a,len);
	break;
      case 2:
	len = delete(a,len);
	traverse(a,len);
	break;
      case 3:
	sort(a,len);
	traverse(a,len);
	break;
      case 4:
	search(a,len);
	traverse(a,len);
	break;
      case 5:
	len = merge(a,len);
	traverse(a,len);
	break;
      case 6:
	printf("\nbye\n");
	break;
      default:
	printf("\nInvalid choice Try again!!");
	break;
      }
  }while(ch != 6);
}
void traverse(int a[],int len)
{
  int i;
  printf("\n");
  for(i=0;i<len;i++)
    {
      printf("  %d",a[i]);
    }
}
int insert(int a[],int len)
{
  int i,pos,num;
  printf("\nEnter the position to insert an element:");
  scanf("%d",&pos);
  pos--;
  if(pos<=len && pos>=0)
    {
      printf("\nEnter the element to be inserted:");
      scanf("%d",&num);
      for(i=len;i>=pos;i--)
	a[i+1]=a[i];
      a[pos]=num;
      return (len+1);
    }
  else
    {
    printf("\nInsertion outside the array Try again!!");
    return len;
    }
}
int delete(int a[],int len)
{
  int pos,i;
  printf("\nEnter the position of element to be deleted:");
  scanf("%d",&pos);
  pos--;
  if(pos>=0 && pos<len)
    {
      for(i=pos;i<len-1;i++)
	a[i]=a[i+1];
      return (len-1);
    }
  else
    {
      printf("\nInvalid position Try again!!");
      return len;
    }
}
void sort(int *a,int len)
{
  int i,j,temp;
  for(i=0;i<len-1;i++)
    for(j=i+1;j<len;j++)
      {
	if(a[i]>a[j])
	  {
	    temp=a[i];
	    a[i]=a[j];
	    a[j]=temp;
	  }
      }
}
void search(int a[],int len)
{
  int num,f=0,i;
  printf("\nEnter the number to be searched:");
  scanf("%d",&num);
  for(i=0;i<len;i++)
    {
      if(a[i]==num)
	{
	  printf("\nFount at position %d",i+1);
	  f=1;
	}
    }
  if(f==0)
    printf("\nNot found!!!!!");
}
int merge(int *a,int len)
{
  int b[25],c[100],i=0,j=0,len1,k=0,m;
  printf("\nEnter the length of array to be merged(<25):");
  scanf("%d",&len1);
  printf("\nEnter the array:\n");
  for(i=0;i<len1;i++)
    scanf(" %d",&b[i]);
  sort(a,len);
  sort(b,len1);
  i= 0;
  while(i<len && j<len1)
    {
      if(a[i]<b[j])
	c[k++] = a[i++];
      if(a[i]>b[j])
	c[k++] = b[j++];
    }
  while(i<=len)
    {
    c[k++] = a[i++];
    }
  while(j<=len1)
    {
      c[k++] = b[j++];
    }
  for(m=0;m<k;m++)
    a[m]=c[m];
  return k-1;
}
