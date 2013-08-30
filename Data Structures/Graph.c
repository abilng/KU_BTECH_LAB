#include<stdio.h>
#include<stdlib.h>
int itemq,front=-1,rear=-1,nq=30,nv=0,ns=30,top=-1,nvis=0,items;
struct header
{
  int data;
  struct node *r;
  struct header *d;
}*head=NULL;

struct node 
{
  int data;
  struct node *link;
};

void print()
{
  struct header *ptr;
  struct node *ptr1;
  printf("Adjaceny List\n");
  ptr=head;
  while(ptr!=NULL)
    {
      printf("Adjacent elements of %d:",ptr->data);
      ptr1=ptr->r;
      while(ptr1!=NULL)
		{
			printf("%d ",ptr1->data);
			ptr1=ptr1->link;
		}
      ptr=ptr->d;
      printf("\n");
    }
}
void create()
{
  struct header *ptr,*new;
  struct node *ptr1,*n;
  int ch,num,i;
  ptr=head;
  printf("Enter the nodes\n");
  do
    {
      new=(struct header *)malloc(sizeof(struct header));
      scanf("%d",&new->data);
      new->d=NULL;
      new->r=NULL;
      if(head==NULL)head=new;
      else ptr->d=new;
      ptr=new;
      printf("more elements ?(press 1.Yes or 2.No):");
      scanf("%d",&ch);
    }while(ch==1);
  ptr=head;
  while(ptr!=NULL)
    {
      printf("Number of adjacent nodes for %d ?:",ptr->data);
      scanf("%d",&num);
      
	
	  ptr1=ptr->r;
	  printf("Enter adjacent nodes of %d:",ptr->data);
	  for(i=0;i<num;i++)
	    {
	      n=(struct node *)malloc(sizeof(struct node));
	      scanf("%d",&n->data);
	      n->link=NULL;
	      if(ptr->r==NULL)ptr->r=n;
	      else ptr1->link=n;
	      ptr1=n;
	      // printf("more elements?(press 1.Yes or 2.No):");
	      //scanf("%d",&ch);
	    }
	
      ptr=ptr->d;
    }
}
void enqueue(int queue[],int item)
{
  if(rear==nq-1)
    {
      printf("Queue full error\n");
      return;
    }
  if(rear==-1)
    front=rear=0;
  else
    rear++;
  queue[rear]=item;
}
void dequeue(int queue[])
{
  if(front==-1)
    {
      printf("QUEUE empty error\n");
      return;
    }
  itemq=queue[front];
  if(front==rear)
    front=rear=-1;
  else
    front++;
}
int search(int visit[],int item)
{
  int i,flag=0;
  for(i=0;i<nv;i++)
    {
      if(visit[i]==item){ flag=1; return 1;}
    }
  if(flag!=1)return 0;
}
void insert(int visit[],int item)
{
  int i;
  visit[nv]=item;
  nv++;
}
struct node *find_ptr(int item)
{
  struct header *ptr;
  ptr=head;
  while(ptr!=NULL)
    {
      if(ptr->data==item)return ptr->r;
      ptr=ptr->d;
    }
}
void push(int stack[],int item)
{
  if(top==ns-1){ printf("STACK overflow error\n"); return ;}
  top++;
  stack[top]=item;
}
void pop(int stack[])
{
  if(top==-1){ printf("STACK underflow error\n"); return;}
  items=stack[top];
  top--;
}
void DFS(int v,int stack[],int vis[])
{
  int u;
  struct node *ptr;
  if(head==NULL){ printf("Graph empty\n"); return;}
  printf("DFS Traversal\n");
  u=v;
  push(stack,u);
  while(top!=-1)
    {
      pop(stack);
      u=items;
      if((search(vis,u))==0)
	{
	  insert(vis,u);
	  printf("%d ",u);
	  ptr=find_ptr(u);
	  while(ptr!=NULL)
	    {
	      push(stack,ptr->data);
	      ptr=ptr->link;
	    }
	}
    }
  printf("\n");
}
void BFS(int v,int queue[],int visit[])
{
  int u;
  struct node *ptr;
  if(head==NULL){ printf("Graph empty\n"); return;}
  printf("BFS Traversal\n"); 
  u=v;
  enqueue(queue,u);
  while(front!=-1)
    {
      dequeue(queue);
      u=itemq;
      if((search(visit,u))==0)
	  {
		insert(visit,u);
		printf("%d ",u);
		ptr=find_ptr(u);
		while(ptr!=NULL)
	    {
	      enqueue(queue,ptr->data);
	      ptr=ptr->link;
	    }
	  }
    }
  printf("\n");
}
void main()
{
  int queue[30],visit[30],stack[30],vis[30];
  create();
  print();
  BFS(head->data,queue,visit);
  DFS(head->data,stack,vis);
}
