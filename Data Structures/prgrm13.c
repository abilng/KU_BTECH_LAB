#include<stdio.h>
#include<stdlib.h>
struct node
{
  int data;
  struct node *link;
};
struct node *top = NULL; 
void push();
void pop();

main()
{
  //int stack[25],ch,top=-1,lim;
  //printf("\nEnter the stack limit:");
  //scanf("%d",&lim);
  int ch;
  do{
  printf("\n**MENU**\n1.PUSH an element:\n2.POP an element");
  printf("\n3.EXIT\nEnter your choice:");
  scanf("%d",&ch);
  switch(ch)
    {
    case 1:
      push();
      break;
    case 2:
      pop();
      break;
    case 3:
      break;
    default:
      printf("\nInvalid choice. Try again!!");
      break;
    }
  }while(ch!=3);
}
void push()
{
  struct node *new,*ptr;
  new = (struct node*)malloc(sizeof(struct node)); 
  printf("\nEnter element to be pushed:");
  scanf("%d",&new->data);
  if(top==NULL)
    {
      new->link=NULL;
      top=new;
    }
  else 
    {
      new->link=top;
      top=new;
    }
  ptr=top;
  while(ptr!=NULL)
    {
      printf(" %d",ptr->data);
      ptr=ptr->link;
    }
      return;
}
void pop()
{
  struct node *ptr;
  ptr=top; 
  if(top==NULL)
    {
      printf("\nstack underflow");
      return;
    }
  printf("\n%d rmoved\n",ptr->data);
  top=top->link;
  free(ptr);
  ptr=top;
  while(ptr!=NULL)
    {
    printf(" %d",ptr->data);
    ptr=ptr->link;
    }
}
