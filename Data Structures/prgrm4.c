#include<stdio.h>
void push(int *stack,int *top,int lim);
void pop(int *stack,int *top);

main()
{
  int stack[25],ch,top=-1,lim;
  printf("\nEnter the stack limit:");
  scanf("%d",&lim);
  do{
  printf("\n**MENU**\n1.PUSH an element:\n2.POP an element");
  printf("\n3.EXIT\nEnter your choice:");
  scanf("%d",&ch);
  switch(ch)
    {
    case 1:
      push(stack,&top,lim);
      break;
    case 2:
      pop(stack,&top);
      break;
    case 3:
      break;
    default:
      printf("\nInvalid choice. Try again!!");
      break;
    }
  }while(ch!=3);
}
void push(int *stack,int *top,int lim)
{
  int i;
  if((*top) == lim-1)
    {
      printf("\nstack overflow");
      return;
    }
  (*top)++;
  printf("\nEnter element to be pushed:");
  scanf("%d",&stack[(*top)]);
  for(i=0;i<=(*top);i++)
    printf(" %d",stack[i]);
  return;
}
void pop(int *stack,int *top)
{
  int i;
  if((*top)==-1)
    {
      printf("\nstack underflow");
      return;
    }
  printf("\n%d rmoved\n",stack[(*top)--]);
  for(i=0;i<=(*top);i++)
    printf(" %d",stack[i]);
  }
