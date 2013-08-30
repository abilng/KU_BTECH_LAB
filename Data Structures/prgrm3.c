#include<stdio.h>
void trans(int a[][3]);
main()
{
  int a[50][3],b[50][3],c[100][3],d[50][3],i,j,t,k,m,n,ch;
do
  {
    printf("\n**MENU**\n1.Addition\n2.Transpose\n3.EXIT");
    printf("\nEnter your choice:");
    scanf("%d",&ch);
    switch(ch)
      {
      case 1:
	{
	  printf("\nEnter the number of rows and columns :");
	  scanf(" %d %d",&a[0][0],&a[0][1]);
	  b[0][0]=a[0][0];
		       b[0][1]=a[0][1];
	  printf("\nEnter the 1st matrix:");
	  k=1;
	  for(i=0;i<a[0][0];i++)
	    {
	      printf("Enter %dth row",i+1);
	      for(j=0;j<a[0][1];j++)
		{
		  scanf("%d",&t);
		  if(t)
		    {
		      a[k][0] = i;
		      a[k][1] = j;
		      a[k++][2] = t;
		    }
		}
	    }
	  a[0][2]=k-1;
	  ///trans(a);
	  //printf("\nEnter the number of rows and columns of 2nd matrix:");
	  //scanf("%d %d",&b[0][0],&b[0][1]);
	  printf("\nEnter the 2nd matrix:");
	  k=1;
	  for(i=0;i<b[0][0];i++)
	    {
	      printf("\nEnter %dth row:",i+1);
	      for(j=0;j<b[0][1];j++)
		{
		  scanf("%d",&t);
		  if(t)
		    {
		      b[k][0] = i;
		      b[k][1] = j;
		      b[k++][2] = t;
		    } 
		}
	    }
	  b[0][2] = k-1;
	  //Addition
	  if(a[0][0]==b[0][0] && a[0][1]==b[0][1])
	    {
	      c[0][0]=a[0][0];
	      c[0][1]=a[0][1];
	      i=j=k=1;
	      while(i<=a[0][2] && j<=b[0][2])
		{
		  if(a[i][0] == b[j][0] && a[i][1] ==b[j][1])
		    {
		      c[k][0]=a[i][0];
		      c[k][1]  = a[i][1];
		      c[k++][2] = a[i++][2] + b[j++][2];
		    }
		  if(a[i][0] == b[j][0] && a[i][1]<b[j][1])
		    {
		      c[k][0] = a[i][0];
		      c[k][1] = a[i][1];
		      c[k++][2] = a[i++][2];
		    }
		  if(a[i][0] == b[j][0] && a[i][1] > b[j][1])
		    {
		      c[k][0] = b[j][0];
		      c[k][1]=b[j][1];
		      c[k++][2]=b[j++][2];
		    }
		  if(a[i][0]<b[j][0])
		    {
		      c[k][0] = a[i][0];
		      c[k][1]=a[i][1];
		      c[k++][2]=a[i++][2];
		    }
		  if(a[i][0]>b[j][0])
		    {
		      c[k][0]=b[j][0];
		      c[k][1]=b[j][1];
		      c[k++][2]=b[j++][2];
		    }
		}
	      while(i<a[0][2])
		{
		  c[k][0]=a[i][0];
		  c[k][1]=a[i][1];
		  c[k++][2]=a[i++][2];
		}
	      while(j<b[0][2])
		{
		  c[k][0]=b[j][0];
		  c[k][1]=b[j][1];
		  c[k++][2]=b[j++][2];
		}
	      c[0][2] = k-1;
	    }
	  else printf("\n can\'t add ");
	  //End of addition
	  printf("\n The sum is \n");
	  k=1;
	  for(i=0;i<c[0][0];i++)
	    {
	      printf("\n");
	      for(j=0;j<c[0][1];j++)
		{
		  if(c[k][0]==i && c[k][1]==j)
		    printf("  %d",c[k++][2]);
		  else printf("  0");
		}
	    }
	  printf("\nIn Sparse");
	  for(i=0;i<=c[0][2];i++)
	    {
	      printf("\n");
	      for(j=0;j<3;j++)
		printf("  %d",c[i][j]);
	    }
	  break;
	}//end of ch==1
      case 2:
	{
	  printf("\nEnter the Number of rows and columns:");
	  scanf(" %d %d",&d[0][0],&d[0][1]);
	  k=1;
	  for(i=0;i<d[0][0];i++)
	    {
	      printf("\nEnter %dth row:",i+1);
	    for(j=0;j<d[0][1];j++)
	      {
		scanf("%d",&t);
		if(t)
		  {
		    d[k][0]=i;
		    d[k][1]=j;
		    d[k++][2]=t;		  }
	      }
	    }
	  d[0][2]=k-1;
	  trans(d);
	  break;
	}//end of ch=2
      case 3:
	break;
      default:
	printf("\nInvalid choice TryAgain!!");
	break;
      }
  }while(ch!=3);
}
void trans(int a[][3])
{
  int m,n,i,j,k,tr[50][3],s[50],term,t[50];
 tr[0][2] = term = a[0][2];
  tr[0][1] = m = a[0][0];
  tr[0][0] = n = a[0][1];
  for(i=1;i<n;i++)
    s[i]=0;
  for(i=1;i<=term;i++)
    s[a[i][1]]=s[a[i][1]]+1;
  t[0]=1;
  for(i=1;i<n;i++)
    t[i]=t[i-1]+s[i-1];
  for(i=1;i<=term;i++)
    {
      j=a[i][1];
      tr[t[j]][0] = a[i][1];
      tr[t[j]][1] = a[i][0];
      tr[t[j]][2] = a[i][2];
      t[j]=t[j]+1;
    }
  printf("\nthe transpose is\n");
  k=1;
  for(i=0;i<tr[0][0];i++)
    {
      printf("\n");
      for(j=0;j<tr[0][1];j++)
	{
	  if(tr[k][0]==i && tr[k][1]==j)
	    printf("  %d",tr[k++][2]);
	  else printf("  0");
	}
    }
  printf("\nIn sparse");
  for(i=0;i<=tr[0][2];i++)
    {
      printf("\n");
      for(j=0;j<3;j++)
	printf("  %d",tr[i][j]);
    }
}
