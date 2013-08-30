#include<stdio.h>
#include<stdlib.h>
struct node
{
  int data;
  struct node *lchild,*rchild;
};
struct node *root=NULL,*ptr,*ptr1=NULL;
void insert(int item)
{
  ptr=root;
  struct node *new;
  new = (struct node *)malloc(sizeof(struct node));
  new->data=item;
  new->lchild=NULL;
  new->rchild=NULL;
  if(ptr!=NULL)
    {
      while(ptr!=NULL)
	{
	  //ptr1=ptr;
	  if(ptr->data > item)
	    {
	      ptr1=ptr;
	      ptr=ptr->lchild;
	      //      printf("1");
	    }
	  else if(ptr->data < item)
	    {
	      ptr1=ptr;
	      ptr=ptr->rchild;
	      //printf("2");
	      }
	  else
	    {
	      printf("\nSame element exists\n");
	      return;
	    }
	}
      if(ptr1->data > item)//leaf node
	ptr1->lchild=new;
      else if(ptr1->data < item)
	ptr1->rchild=new;
    }
  else root = new;
}
void display(struct node *p,int k)
{
  int i;
  //ptr=root;
  if(p!=NULL)
    {
      display(p->lchild,k-1);
      for(i=0;i<k;i++)
	printf("\t");
      printf(" %d\n  ",p->data);
      display(p->rchild,k-1);
    }
  //else printf("\ntree empty");
}
int height(struct node *p1)
{
  struct node *p;
  int m,n;
  p=p1;
  if(p==NULL)
    return(0);
  m=height(p->lchild);
  n=height(p->rchild);
  if(m>n)
    return(m+1);
  else 
    return(n+1);
}
int count(struct node *p)
{
  int n1,n2;
  if(p!=NULL)
    {
      n1=count(p->lchild);
      n2=count(p->rchild);
    }
  else return(0);
  return(n1+n2+1);
}
void inorder(struct node *root)
{
  if(root!=NULL)
    {
      inorder(root->lchild);
      printf("\t %d",root->data);
      inorder(root->rchild);
    }

}
void preorder(struct node *root)
{
  if(root!=NULL)
    {
      if(root!=NULL)
	{
	  printf("%d",root->data);
	  preorder(root->lchild);
	  preorder(root->rchild);
	}
    }
}
void search(struct node *root,int item)
{
  if(root->data==item)
      { 
	printf("\nfound\n");
	return;
   }
  search(root->lchild,item);
  search(root->rchild,item);
  printf("\nNot found\n");
}
void postorder(struct node *root)
{
  if(ptr!=NULL)
    {
      postorder(root->lchild);
      postorder(root->rchild);
      printf("%d",root->data);
    }
}
main()
{
  int ch,item,n;
  printf("\nEnter the root element :");
  scanf("%d",&item);
  insert(item);
  do
    {
      printf("\n**MENU**\n");
      printf("\n1.Insert\n2.Delete\nTraverse:\n\t3-Inorder\t4-preorder\t5-postorder");
      printf("\n6.search\n7.count nodes\n8.height");      
printf("\n9.EXIT");
      printf("\nEnter your choice:");
      scanf("%d",&ch);
      switch(ch)
	{
	case 1:
	  printf("\nEnter the element to be inserted:");
	  scanf("%d",&item);
	  insert(item);
	  display(root,height(root));
	  break;
	case 3:
	  inorder(root);
	  //display(root,height(root));
	  //inorder(root);
	  break;
	case 4:
	  preorder(root);
	  break;
	case 5:
	  postorder(root);
	  break;
	case 6:
	  printf("\nEnmter the element :");
	  scanf("%d",&item);
	  search(root,item);
	  break;
	case 7:
	  n=count(root);
	  printf("\nEnter the no. of nodes:%d",n);
	  break;
	case 9:
	  break;
	default:
	  printf("\nInvalid choice");
	}
    }while(ch!=9);
}
