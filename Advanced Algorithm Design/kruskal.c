#include<stdio.h>
#include<stdlib.h>

int edge_list[30][3],edge_list_size=0;
int forest[30][30],forest_size=0;

void create_graph(int G[][20],int no_of_nodes)
{
  int i,j;
  int no_of_edges;
  int v1,v2,weight;
  
  for(i=0;i<no_of_nodes;i++)
    for(j=0;j<no_of_nodes;j++)G[i][j]=0;

  printf("\n Enter the number of edges");
  scanf("%d",&no_of_edges);
  printf("Enter the edges as (v1,v2,weight)triplets\n");
  for(i=0;i<no_of_edges;i++)
    {
      scanf("%d%d%d",&v1,&v2,&weight);
      G[v1][v2]=G[v2][v1]=weight;
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
	  if(G[i][j]!=0)printf("(%d.%d)",j,G[i][j]);
	}
      printf("\n");
    }
  printf("\n");
}

void insert_into_edge_list(int v1,int v2,int weight)
{
  int i,j;
  int pos;
  pos=edge_list_size;
  for(i=0;i<edge_list_size;i++)
    {
      if(edge_list[i][2]>weight)
	{
	  pos=i;
	  for(j=edge_list_size-1;j>=i;j--)
	    {
	      edge_list[j+1][0]=edge_list[j][0];
	      edge_list[j+1][1]=edge_list[j][1];
	      edge_list[j+1][2]=edge_list[j][2];
	    }
	  break;
	}
    }
  edge_list[pos][0]=v1;
  edge_list[pos][1]=v2;
  edge_list[pos][2]=weight;
  edge_list_size++;
}

void get_sorted_edge_list(int G[][20],int no_of_nodes)
{
  int i,j;

  for(i=0;i<no_of_nodes-1;i++)
    for(j=i+1;j<no_of_nodes;j++)
      if(G[i][j]!=0)insert_into_edge_list(i,j,G[i][j]);

}
void print_edge_list()
{
  int i;

  for(i=0;i<edge_list_size;i++)
    printf("%d%d:%d\n",edge_list[i][0],edge_list[i][1],edge_list[i][2]);

}

void make_set(int vertex)
{
  forest[forest_size][0]=1;
  forest[forest_size][1]=vertex;
  forest_size++;
}

int find_set(int vertex)
{
  int i,j;

  for(i=0;i<forest_size;i++)
    for(j=1;j<=forest[i][0];j++)
      if(forest[i][j]==vertex)return i;

}
void unite(int v1,int v2)
{
  int i,j;
  int p1,p2;
  int smaller,larger;

  p1=find_set(v1);
  p2=find_set(v2);

  smaller=(p1<p2)?p1:p2;
  larger=(p1<p2)?p2:p1;

  for(i=1;i<=forest[larger][0];i++)forest[smaller][++forest[smaller][0]]=forest[larger][i];

  for(i=larger;i<forest_size-1;i++)
    {

      for(j=0;j<=forest[i+1][0];j++)forest[i][j]=forest[i+1][j];

    }
  forest_size--;
}
void print_forest()
{
  int i,j;
  for(i=0;i>forest_size;i++)
    {
      for(j=1;j<=forest[i][0];j++)
	printf("%d",forest[i][j]);
	
	printf("\n");

    }
  printf("\n");
}

void MST_kruskal(int G[][20],int no_of_nodes,int mst[][20])
{
  int i,j;
  int u,v;

  for(i=0;i<no_of_nodes;i++)
    for(j=0;j<no_of_nodes;j++)
      mst[i][j]=0;

  for(i=0;i<no_of_nodes;i++)make_set(i);
  get_sorted_edge_list(G,no_of_nodes);
  for(i=0;i<edge_list_size;i++)
    {
      u=edge_list[i][0];
      v=edge_list[i][1];
      if(find_set(u)!=find_set(v))
	{
	  mst[u][v]=mst[v][u]=edge_list[i][2];
	  unite(u,v);
	}
    }
}

main()
{
  int G[20][20],no_of_nodes,mst[20][20];

  printf("Enter no.of nodes:");
  scanf("%d",&no_of_nodes);
  create_graph(G,no_of_nodes);
  printf("---Original graph---\n");
  print_graph(G,no_of_nodes);

  MST_kruskal(G,no_of_nodes,mst);
  printf("----Mst---\n");
  print_graph(mst,no_of_nodes);
}

/* OUTPUT

Enter no.of nodes:9

 Enter the number of edges14
Enter the edges as (v1,v2,weight)triplets
0 1 4
1 2 8
2 3 7
3 4 9
4 5 10
5 6 2
6 7 1
7 0 8
7 1 11
7 8 7
8 2 2
8 6 6
2 5 4
3 5 14
---Original graph---
0--->(1.4)(7.8)
1--->(0.4)(2.8)(7.11)
2--->(1.8)(3.7)(5.4)(8.2)
3--->(2.7)(4.9)(5.14)
4--->(3.9)(5.10)
5--->(2.4)(3.14)(4.10)(6.2)
6--->(5.2)(7.1)(8.6)
7--->(0.8)(1.11)(6.1)(8.7)
8--->(2.2)(6.6)(7.7)

----Mst---
0--->(1.4)(7.8)
1--->(0.4)
2--->(3.7)(5.4)(8.2)
3--->(2.7)(4.9)
4--->(3.9)
5--->(2.4)(6.2)
6--->(5.2)(7.1)
7--->(0.8)(6.1)
8--->(2.2)

*/
