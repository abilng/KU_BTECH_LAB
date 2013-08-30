     
#include<stdio.h>
#include<stdlib.h>
struct node
{
  int data;
  struct node *lchild;
  struct node *rchild;
}*root,*new,*ptr,*ptr1;
void insertion(int value)  
{
  new=(struct node *)malloc(sizeof(struct node *));
  new->data=value;
  new->lchild=NULL;
  new->rchild=NULL;
  if(root==NULL)  
    root=new;
  else
    {
      ptr=root;   
      while(ptr!=NULL)   
	{
	  ptr1=ptr;
	  if(ptr->data>value)
	    ptr=ptr->lchild;
	  else
	    ptr=ptr->rchild;
	}
      if(ptr1->data>value)
	ptr1->lchild=new;
      else
	if(ptr1->data<value)
	  ptr1->rchild=new;
	else
	  {
	    printf("same value exists....\n");
	    return;
	  }
    }
}
void deletion(int item)  
{
  struct node *ptr2;
  ptr=root;
  while(ptr->data!=item&&ptr!=NULL)
    {
      ptr1=ptr;
      if(ptr->data>item)
	ptr=ptr->lchild;
      else
	ptr=ptr->rchild;
      if(ptr==NULL)
	{
	  printf("Element not found\n");
	  return;
	}
    }
  if(ptr->rchild==NULL&&ptr->lchild==NULL)  
    {
      if(ptr==root)
	root=NULL;
      else
	{
	  if(ptr1->rchild==ptr)
	    ptr1->rchild=NULL;
	  else
	    ptr1->lchild=NULL;
	}
      free(ptr);
    }
  else
    if(ptr->rchild==NULL)  
      {
	if(ptr==root)
	  root=ptr->lchild;
	else
	  {
	    if(ptr1->rchild==ptr)
	      ptr1->rchild=ptr->lchild;
	    else
	      ptr1->lchild=ptr->lchild;
	  }
	free(ptr);
      }
    else
      if(ptr->lchild==NULL)  
	{
	  if(ptr==root)
	    root=ptr->rchild;
	  else
	    {
	      if(ptr1->rchild==ptr)
		ptr1->rchild=ptr->rchild;
	      else
		ptr1->lchild=ptr->rchild;
	    }
	  free(ptr);
	}
      else                            
 	{
	  ptr2=ptr->rchild;
	  while(ptr2->lchild!=NULL)
	    {
	      ptr1=ptr2;
	      ptr2=ptr2->lchild;
	    }    //ptr2=inorder succesor
   	  if(ptr2->lchild==NULL&&ptr2==ptr->rchild)   
	    {
	      ptr->data=ptr2->data;
	      ptr->rchild=NULL;
	      free(ptr2);
	    }
	  else
	    {
	      ptr->data=ptr2->data;
	      if(ptr2->lchild==NULL&&ptr2->rchild==NULL) 
		{
		  ptr1->lchild=NULL;
		  free(ptr2);
		}
	      else
		if(ptr2->lchild==NULL)       
		  {

		    ptr1->lchild=ptr2->rchild;
		    free(ptr2);
		  }
		else     
		  {
		    ptr1->lchild=ptr2->lchild;
		    free(ptr2);
		  }
	    }
	}
}
void display(struct node *ptr,int k)    
{
  int i;
  if(ptr!=NULL)
    {
      display(ptr->lchild,k-1);
      for(i=0;i<k;i++)
	printf("\t");
      printf("%d\n",ptr->data);
      display(ptr->rchild,k-1);
    }
}
int height(struct node *root)
{
  struct node *pt;
  int h1,h2;
  pt=root;
  if(pt==NULL)
    return(0);
  else
    {
      h1=height(pt->lchild);
      h2=height(pt->rchild);
      if(h1>h2)
	return(h1+1);
      else
	return(h2+1);
    }
}
void preorder(struct node *ptr)   //preorder
{
  if(ptr!=NULL)
    {
      printf("%d\t",ptr->data);
      preorder(ptr->lchild);
      preorder(ptr->rchild);
    }
}
void inorder(struct node *ptr)  //inorder
{
  if(ptr!=NULL)
    {
      inorder(ptr->lchild);
      printf("%d\t",ptr->data);
      inorder(ptr->rchild);
    }
}
void postorder(struct node *ptr)  //postorder 
{
  if(ptr!=NULL)
    {
      postorder(ptr->lchild);
      postorder(ptr->rchild);
      printf("%d\t",ptr->data);
    }
}
int count(struct node *ptr)   //number of nodes
{
  int i1,i2;
  if(ptr!=NULL)
    {
      i1=count(ptr->lchild);
      i2=count(ptr->rchild);
    }
  else
    return(0);
  return(i1+i2+1);
}
void main()
{
  int ch,value,i,ch1;
  char ans;
  do
    {
      printf("\t**MENU**\n1.Insertion\n2.Deletion\n3.Traversal\n4.No of nodes in tree\n5.Height of tree\n6.EXIT");
printf("\nEnter your choice:");
      scanf("%d",&ch);
      switch(ch)
	{
	case 1:
	  printf("Enter the value to be inserted:");
	  scanf("%d",&value);
	  insertion(value);
	  display(root,height(root));
	  break;
	case 2:
	  printf("Enter the value to be deleted:");
	  scanf("%d",&value);
	  deletion(value);
	  display(root,height(root));
	  break;
	case 3:
	  printf("\t\t1.preorder traversal\n2.inorder traversal\n3.postorder traversal\n");
	  scanf("%d",&ch1);
	  switch(ch1)
	    {
	    case 1:
	      preorder(root);
	      break;
	    case 2:
	      inorder(root);
	      break;
	    case 3:
	      postorder(root);
	      break;
	    default:
	      printf("Invalid choice\n\n");
	    }
	  break;
	case 4:
	  i=count(root);
	  printf("No of nodes=%d\n",i);
	  break;
	case 5:
	  printf("to find height\n");
	  i=height(root);
	  printf("height=%d\n",i);
	  break;
        case 6:
	       break;
	default:
	  printf("Invalid choice\n");
	}
      printf("Do you want to continue?Press y for yes\n");
      scanf(" %c",&ans);
    }
  while(ch!=6);
}
