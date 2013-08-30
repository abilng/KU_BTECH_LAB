#include<stdio.h>
#include<stdlib.h>
struct node
{
  int data,pr;
  struct node *llink,*rlink;
};
struct node *head=NULL;


void insrear()
{
  struct node *ptr;
  struct node *n1;
  int item;
  n1=(struct node *)malloc(sizeof(struct node));
  printf("Enter data\t: ");
  scanf("%d",&item);
  printf("Enter Priority:");
  scanf("%d",&n1->pr);
  n1->data=item;
  //n1->rlink=NULL;
  ptr=head;
  int flag=0;
  if(ptr!=NULL)
    {
      while(ptr!=NULL)
	{
	  if(ptr->pr <= n1->pr)
	    {
	      n1->rlink=ptr;
	      n1->llink=ptr->llink;
	      if(ptr->llink!=NULL)
		{
		  ptr->llink->rlink=n1;
		}
	      ptr->llink=n1;
	      if(n1->llink==NULL)
		{
		  head=n1;
		}
	      return;
	    }
	  else if(ptr->rlink==NULL)
	    {
	      n1->rlink=NULL;
	      n1->llink=ptr;
	      ptr->rlink=n1;
	      //n1->llink=ptr;
	      if(n1->llink=NULL)
		{
		  head=n1;
		}
	      return;
	    }
	  ptr=ptr->rlink;
	}
    }//end of if
  else 
    {
       n1->llink=NULL;
       n1->rlink=NULL;
       head=n1;
    }
 }

void display()
{
  struct node *n1;
  n1=head;
  if(n1!=NULL)
    {
      printf("\nQueue\nDATA \tPRIORITY\n");
      while(n1!=NULL)
	{
	  printf("\n %d \t %d",n1->data,n1->pr);
	  n1=n1->rlink;
	}
    }
  else printf("\n List Empty");
      printf("\n");
}
void deletef()
{
  struct node *ptr;
  ptr = head;
  if(head!=NULL)
    {
      head=head->rlink;
      if(head!=NULL)
	head->llink=NULL;
      printf("%d Removed",ptr->data);
    
      free(ptr);
    }
  else printf("\nList empty");
}


main()
{
  int ch,flag=0;
  while(flag==0)
    {
      printf("\n**MENU**\t1-Enqueue\t2-Dequeue\t3-Display\n4-EXIT\n");
      printf("Enter Choice\t: ");
      scanf("%d",&ch);
      switch(ch)
        {
        case 1:insrear();break;
        case 2:deletef();break;
        case 3:display();break;
	case 4: flag=1; break;
	  /*se 5:deleter();break;
	case 6:deletep();break;
	case 7:search();break;
	case 8:sort();break;
        case 9:display();break;
        case 10:flag=1;break;*/
        default:printf("Invalid choice\n");
        }
      
    }
  
}

