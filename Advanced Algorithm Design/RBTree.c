#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define RED 0
#define BLACK 1
#define QUEUE_SIZE 100

struct node
{
  int key;
  int color;
  struct node *l;
  struct node *r;
  struct node *p;
}*root=NULL;

int front =-1,rear=-1;
struct node *queue[100];
struct node *NILL;

void build_RBT(struct node *ptr,int item,int color)
{
  struct node *lptr,*rptr;
  int ch,item1,item2,color1,color2;
  char temp[20];
  if(ptr!=NILL)
    {
      ptr->key=item;
      ptr->color=color;
      printf("Left child for %d ? \n1.Yes \n2.No \n",ptr->key);
      scanf("%d",&ch);
      if(ch==1)
	{
	  lptr=(struct node*)malloc(sizeof(struct node));
	  ptr->l=lptr;
	  lptr->p=ptr;
	  printf("Enter left child with color of %d:",ptr->key);
	  scanf("%d%d",&item1,&color1);
	  build_RBT(lptr,item1,color1);
	}
      else
	{
	  lptr=NILL;
	  ptr->l=NILL;
	  build_RBT(lptr,-1,-1);
	}
      printf("Right child for %d?(\n1.YEs\n2.No\n",ptr->key);
      scanf("%d",&ch);
      if(ch==1)
	{
	  rptr=(struct node *)malloc(sizeof(struct node));
	  ptr->r=rptr;
	  rptr->p=ptr;
	  printf("Enter the right child with color of %d:",ptr->key);
	  scanf("%d%d",&item2,&color2);
	  build_RBT(rptr,item2,color2);
	}
      else
	{
	  rptr=NILL;
	  ptr->r=NILL;
	  build_RBT(rptr,-1,-1);
	}
    }
}

void inorder(struct node *root)
{
  struct node * ptr;
  ptr= root;
  if(ptr!=NULL)
    {
      inorder(ptr->l);
      if(ptr->color==RED)printf("(%d,RED)",ptr->key);
      else if(ptr->color==BLACK)printf("(%d,BLACK)",ptr->key);
      inorder(ptr->l);
    }
}

struct node *search(int item)
{
  struct node * ptr;
  ptr= root;
  while(ptr!=NILL)
    {
      if(item<ptr->key)ptr=ptr->l;
      else if(item>ptr->key)ptr=ptr->r;
      else return ptr;
    }
}

void enqueue(struct node *item)
{
  if(rear==QUEUE_SIZE-1)
    {
      printf("Queue full error\n");
      exit(1);
    }
  if(rear==-1)
    front=rear=0;
  else rear++;
  queue[rear]=item;
}

struct node *dequeue()
{
  struct node *item;
  if(front==-1)
    {
      printf("Queue empty error\n");
      exit(1);
    }
  item=queue[front];
  if(front==rear)front=rear=-1;
  else front++;
  return item;

}


void level_order()
{
  struct node * ptr;
  front=rear=-1;
  enqueue(root);
  while(front!=-1)
    {
      ptr=dequeue();
      if(ptr->l!=NILL)enqueue(ptr->l);
      if(ptr->r!=NILL)enqueue(ptr->r);
      if(ptr->color==RED)
	printf("(%d,RED,%d)",ptr->key,(ptr->p)->key);
      else if(ptr->color==BLACK)printf("(%d,BLACK,%d)",ptr->key,(ptr->p)->key);
    }
  printf("\n");
}

void left_rotate(int item)
{
  struct node *x,*y;
  x=search(item);
  if(x->r==NILL)printf("LR violation\n");
  y=x->r;
  x->r=y->l;
  if(y->l!=NILL)(y->l)->p=x;
  y->p=x->p;
  if(x->p==NILL)root=y;
  else if(x==(x->p)->p)(x->p)->l=y;
  else (x->p)->r=y;
  y->l=x;
  x->p=y;
}

void right_rotate(int item)
{
  struct node *x,*y;
  x=search(item);
  if(x->l==NILL)printf("RR violation\n");
  y=x->l;
  x->l=y->r;
  if(y->r!=NILL)(y->r)->p=x;
  y->p=x->p;
  if(x->p==NILL)root=y;
  else if(x==(x->p)->r)(x->p)->r=y;
  else (x->p)->l=y;
  y->r=x;
  x->p=y;
}

