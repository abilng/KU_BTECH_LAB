#include<stdio.h>
#include<stdlib.h>
struct node
{
  int data;
  struct node *llink,*rlink;
};
struct node *head=NULL;

void insfrt()
{
  int item;
  struct node *n1;
  n1=(struct node *)malloc(sizeof(struct node));
  printf("Enter Data\t: ");
  scanf("%d",&item);
  n1->llink=head;
  if(head != NULL)
    head->rlink=n1;
  n1->data=item;
  n1->rlink=NULL;
  head=n1;
}
void insrear()
{
  struct node *ptr;
  struct node *n1;
  int item;
  n1=(struct node *)malloc(sizeof(struct node));
  printf("Enter data\t: ");
  scanf("%d",&item);
  n1->data=item;
  n1->llink=NULL;
  ptr=head;
  int flag=0;
  if(ptr!=NULL)
    {
      while(flag==0)
	{
	  if(ptr->llink==NULL)
	    {
	      ptr->llink=n1;
	      n1->rlink=ptr;
	      flag=1;
	    }
	  else
	    {
	      ptr=ptr->llink;
	    }
	}
    }
  else
    {
      // printf("fasdd");
      head=n1;
      n1->rlink=NULL;
    }
}
void inspos()
{
  struct node *ptr,*n1,*tmp;
  int item,pos,count=2;
  printf("Enter the position:");
  scanf("%d",&pos);
  if(pos == 1)
    insfrt();
  else
    {
      ptr=head;
      while(ptr != NULL)
        {
          if(count == pos)
            {
              n1=(struct node *)malloc(sizeof(struct node));
              printf("Enter data\t: ");
              scanf("%d",&item);
              n1->data=item;
              n1->llink=ptr->llink;
	      if(ptr->llink!=NULL)
		(ptr->llink)->rlink=n1;
	      n1->rlink=ptr;
              ptr->llink=n1;
              return;
            }
          ptr=ptr->llink;
          count++;
        }
      printf("Position not found\n");
    }
}
void display()
{
  struct node *n1;
  n1=head;
  if(n1!=NULL)
    {
      printf("\nContents of Linked list\n");
      while(n1!=NULL)
	{
	  printf("%d ",n1->data);
	  n1=n1->llink;
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
      head=head->llink;
      if(head!=NULL)
	head->rlink=NULL;
      printf("%d Removed",ptr->data);
    
      free(ptr);
    }
  else printf("\nList empty");
}
void deleter()
{
  struct node *ptr,*ptr1;
  ptr = head;
  // ptr1=ptr->llink;
  if(head!=NULL)
    {
      ptr1=ptr->llink;
      if(ptr1==NULL)
	{
	  deletef();
	  return;
	}
      while(ptr1->llink!=NULL)
	{
	  ptr=ptr1;
	  ptr1=ptr1->llink;
	}
	  //head=head->link;
      ptr->llink = NULL;
      printf("%d Removed",ptr1->data);
      free(ptr1);
    }
  else printf("\nList empty");
}
void deletep()
{
  struct node *ptr,*temp;
  int item,pos,count=2;
  printf("Enter the position:");
  scanf("%d",&pos);
  if(pos == 1)
    deletef();
  else
    {
      ptr=head;
      temp=ptr->llink;
      while(temp!= NULL)
        {
          if(count == pos)
            {
	      // n1=(struct node *)malloc(sizeof(struct node));
              printf("%d Removed",temp->data);
              //scanf("%d",&item);
	      //   free(temp);
              ptr->llink=temp->llink;
	      if(temp->llink!=NULL)
		(temp->llink)->rlink=ptr;
	      free(temp);	      
	      // ptr->link=n1;
              return;
            }
          ptr=temp;
	  temp=temp->llink;
          count++;
        }
      printf("Position not found\n");
    }
}
void search()
{
  struct node *ptr;
  int item,flag=0;
  ptr=head;
  if(ptr!=NULL)
    {
      printf("\nEnter the element to be searched:");
      scanf("%d",&item);
      while(ptr!=NULL)
	{
	  if(ptr->data==item)
	    {
	      //printf("");
	      flag=1;
	      break;
	    }
	  ptr=ptr->llink;
	}
      if(flag)
	printf("\n%d Fount in list",item);
      else printf("\nNot found");
    }
  else printf("\nList Empty");
}
void sort()
{
  struct node *ptr,*ptr1,*tmp;
  ptr=head;
  //ptr1=head->link;
  if(head!=NULL)
    {
      while(ptr->llink!=NULL)
	{
	  ptr1=ptr->llink;
	  while(ptr1!=NULL)
	    {
	      if(ptr->data>ptr1->data)
		{
		  tmp->data=ptr->data;
		  ptr->data=ptr1->data;
		  ptr1->data=tmp->data;
		}
	      ptr1=ptr1->llink;
	    }
	  ptr=ptr->llink;
	}
      printf("\nList sorted");
    }
  else printf("\nList empty");
    }
main()
{
  int ch,flag=0;
  while(flag==0)
    {
      printf("\n**MENU**\n1-Insert  @front\t2-Insert @rear\t3-Insert @position\n");
      printf("4-Delete @front  \t5-Delete @rear\t6-Delete @position");
      printf("\n7-Search data     \t8.SORT        \t9-Display all\n10-Exit\n");
      printf("Enter Choice\t: ");
      scanf("%d",&ch);
      switch(ch)
        {
        case 1:insfrt();break;
        case 2:insrear();break;
        case 3:inspos();break;
	case 4:deletef();break;
	case 5:deleter();break;
	case 6:deletep();break;
	case 7:search();break;
	case 8:sort();break;
        case 9:display();break;
        case 10:flag=1;break;
        default:printf("Invalid choice\n");
        }
      
    }
  
}

