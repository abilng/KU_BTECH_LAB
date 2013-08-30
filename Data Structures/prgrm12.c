#include<stdio.h>
#include<stdlib.h>
struct node
{
  int coeff;
  int power;
  struct node* link;
}*head,*new,*head1,*head2,*head3,*ptr1,*ptr2;

struct node* read(struct node* head)
{
  int coef,exp,i,n;
  printf("enter the no of terms\n");
  scanf("%d",&n);
  printf("Enter the terms \n");
  for(i=0;i<2*n;i+=2)
    {
      printf("Coefficient:");
      scanf("%d",&coef);
      printf("Exponent:");
      scanf("%d",&exp);
	if(coef!=0)
	  {
	    new=(struct node*)malloc(sizeof(struct node));
	    new->coeff=coef;
	    new->power=exp;
	    new->link=NULL;
	  }
	if(head==NULL)
	  head=new;
	else
	  ptr1->link=new;
	ptr1=new;
    }
  return(head);
}
void sort(struct node* head)
{
  int temp;
  ptr1=head;
  while(ptr1!=NULL)
    {
      ptr2=ptr1->link;
      while(ptr2!=NULL)
	{
	  if((ptr2->power)>(ptr1->power))
	    {
	      temp=ptr1->coeff;
	      ptr1->coeff=ptr2->coeff;
	      ptr2->coeff=temp;
	      temp=ptr1->power;
	      ptr1->power=ptr2->power;
	      ptr2->power=temp;
	    }
	  ptr2=ptr2->link;
	}
      ptr1=ptr1->link;
    }
}
void display(struct node* head)
{
  sort(head);
  ptr1=head;
  while(ptr1!=NULL)
    {
      if(ptr1->coeff != 0)
	{
	  if(ptr1!=head)
	    printf("\t+\t");
	   
	    if(ptr1->power==0)
	      printf("%d",ptr1->coeff,ptr1->power);
	    else
	      printf("%dx^%d",ptr1->coeff,ptr1->power);
	}
      ptr1=ptr1->link;
    }
  printf("\n");
}
//{
  
//}
void add(struct node* head)
{
  struct node *ptr3;
  ptr1=head1;
  int flag=0;
  while(ptr1!=NULL)
    {
         new=(struct node*)malloc(sizeof(struct node));
	 new->link=NULL;
	 if(ptr1==head1)
	   head3=new;
	 else
	   ptr2->link=new;
	 new->coeff=ptr1->coeff;
	 new->power=ptr1->power;
	 ptr2=new;
	 ptr1=ptr1->link;
    }
  ptr1=head2;
  while(ptr1!=NULL)
    {
      flag=0;
      ptr2=head3;
      while(ptr2!=NULL)
	{
	  if(ptr1->power==ptr2->power)
	    {
	      flag++;
	      ptr2->coeff+=ptr1->coeff;
	    }
	  ptr2=ptr2->link;
	}
      if(flag==0)
	{
            new=(struct node*)malloc(sizeof(struct node));
	    new->power=ptr1->power;
	    new->coeff=ptr1->coeff;
	    ptr3=head3;
	    while(ptr3->link!=NULL)
	      ptr3=ptr3->link;
	    ptr3->link=new;
	}
      ptr1=ptr1->link;
    }
  ptr1=head;
  while(ptr1!=NULL)
    {
      if(ptr1->coeff==0)
	{
	  if(ptr1==head)
	    {
	      head=ptr1->link;
	      free(ptr1);
	    }
	  else
	    {
	      ptr2->link=ptr1->link;
	      free(ptr1);
	    }
	}
      ptr2=ptr1;
      ptr1=ptr1->link;
    }
}
void multiply(struct node* head)
{
  struct node *ptr3;
  ptr1=head1;
  while(ptr1!=NULL)
    {
      ptr2=head2;
      while(ptr2!=NULL)
	{
	  if(ptr1->coeff+ptr2->coeff!=0)
	    {
               new=(struct node*)malloc(sizeof(struct node));
	       if(ptr1==head1&&ptr2==head2)
		 head3=new;
	       else
		 ptr3->link=new;
	       new->power=ptr1->power+ptr2->power;
	       new->coeff=ptr1->coeff*ptr2->coeff;	  
	       ptr2=ptr2->link;
	       ptr3=new;
	    }
	}
      ptr1=ptr1->link;
    }
  ptr1=head3;
  while(ptr1!=NULL)
    {
      ptr2=ptr1->link;
      while(ptr2!=NULL)
	{
	  if(ptr1->power==ptr2->power)
	    {
              ptr1->coeff=ptr1->coeff+ptr2->coeff;
	      ptr2->coeff=0;
	    }
	  ptr2=ptr2->link;
	}
      ptr1=ptr1->link;
    }//
  ptr1=head;
  while(ptr1!=NULL)
    {
      if(ptr1->coeff==0)
	{
	  if(ptr1==head)
	    {
	      head=ptr1->link;
	      free(ptr1);
	    }
	  else
	    {
	      ptr2->link=ptr1->link;
	      free(ptr1);
	    }
	}
      ptr2=ptr1;
      ptr1=ptr1->link;
    }
  sort(head3);
}
main()
{
  int ch;
  // while(ch!=3)
   
     head1=NULL;
     head2=NULL;
    printf("Enter first polynomial:\n\n");
    head1=read(head1);
    printf("Enter the second polynomial:\n\n");
    head2=read(head2);
    while(ch!=3)
      {
	printf("\nMENU\n");
	printf("Enter the choice 1.Addition 2.Multiplication 3.Exit\n");
	scanf("%d",&ch);
	switch(ch)
	  {
	  case 1:add(head);
            display(head1);
            printf("\t\t+\n");
            display(head2);
            printf("\t\t=\n");
            display(head3);
            break;
	  case 2:multiply(head);
            display(head1);
            printf("\t\t*\n");
            display(head2);
            printf("\t\t=\n");
            sort(head3);
            display(head3);
            break;
	  case 3:exit(0);
	  }
      }
}