void RB_insert_fixup(struct node *z)
{
  struct node *y;
  while((z->p)->color==RED)
    {
      if((z->p)==(((z->p)->p)->l))
	{
	  y=(((z->p)->p)->r);
	  if(y->color==RED)
	    {
	      (z->p)->color=BLACK;
	      y->color=BLACK;
	      ((z->p)->p)->color=RED;
	      z=(z->p)->p;
	    }
	  else
	    {
	      if(z==(z->p)->r)
		{
		  z=z->p;
		  left_rotate(z->key);
		}
	      (z->p)->color=BLACK;
	      ((z->p)->p)->color=RED;
	      right_rotate(((z->p)->p)->key);
	    }
	}
      else
	{
	  y=(((z->p)->p)->l);
	  if(y->color==RED)
	    {
	      (z->p)->color=BLACK;
	      y->color=BLACK;
	      ((z->p)->p)->color=RED;
	      z=(z->p)->p;
	    }
	  else
	    {
	      if(z==(z->p)->l)
		{
		  z=z->p;
		  right_rotate(z->key);
		}
	      (z->p)->color=BLACK;
	      ((z->p)->p)->color=RED;
	      left_rotate(((z->p)->p)->key);
	    }
	}
    }
  root->color=BLACK;
}

void RB_insert(int item)
{
  struct node *x,*y,*z;
  if(search(item)!=NILL)
    {
      printf("item already exists\n");
      return;
    }
  z=(struct node *)malloc(sizeof(struct node));
  z->key=item;
  y=NILL;
  x=root;
  while(x!=NILL)
    {
      y=x;
      if(z->key<x->key)
	x=x->l;
      else
	x=x->r;
    }
  z->p=y;
  if(y==NILL)
     root=z;
  else
    if(z->key<y->key)
      y->l=z;
    else
      y->r=z;
  z->l=NILL;
  z->r=NILL;
  z->color=RED;
  RB_insert_fixup(z);
}

void RB_transplant(struct node *u,struct node *v)
{
  if(u->p==NILL)
    root=v;
  else
    if(u==(u->p)->l)
      (u->p)->l=v;
    else
      (u->p)->r=v;
       v->p=u->p;
}

struct node *tree_minimum(struct node *root)
{
  struct node *ptr;
  ptr=root;
  while(ptr->l!=NILL)
    ptr=ptr->l;
  return ptr;
}

void RB_delete_fixup(struct node *x)
{
  struct node *w;
  while(x!=root&&x->color==BLACK)
    {
      if(x==(x->p)->l)
	{
	  w=(x->p)->r;
	  if(w->color==RED)
	    {
	      w->color=BLACK;
	      (x->p)->color=RED;
	      left_rotate((x->p)->key);
	      w=(x->p)->r;
	    }
	  if((w->l)->color==BLACK&&(w->r)->color==BLACK)
	    {
	      w->color=RED;
	      x=x->p;
	    }
	  else
	    {
	      if((w->r)->color==BLACK)
		{
		  (w->l)->color=BLACK;
		  w->color=RED;
		  right_rotate(w->key);
		  w=(x->p)->r;
		}
	      w->color=(x->p)->color;
	      (x->p)->color=BLACK;
	      (w->r)->color=BLACK;
	      left_rotate((x->p)->key);
	      x=root;
	    }
	}
      else
	{
	  w=(x->p)->l;
	  if(w->color==RED)
	    {
	      w->color=BLACK;
	      (x->p)->color=RED;
	      right_rotate((x->p)->key);
	      w=(x->p)->l;
	    }
	  if((w->r)->color==BLACK&&(w->l)->color==BLACK)
	    {
	      w->color=RED;
	      x=x->p;
	    }
	  else
	    {
	      if((w->l)->color==BLACK)
		{
		  (w->r)->color=BLACK;
		  w->color=RED;
		  left_rotate(w->key);
		  w=(x->p)->l;
		}
	      w->color=(x->p)->color;
	      (x->p)->color=BLACK;
	      (w->l)->color=BLACK;
	      right_rotate((x->p)->key);
	      x=root;
	    }
	}
    }
  x->color=BLACK;
}

void RB_delete(int item)
{
  struct node *x,*y,*z;
  int y_original_color;
  z=search(item);
  if(z==NILL)
    {
      printf("Item not found\n");
      return;
    }
  y=z;
  y_original_color=y->color;
  if(z->l==NILL)
    {
      x=z->r;
      RB_transplant(z,z->r);
    }
  else
    if(z->r==NILL)
      {
	x=z->l;
	RB_transplant(z,z->l);
      }
    else
      {
	y=tree_minimum(z->r);
	y_original_color=y->color;
	x=y->r;
	if(y->p==z)
	  x->p=y;
	else
	  {
	    RB_transplant(y,y->r);
	    y->r=z->r;
	    (y->r)->p=y;
	  }
	RB_transplant(z,y);
	y->l=z->l;
	(y->l)->p=y;
	y->color=z->color;
      }
  if(y_original_color==BLACK)
    RB_delete_fixup(x);
}

