#include<stdio.h>
#include<stdlib.h>

struct header_node
{
  int data;
  struct list_node *r;
  struct header_node *d;
};

struct list_node
{
  int data;
  struct list_node *r;
};

int front=-1,rear=-1,QUEUE_SIZE=100,top=-1,STACK_SIZE=100,nv=0;

void create_graph(struct header_node **Gptr)
{
  struct header_node *ptr,*new;
  struct list_node *ptr1,*new1;
  int ch,yn,n,n1;
  int i,j;

  *Gptr=NULL;
   ptr=NULL;
   printf("Enter no of nodes:");
   scanf("%d",&n);
   printf("Enter nods of graph one by one\n");

   for(i=0;i<n;i++)
     {
       new=(struct header_node *)malloc(sizeof(struct header_node));
       scanf("%d",&new->data);
       new->r=NULL;
       new->d=NULL;
       if(*Gptr==NULL)*Gptr=new;
       else ptr->d=new;
       ptr=new;
     }

   ptr=*Gptr;
   while(ptr!=NULL)
     {
       printf("Enter no of adjacent nodes for %d:",ptr->data);
       scanf("%d",&n1);
       ptr1=ptr->r;
       printf("Enter adjacent nodes for %d:",ptr->data);
       for(i=0;i<n1;i++)
	 {
	   new1=(struct list_node *)malloc(sizeof(struct list_node));
	   scanf("%d",&new1->data);
	   new1->r=NULL;
	   if(ptr->r==NULL)ptr->r=new1;
	   else ptr1->r=new1;
	   ptr1=new1;
	 }
       ptr=ptr->d;
     }

}

void print_graph(struct header_node *Gptr)
{
  struct header_node *ptr;
  struct list_node *ptr1;

  printf("Adjacent List\n");
  ptr=Gptr;
  while(ptr!=NULL)
    {
      printf("Adjacent elements of %d: ",ptr->data);
      ptr1=ptr->r;
      while(ptr1!=NULL)
	{
	  printf("%d ",ptr1->data);
	  ptr1=ptr1->r;
	}
      printf("\n");
      ptr=ptr->d;
    }
  printf("\n");
}

void enqueue(int queue[],int item)
{
  if(rear==QUEUE_SIZE-1){printf("Queue full error\n"); exit(1);}
  if(rear==-1)front=rear=0;
  else rear++;
  queue[rear]=item;
}


int dequeue(int queue[])
{
  int item;
  if(front==-1){printf("Queue empty error\n"); exit(1);}
  item=queue[front];
  if(front==rear)front=rear=-1;
  else front++;
  return item;
}

void push(int stack[],int item)
{
  if(top==STACK_SIZE-1){printf("Stack overflow error\n"); exit(1);}
  top++;
  stack[top]=item;
}

int pop(int stack[])
{
  int item;
  if(top==-1){printf("Stack underflow error\n"); exit(1);}
  item=stack[top];
  top--;
  return item;
}

int search(int visit[],int item)
{
  int i;
  for(i=0;i<nv;i++)
    if(visit[i]==item)return 1;
  return 0;

}

void insert(int visit[],int item)
{
  visit[nv++]=item;
}

struct list_node *find_ptr(struct header_node *Gptr,int item)
{
  struct header_node *ptr;
  ptr=Gptr;
  while(ptr!=NULL)
    {
      if(ptr->data==item)return ptr->r;
      ptr=ptr->d;
    }
}


void DFS(struct header_node *Gptr)
{
  int u,stack[100],visit[100],start_vertex;
  struct list_node *ptr;

  top=-1;
  nv=0;
  if(Gptr==NULL){printf("Graph Empty\n"); return;}
  printf("Enter the start vertex:");
  scanf("%d",&start_vertex);
  printf("DFS traversal\n\n");
  u=start_vertex;
  push(stack,u);
  while(top!=-1)
    {
      u=pop(stack);
      if(search(visit,u)==0)
	{
	  insert(visit,u);
	  printf("%d ",u);
	  ptr=find_ptr(Gptr,u);
	  while(ptr!=NULL)
	    {
	      push(stack,ptr->data);
	      ptr=ptr->r;
	    }
	}
    }
 printf("\n");

}

void BFS(struct header_node *Gptr)
{
  int u,queue[100],visit[100],start_vertex;
  struct list_node *ptr;

  front=rear=-1;
  nv=0;
  if(Gptr==NULL){printf("Graph Empty\n"); return;}
  printf("Enter the start vertex:");
  scanf("%d",&start_vertex);
  printf("BFS traversal\n\n");
  u=start_vertex;
  enqueue(queue,u);
  while(front!=-1)
    {
      u=dequeue(queue);
      if(search(visit,u)==0)
	{
	  insert(visit,u);
	  printf("%d ",u);
	  ptr=find_ptr(Gptr,u);
	  while(ptr!=NULL)
	    {
	      enqueue(queue,ptr->data);
	      ptr=ptr->r;
	    }
	}
    }
 printf("\n");

}


main()
{
  struct header_node *G;
  create_graph(&G);
  print_graph(G);
  DFS(G);
  BFS(G);
}





/*


				OUTPUT STATEMENT
Enter no of nodes:6
Enter nods of graph one by one
1
2
3
4
5
6
Enter no of adjacent nodes for 1:2
Enter adjacent nodes for 1:2 6
Enter no of adjacent nodes for 2:2
Enter adjacent nodes for 2:1 3
Enter no of adjacent nodes for 3:2
Enter adjacent nodes for 3:2 4
Enter no of adjacent nodes for 4:2
Enter adjacent nodes for 4:3 5
Enter no of adjacent nodes for 5:2
Enter adjacent nodes for 5:4 6
Enter no of adjacent nodes for 6:2
Enter adjacent nodes for 6:1 5
Adjacent List
Adjacent elements of 1: 2 6 
Adjacent elements of 2: 1 3 
Adjacent elements of 3: 2 4 
Adjacent elements of 4: 3 5 
Adjacent elements of 5: 4 6 
Adjacent elements of 6: 1 5 

Enter the start vertex:1
DFS traversal

1 6 5 4 3 2 
Enter the start vertex:1
BFS traversal

1 2 6 3 5 4 


*/



