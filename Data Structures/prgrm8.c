#include<stdio.h>
int n;
void display(int q[],int rear,int front)
{
  int i;
  printf("\n<front>");
      for(i=front;i<=rear;i++)
	printf("  %d",q[i]);
    
  printf(" <rear>");
    
}
void enqr(int *q,int *rear,int *front);
void enqf(int *q,int *rear,int *front);
void deqr(int *q,int *rear,int *front);
void deqf(int *q,int *rear,int *front);
main()
{
  int q[25],rear=-1,front=-1,ch;
  printf("\nEnter the dequeue limit:");
  scanf("%d",&n);
do
  {
    printf("\n**MENU**\n1.Enqueue @ rear\n2.Enqueue @ front\n3.Dequeue @ rear\
\n4.Dequeue @ front\n5.Display\n6.EXIT");
    printf("\nEnter your choice:");
    scanf("%d",&ch);
    switch(ch)
      {
      case 1:
	enqr(q,&rear,&front);
	//display(q,rear,front);
	break;
      case 2:
	enqf(q,&rear,&front);
	//display(q,rear,front);
	break;
      case 3:
	deqr(q,&rear,&front);
	break;
      case 4:
	deqf(q,&rear,&front);
	break;
      case 5:
	display(q,rear,front);
	break;
      case 6:
	break;
      default:
	printf("\nInvalid choice!!");
	break;
      }
  }while(ch!=6);
  
}
void enqf(int *q,int *rear,int *front)
{
  int next,i;
  if((*front) == -1)
	{
	  //  printf("\nQueue full");
	 (*front)=(*rear)=0;
	}
  else if((*front)==0)
    {
      if((*rear)<(n-1))
	{
	  for(i=(*rear);i>=(*front);i--)
	    q[i+1]=q[i];
	  (*rear)++;
	}
      else
	{
	  printf("\nQueue full");
	  return;
	}
      //else *rear = next;
    }
  else (*front)--;
      printf("\nenter the element to be pushed :");
      scanf("%d",&q[*front]);
   
}
void deqf(int *q,int *rear,int *front)
{
  int item;
  if(*front == -1)
    {
      printf("\nqueue empty");
      return;
    }
else if(*front == *rear)
    {
      item=q[*front];
      *front = *rear =-1;
    }
  else 
    {
      item=q[*front];
      (*front)++;
    }
  printf("\n %d deleted",item);
}
void deqr(int *q,int *rear,int *front)
{
  int item;
  if(*front == -1)
    {
      printf("\nqueue empty");
      return;
    }
else if(*front == *rear)
    {
      item=q[*rear];
      *front = *rear =-1;
    }
  else 
    {
      item=q[*rear];
      (*rear)--;
    }
  printf("\n %d deleted",item);
}
void enqr(int *q,int *rear,int *front)
{
int next,i;
  if((*front) == -1)
	{
	  //  printf("\nQueue full");
	 (*front)=(*rear)=0;
	}
  else 
    {
      next=(*rear)+1;
       if(next==n)
	{
	  if((*front) > 0)
	    {
	      for(i=(*front);i<=(*rear);i++)
		{
		  q[i-1]=q[i];
		}
	      (*front)--;

	    }
	  else
	    {
	      printf("\nQueue full");
	      return;
	    }
	}
       else 
	 (*rear)++;
       //else *rear = next;
    }
      printf("\nenter the element to be pushed :");
      scanf("%d",&q[*rear]);
}