main()
{
  int item;
  int ch,yn;
  NILL=(struct node *)malloc(sizeof(struct node ));
  NILL->color=BLACK;
  NILL->key=-1;
      NILL->l=NILL->r=NILL->p=NULL;
      root=(struct node *)malloc(sizeof(struct node));
      root->p=NILL;
      root=NILL;

do
  {
    printf("1:Insert\n2:Delete\n3:Print\nEnter the choice:");
    scanf("%d",&ch);
    switch(ch)
      {
      case 1:
	scanf("%d",&item);
	RB_insert(item);
	level_order();
	break;
      case 2:if(root==NILL)
	  {
	    printf("Cannot delete.Tree empty\n");
	    break;
	  }
	scanf("%d",&item);
	RB_delete(item);
	if(root==NILL)
	  printf("Tree empty\n");
	else
	  level_order();
	break;
      case 3:
	if(root==NILL)
	  printf("Tree empty\n");
	else
	  level_order();
	break;
      default:break;
      }
    printf("Press 1 to continue:");
    scanf("%d",&yn);
  }while(yn==1);
}

/*
			OUTPUT STATEMENT
1:Insert
2:Delete
3:Print
Enter the choice:1
1
(1,BLACK,-1)
Press 1 to continue:1
1:Insert
2:Delete
3:Print
Enter the choice:1
12
(1,BLACK,-1)(12,RED,1)
Press 1 to continue:1
1:Insert
2:Delete
3:Print
Enter the choice:1
7
(7,BLACK,-1)(1,RED,7)(12,RED,7)
Press 1 to continue:1
1:Insert
2:Delete
3:Print
Enter the choice:1
15
(7,BLACK,-1)(1,BLACK,7)(12,BLACK,7)(15,RED,12)
Press 1 to continue:1
1:Insert
2:Delete
3:Print
Enter the choice:1
18
(7,BLACK,-1)(1,BLACK,7)(15,BLACK,7)(12,RED,15)(18,RED,15)
Press 1 to continue:1
1:Insert
2:Delete
3:Print
Enter the choice:1
9
(7,BLACK,-1)(1,BLACK,7)(15,RED,7)(12,BLACK,15)(18,BLACK,15)(9,RED,12)
Press 1 to continue:1
1:Insert
2:Delete
3:Print
Enter the choice:1
20
(7,BLACK,-1)(1,BLACK,7)(15,RED,7)(12,BLACK,15)(18,BLACK,15)(9,RED,12)(20,RED,18)
Press 1 to continue:1
1:Insert
2:Delete
3:Print
Enter the choice:3
(7,BLACK,-1)(1,BLACK,7)(15,RED,7)(12,BLACK,15)(18,BLACK,15)(9,RED,12)(20,RED,18)
Press 1 to continue:1
1:Insert
2:Delete
3:Print
Enter the choice:1
8
(7,BLACK,-1)(1,BLACK,7)(15,RED,7)(9,BLACK,15)(18,BLACK,15)(8,RED,9)(12,RED,9)(20,RED,18)
Press 1 to continue:1
1:Insert
2:Delete
3:Print
Enter the choice:1
13
(9,BLACK,-1)(7,RED,9)(15,RED,9)(1,BLACK,7)(8,BLACK,7)(12,BLACK,15)(18,BLACK,15)(13,RED,12)(20,RED,18)
Press 1 to continue:1
1:Insert
2:Delete
3:Print
Enter the choice:3
(9,BLACK,-1)(7,RED,9)(15,RED,9)(1,BLACK,7)(8,BLACK,7)(12,BLACK,15)(18,BLACK,15)(13,RED,12)(20,RED,18)
Press 1 to continue:1
1:Insert
2:Delete
3:Print
Enter the choice:2
1
(9,BLACK,-1)(7,BLACK,9)(15,RED,9)(8,RED,7)(12,BLACK,15)(18,BLACK,15)(13,RED,12)(20,RED,18)
Press 1 to continue:1
1:Insert
2:Delete
3:Print
Enter the choice:3
(9,BLACK,-1)(7,BLACK,9)(15,RED,9)(8,RED,7)(12,BLACK,15)(18,BLACK,15)(13,RED,12)(20,RED,18)
Press 1 to continue:1
1:Insert
2:Delete
3:Print
Enter the choice:2
12
(9,BLACK,-1)(7,BLACK,9)(15,RED,9)(8,RED,7)(13,BLACK,15)(18,BLACK,15)(20,RED,18)
Press 1 to continue:2



*/

