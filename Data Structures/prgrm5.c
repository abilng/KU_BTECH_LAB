#include<stdio.h>
#include<string.h>
#include<ctype.h>
int isp(char opr)
{
  if(opr=='(' || opr=='#') return -1;
  if(opr=='^') return 3;
  if(opr=='*' || opr=='/') return 2;
  if(opr=='+'||opr=='-') return 1;
  if(opr==')') return 0;
}
int icp(char opr) 
{
  if(opr=='^') return 3;
  if(opr=='*' || opr=='/') return 2;
  if(opr=='+' || opr=='-') return 1;
  if(opr=='(') return 4;
}
main()
{
  char in[30],i,len,post[30],opr[30],ch1,ch2;
  int ans[20],post_top=-1,opr_top=-1,ans_top=-1;
  int val;
  printf("\nEnter the expression:");
  gets(in);
  opr[++opr_top]='#';
  for(i=0;i<strlen(in);i++)
    {
      ch1=in[i];
      printf("Token %c \n",ch1);
      if(ch1=='#')
	{
	}
      if(ch1=='+' || ch1=='-'|| ch1=='*' || ch1=='/'|| ch1=='^')
	{
	  if(icp(ch1)>isp(opr[opr_top]))
	    {
	      printf("~");
	      opr[++opr_top]=ch1;
	    }
	  else
	    {
	      printf("!");
	      while(icp(ch1) <= isp(opr[opr_top]))
		{
		  post[++post_top]=opr[opr_top--];
		}
	      opr[++opr_top]=ch1;
	    }
	}
      if(ch1==')')
	{
	  while(opr[opr_top] != '(' )
	    {
	      post[++post_top]=opr[opr_top--];
	    }
	  opr_top--;
	}
      if(ch1=='(')
	{
	  opr[++opr_top]=ch1;
	}
      if(ch1>='a' && ch1<='z')
	{
	  post[++post_top]=ch1;
	}      
      post[post_top+1]='\0';
      opr[opr_top+1]='\0';
      puts(post);
      puts(opr);
    }
  while(opr[opr_top] != '#')
    {
      post[++post_top]=opr[opr_top--];
    }
  opr[0] ='\0';
  post[post_top+1] = '\0';
  printf("\n");
  puts(post);
  for(i=0;i<=post_top;i++)
    {
     ch1=post[i];
     printf("\n");
     if((ch1>= 'a') && (ch1 <= 'z'))
      {
	printf("Enter the value of %c  \n",ch1);
	scanf("%d",&val);
	ans[++ans_top] = val;
      }
     if(ch1 =='+')
       {
	 ans[ans_top-1]=ans[ans_top-1]+ans[ans_top];
	 ans_top--;
      }
     if(ch1 == '-')
     {
       ans[ans_top-1] = ans[ans_top-1]-ans[ans_top];
       ans_top--;
     }
     if(ch1 == '*')
       {
	 ans[ans_top-1] = ans[ans_top-1]*ans[ans_top];
	 ans_top--;
	 //printf("3");
       }
     if(ch1=='/')
       {
	 ans[ans_top-1] = ans[ans_top-1]/ans[ans_top];
	 ans_top--;
       }
   }
  printf("Result %d\n",ans[0]);
}

