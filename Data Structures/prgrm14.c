#include<stdio.h>
#include<stdlib.h>
struct queue
{
  int data;
  struct queue *link;
}*new,*ptr,*head=NULL,*front,*rear;
struct queue* getnode()
{
  struct queue *n=(struct queue*)malloc(sizeof(struct queue));
  return n;
}
void display()
{
  ptr=front;
  if(ptr==NULL)
    printf("Queue empty\n");
  else
    {
      printf("Queue:");
      while(ptr!=NULL)
	{
	  printf("  %d",ptr->data);
	  ptr=ptr->link;;
	}
    }
}
void enqueue(int x)
{
 new=getnode();
 new->data=x;
 new->link=NULL;               
 if(head==NULL)
 {
   head=new;
   front=new;
   rear=new;
 }
  else
 {
   rear->link=new;
   rear=new;
 }
}
void dequeue()
{
  printf("Dequeued value is %d \n",front->data);
  front=front->link;
  head=front;
}
main()
{
  int ch,x;
  while(ch!=3)
  {
    printf("\n**MENU**\n");
    printf("Enter the choice \n1.Enqueue \n2.Dequeue \n3.Exit\n");
    scanf("%d",&ch);
    switch(ch)
      {
      case 1:printf("Enter the value\n");
	     scanf("%d",&x);
	     enqueue(x);   
             display();
	     break;		      
      case 2:dequeue();
	     display();
	     break;
      case 3:exit(0);
      }
  }
}
