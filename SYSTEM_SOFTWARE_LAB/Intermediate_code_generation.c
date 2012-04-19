#include<stdio.h>
#include<ctype.h>
#include<string.h>

int ISP(char a)
{
  switch(a)
    {
    case ')': return -2;
    case '^': return 3;
    case '*': return 2;
    case '/': return 2;
    case '+': return 1;
    case '-': return 1;
    case '(': return 0;
    case '$': return -1;
    }
}

int ICP(char a)
{
  switch(a)
    {
    case ')': return -2;
    case '^': return 4;
    case '*': return 2;
    case '/': return 2;
    case '+': return 1;
    case '-': return 1;
    case '(': return 4;
    case '$': return -1;
    }
}


void postfix(char in[],char p[])
{
  int i,j=0,top=0;
  char x,S[40];  
  S[0]='$';
  for(i=0;i<strlen(in);i++)
    {
      x=in[i];
      if(isalnum(x))p[j++]=x;
      else if(x==')')
	{
	  while(S[top]!='(')
	    p[j++]=S[top--];
	  top--;	
	}
      else
	{
	  while(ISP(S[top])>=ICP(x))p[j++]=S[top--];
	  S[++top]=x;	
	}
      
    }
  while(top>0) 
    p[j++]=S[top--];
  p[j]='\0';

}
int isoperator(char c)
{
  if(c=='*'||c=='+'||c=='-'||c=='/'||c=='^') return 1;
  else return 0;
}

void generate(char e[])
{
  char S[40],p[40];
  int t=1;
  int i,a,b,top=-1;
  
  postfix(e,p);
  
  for(i=0;p[i]!='\0';i++)
    {
      if(isalnum(p[i])) S[++top]=p[i];
      if(isoperator(p[i]))
	{
	  a=S[top--];
	  b=S[top--];	  
	  printf("T%d=",t);
	  if(b<30)printf("T%d",b);
	  else printf("%c",b);
	  printf("%c",p[i]);
	  if(a<30)printf("T%d\n",a);
	  else printf("%c\n",a);
	  S[++top]=t++;
	}
    }
  printf("T%d=",t);
  if(S[0]<30)printf("T%d\n",S[0]);
  else printf("%c\n",S[0]);
}


main()
{
  char str[50];
  char c;
  do   
    {
      printf("ENTER EXP\t:");
      scanf("%s",str);
      generate(str);
      scanf("%c",&c);
      printf("DO U WANT TO CONTINUE (y/n)\t:");
      scanf("%c",&c);
    }while(c=='Y'||c=='y');
}


/**
OUTPUT:
______

s0901@hp-5:~/s6$ gcc icode.c
s0901@hp-5:~/s6$ ./a.out 
ENTER EXP	:a+b*c/(b^5)
T1=b*c
T2=b^5
T3=T1/T2
T4=a+T3
T5=T4
DO U WANT TO CONTINUE (y/n)	:y
ENTER EXP	:a*b*c^a
T1=a*b
T2=c^a
T3=T1*T2
T4=T3
DO U WANT TO CONTINUE (y/n)	:n
s0901@hp-5:~/s6$ 


 */
