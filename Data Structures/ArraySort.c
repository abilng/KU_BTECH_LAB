#include<stdio.h>
int n;
void display(int a[])
{
  int i;
  printf("\n");
  for(i=0;i<n;i++)
    printf("\t %d",a[i]);
}
void selection(int *a)
{

}
void insertion()
{

}
void bubble(int a[])
{
  int i,j,tmp;
  for(i=0;i<n-1;i++)
    {
      for(j=i+1;j<n;j++)
	if(a[i]>a[j])
	  {
	    tmp=a[i];
	    a[i]=a[j];
	    a[j]=tmp;
	  }
    }
}
main()
{
  int i,a[25],ch;
  printf("\nEnter the number of elements(<25):");
  scanf("%d",&n);
  printf("\nEnter elements:");
  for(i=0;i<n;i++)
    scanf("%d",&a[i]);
do
  {
    printf("\n**MENU**\n1.Bubble sort\n2.Insertion sort\n3.selection sort");
printf("\n7.EXIT");
  printf("\nEnter your choice:");
  scanf("%d",&ch);
  switch(ch)
    {
      case 1:
      bubble(a);
      display(a);
      break;
    case 7:
      break;
    default:
      printf("\nINVALID CHOICE!!!!");
    }
  }while(ch!=7);
}
