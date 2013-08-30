#include<stdio.h>
#include<stdlib.h>

#define INFINITY 99999
#define MAX_ROWS 10
#define MAX_COLS 10
#define MAX_MATRICES 20
int m[MAX_MATRICES][MAX_MATRICES],s[MAX_MATRICES][MAX_MATRICES];

void matrix_chain_order(int A[][MAX_ROWS][MAX_COLS],int n,int p[])
{
  int i,j,k;
  int l,q;


  for(i=0;i<n;i++)m[i][i]=0;

  for(l=2;l<=n;l++)
    {
      for(i=0;i<n-l+1;i++)
	{
	  j=i+l-1;
	  m[i][j]=INFINITY;
	  for(k=i;k<j;k++)
	    {
	      q=m[i][k]+m[k+1][j]+(p[i]*p[k+1]*p[j+1]);
	      if(q<m[i][j])
		{
		  m[i][j]=q;
		  s[i][j]=k;
		}
	    }
	}
    }
}

void print_tables(int n)
{
  int i,j;
  printf("TABLE M\n");
  for(i=0;i<n;i++)
    {
      for(j=0;j<n;j++)printf("%d ",m[i][j]);
      printf("\n");
    }
  printf("\n Table S\n");
  for(i=0;i<n-1;i++)
    {
      for(j=1;j<n;j++)printf("%d ",s[i][j]);
      printf("\n");
    }
  printf("\n");
}

void print_optimal_parens(int i,int j)
{
  if(i==j)
    {
      printf("A%d",i+1);
    }
  else
    {
      printf("(");
      print_optimal_parens(i,s[i][j]);
      print_optimal_parens(s[i][j]+1,j);
      printf(")");
    }      
}

void copy_matrix(int m1[][MAX_COLS],int r,int c,int m2[][MAX_COLS])
{
  int i,j;
  for(i=0;i<r;i++)
    for(j=0;j<c;j++)
      m2[i][j]=m1[i][j];    
}

void print_matrix(int m[][MAX_COLS],int r,int c)
{
  int i,j;
  for(i=0;i<r;i++)
    {
      for(j=0;j<c;j++)printf("%d ",m[i][j]);
      printf("\n");
    }

}

void matrix_multiply(int m1[][MAX_COLS],int r1,int c1,int m2[][MAX_COLS],int r2,int c2,int product[][MAX_COLS])
{
  int i,j,k;
  for(i=0;i<r1;i++)
    for(j=0;j<c2;j++)
      {
	product[i][j]=0;
	for(k=0;k<c1;k++)
	  product[i][j]+=m1[i][k]*m2[k][j];
      }
}

void chain_multiply(int A[][MAX_ROWS][MAX_COLS],int p[],int i,int j,int result[][MAX_COLS])
{
  if(i==j)
    {
      copy_matrix(A[i],p[i],p[i+1],result);
    }
  else if(i+1==j)
    {
      matrix_multiply(A[i],p[i],p[i+1],A[j],p[j],p[j+1],result);
    }
  else
    {
      int prod1[MAX_ROWS][MAX_COLS],prod2[MAX_ROWS][MAX_COLS];
      chain_multiply(A,p,i,s[i][j],prod1);
      chain_multiply(A,p,s[i][j]+1,j,prod2);
      matrix_multiply(prod1,p[i],p[s[i][j]+1],prod2,p[s[i][j]+1],p[j+1],result);
    }
}

main()
{
  int n,A[MAX_MATRICES][MAX_ROWS][MAX_COLS],p[MAX_MATRICES],res[MAX_ROWS][MAX_COLS];
  int i,j,k;
  printf("enter the no of matrices:");
  scanf("%d",&n);
  for(i=0;i<n;i++)
    {
      printf("Enter the dimensions of the matrix %d:",i+1);
      scanf("%d%d",&p[i],&p[i+1]);
      printf("enter the elements of matrix %d:\n",i+1);
      for(j=0;j<p[i];j++)
	for(k=0;k<p[i+1];k++)
	  scanf("%d",&A[i][j][k]);
    }
  matrix_chain_order(A,n,p);
  print_tables(n);
  printf("----OPTIMAL parenthesisation---\n");
  print_optimal_parens(0,n-1);
  printf("\nTotal no of multiplications=%d\n",m[0][n-1]);
  chain_multiply(A,p,0,n-1,res);
  printf("\n\n ---PRODUCT----\n");
  print_matrix(res,p[0],p[n]);
}


/*

			OUTPUT STATEMENT
enter the no of matrices:4
Enter the dimensions of the matrix 1:3 2
enter the elements of matrix 1:
1 2
2 3
3 1
Enter the dimensions of the matrix 2:2 3
enter the elements of matrix 2:
1 2 3
3 2 1
Enter the dimensions of the matrix 3:3 1
enter the elements of matrix 3:
1
2
3
Enter the dimensions of the matrix 4:1 3
enter the elements of matrix 4:
1 2 3
TABLE M
0 18 12 21 
0 0 6 12 
0 0 0 9 
0 0 0 0 

 Table S
0 0 2 
0 1 2 
0 0 2 

----OPTIMAL parenthesisation---
((A1(A2A3))A4)
Total no of multiplications=21


 ---PRODUCT----
34 68 102 
58 116 174 
52 104 156 


*/

