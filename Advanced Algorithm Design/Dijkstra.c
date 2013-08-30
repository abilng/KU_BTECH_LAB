#include<stdio.h>
#include<stdlib.h>

#define INFINITY 9999
int node_info[20][2];
int queue[20],nq=0;

void create_directed_graph(int G[][20],int no_of_nodes)
{
  int i,j,no_of_edges,v1,v2,weight;
  for(i=0;i<no_of_nodes;i++)
    {
      for(j=0;j<no_of_nodes;j++)
	{
	  G[i][j]=0;
	}
    }

  printf("\n enter no_of edges:");
  scanf("%d",&no_of_edges);
  printf("\n enter the edges as (v1,v2,weight)triplets\n");

  for(i=0;i<no_of_edges;i++)
    {
      scanf("%d%d%d",&v1,&v2,&weight);
      G[v1][v2]=weight;
    }
}
void print_graph(int G[][20],int no_of_nodes)
{
  int i,j;
  for(i=0;i<no_of_nodes;i++)
    {
      printf("%d--->",i);
      for(j=0;j<no_of_nodes;j++)
	{
	  if(G[i][j]!=0)
	    {
	      printf("(%d,%d) ",j,G[i][j]);
	    }
	}
      printf("\n");
    }
  printf("\n");

}
void initialise_single_source(int G[][20],int no_of_nodes,int vertex)
{
  int i;
  for(i=0;i<no_of_nodes;i++)
    {
      node_info[i][0]=INFINITY;
      node_info[i][1]=-1;

    }
  node_info[vertex][0]=0;
}
void relax(int u,int v,int weight)
{
  if(node_info[v][0]>node_info[u][0]+weight)
    {
      node_info[v][0]=node_info[u][0]+weight;
      node_info[v][1]=u;

    }
}



void dijkstra(int G[][20],int no_of_nodes,int source_vertex)
{
  int i,u;
  initialise_single_source(G,no_of_nodes,source_vertex);

  for(i=0;i<no_of_nodes;i++)
    {
      queue[i]=i;
    }
  nq=no_of_nodes;
  while(nq!=0)
    {
      u=extract_min();
      for(i=0;i<no_of_nodes;i++)
	{
	  if(G[u][i]!=0)
	    relax(u,i,G[u][i]);
	 }

     }

}

int extract_min()
{
  int i,min=INFINITY,min_node=-1,pos=-1;
  for(i=0;i<nq;i++)
    {
      if(node_info[queue[i]][0]<min)
	{
	  min=node_info[queue[i]][0];
	  min_node=queue[i];
	  pos=i;
	}
    }
  for(i=pos;i<nq-1;i++)
  queue[i]=queue[i+1];
      nq--;
      return min_node;
  }









void print_shortest_path_to(int dest)
{
 if(node_info[dest][1]==-1)
        printf("%d ",dest);
  else
       {
	 print_shortest_path_to(node_info[dest][1]);
	 printf("---->%d ",dest);
       }

 }
  void print_all_shortest_paths(int G[][20],int no_of_nodes)
{
  int i;
  printf("------SHORTEST PATHS-----------\n");
  for(i=0;i<no_of_nodes;i++)
    {
      printf("SHORTEST PATH TO %d: ",i);
      print_shortest_path_to(i);
      printf("\nPathlength=%d\n\n",node_info[i][0]);
    }
  printf("\n");
}

main()
{
  int G[20][20],no_of_nodes,source_vertex;


  printf("\n enter the no of nodes:");
  scanf("%d",&no_of_nodes);

  create_directed_graph(G,no_of_nodes);
  printf("\n..ORIGINAL GRAPH...\n");
  print_graph(G,no_of_nodes);



  printf("\n enter the source vertex:");
  scanf("%d",&source_vertex);
  dijkstra(G,no_of_nodes,source_vertex);



  print_all_shortest_paths(G,no_of_nodes);
}


/*
			OUTPUT STATEMENT
 enter the no of nodes:5

 enter no_of edges:10

 enter the edges as (v1,v2,weight)triplets
0 1 10
0 3 5
1 3 2
3 1 3
1 2 1
3 2 9
3 4 2
2 4 4
4 2 6
4 0 7

..ORIGINAL GRAPH...
0--->(1,10) (3,5) 
1--->(2,1) (3,2) 
2--->(4,4) 
3--->(1,3) (2,9) (4,2) 
4--->(0,7) (2,6) 


 enter the source vertex:0
------SHORTEST PATHS-----------
SHORTEST PATH TO 0: 0 
Pathlength=0

SHORTEST PATH TO 1: 0 ---->3 ---->1 
Pathlength=8

SHORTEST PATH TO 2: 0 ---->3 ---->1 ---->2 
Pathlength=9

SHORTEST PATH TO 3: 0 ---->3 
Pathlength=5

SHORTEST PATH TO 4: 0 ---->3 ---->4 
Pathlength=7



*/

