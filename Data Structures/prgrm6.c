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
void enq(int *q,int *rear,int *front);
void deq(int *q,int *rear,int *front);
main()
{
  int q[25],rear=-1,front=-1,ch;
  printf("\nEnter the queue limit:");
  scanf("%d",&n);
do
  {
    printf("\n**MENU**\n1.Enqueue\n2.Dequeue\n3.Display\n4.EXIT");
    printf("\nEnter your choice:");
    scanf("%d",&ch);
    switch(ch)
      {
      case 1:
	enq(q,&rear,&front);
	//display(q,rear,front);
	break;
      case 2:
	deq(q,&rear,&front);
	//display(q,rear,front);
	break;
      case 3:
	display(q,rear,front);
	break;
      case 4:
	break;
      default:
	printf("\nInvalid choice!!");
	break;
      }
  }while(ch!=4);
  
}
void enq(int *q,int *rear,int *front)
{
  if((*rear)<n-1)
    {
      if((*front) == -1)
	{
	  //  printf("\nQueue full");
	 (*front)=(*rear)=0;
	}
      else (*rear)++;
      printf("\nenter the element to be pushed :");
      scanf("%d",&q[*rear]);
    }
  else printf("\nQueue full");
  //scanf("%d",&q[rear]);
  //return rear;
}
void deq(int *q,int *rear,int *front)
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
