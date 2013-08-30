#include<stdio.h>
main()
{
  int a[30],b[30],c[60],d[70],i,j,k,temp,temp1,ch,choice;
  
    printf("Enter the number of nonzero terms in 1st polynomial:");
    scanf("%d",&a[0]);
    printf("\nEnter the 1st polynomial:");
    i=1;
    while(i<(2*a[0]+1))
      {
	printf("\nExponent:");
	scanf("%d",&a[i]);
	printf("\nCoefficient:");
	scanf("%d",&a[i+1]);
	i=i+2;
      }
    printf("\nEnter the number of non zero terms in 2nd polynomial:");
    scanf("%d",&b[0]);
    printf("\nEnter the 2nd polynomial:");
    i=1;
    while(i<(2*b[0]+1))
      {
	printf("\nEnter Exponent:");
	scanf("%d",&b[i]);
	printf("\nEnter coefficient:");
	scanf("%d",&b[i+1]);
	i=i+2;
    }
    do{
      
      printf("\n**MENU**\n 1.SUM \n2.PRODUCT\nEnter your choice:");
      scanf("%d",&ch);
      switch(ch)
	{
	case 1:
	  {
	    i = j = k = 1;
	    while(i<(2*a[0]+1) && j<(2*b[0]+1))
	      {
		if(a[i]>b[j])
		  {
		    c[k] = a[i];
		    c[k+1] = a[i+1];
		    k=k+2;
		    i=i+2;
		  }
		if(b[j]>a[i])
		  {
		    c[k] = b[j];
		    c[k+1] = b[j+1];
		    j = j+2;
		    k = k+2;
		  }
		if(a[i]==b[j])
		  {
		    c[k] = a[i];
		    c[k+1] = a[i+1] + b[j+1];
		    k=k+2;
		    i=i+2;
		    j=j+2;
		  }
	      }
	    while(i<(2*a[0]+1))
	      {
		c[k] = a[i];
		c[k+1] = a[i+1];
		k=k+2;
		i=i+2;
	      }
	    while(j<(2*b[0]+1))
	      {
		c[k] = b[j];
		c[k+1] = b[j+1];
		k=k+2;
		j=j+2;
	      }
	    c[0] = (k-1)/2;
	    printf("\nThe sum is:\n");
	    i=1;
	    while(i<(2*c[0]+1))
	      {
		printf("  %d X^%d",c[i+1],c[i]);
		i=i+2;
		if(i<(2*c[0]+1))
		  printf(" + ");
	      }
	    printf("\n");
	    break;
	  }
	case 2:
	  {
	    i=j=k=1;
	    while(i<2*a[0]+1)
	      {
		j=1;
		while(j<2*b[0]+1)
		  {
		    d[k] = a[i] + b[j];
		    d[k+1] = a[i+1] * b[j+1];
		    k=k+2;
		    j=j+2;
		  }
		i=i+2;
	      }
	    d[0] = (k-1)/2;
	    i=1;
	    while(i<2*d[0]-1)
	      {
		j=i+2;
		while(j<2*d[0]+1)
		  {
		    if(d[i]<d[j])
		      {
			temp = d[i];
			temp1=d[i+1];
			d[i] = d[j];
			d[i+1] = d[j+1];
			d[j]=temp;
			d[j+1]=temp1;
		      }
		    j=j+2;
		  }
		i=i+2;
	      }
	    i=1;
	    while(i<2*d[0]-1)
	      {
		j=i+2;
		while(j<2*d[0]+1)
		  {
		    if(d[i]==d[j])
		      {
			d[i+1]=d[i+1]+d[j+1];
		      d[j+1]=0;
		      }
		  j=j+2;
		  }
	      i=i+2;
	      }
	    i=1;
	    printf("\nThe product is\n");
	    while(i<2*d[0]+1)
	      {
		if(d[i+1])
		  {
		    printf(" %d X^%d ",d[i+1],d[i]);
		  }
		i=i+2;
		if(i<2*d[0] && d[i+1])
		  printf("+");
	      }
	    printf("\n");
	    break;
	  }
	default:
	{
	  printf("\nInavlid choice Try Again!!"); 
	  break;
	}
	}//end of switch
      printf("\nDo you want to continue ? (1 or 0):");
      scanf("%d",&choice);
    }while(choice!= 0 );
  }
