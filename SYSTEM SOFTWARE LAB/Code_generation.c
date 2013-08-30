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
  if(c=='*'||c=='+'||c=='-'||c=='/') return 1;
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
	  if(b<30) printf("LDA T%d\n",b);
	  else if(isdigit(b)) printf("LDA #%c\n",b);
	  else printf("LDA  %c\n",b);
	  switch(p[i])
	    {
	    case '*':
	      if(a<30) printf("MUL T%d\n",a);
	      else if(isdigit(a)) printf("MUL #%c\n",a);
	      else printf("MUL %c\n",a);
	      break;
	    case '/':
	      if(a<30)printf("DIV T%d\n",a);
	      else if(isdigit(a)) printf("DIV #%c\n",a);
	      else printf("DIV %c\n",a);
	      break;
	    case '+':
	      if(a<30)printf("ADD T%d\n",a);
	      else if(isdigit(a)) printf("ADD #%c\n",a);
	      else printf("ADD %c\n",a);
	      break;
	    case '-':
	      if(a<30)printf("SUB T%d\n",a);
	      else if(isdigit(a)) printf("SUB #%c\n",a);
	      else printf("SUB %c\n",a);
	      break;
	    }
	  printf("STA T%d\n",t);
	  S[++top]=t++;
	}
    }
  //  printf("T%d=",t);
  // if(S[0]<30)printf("LDA T%d\n",S[0]);
  // else printf("LDA %c\n",S[0]);
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
   ------

   s0901@hp-5:~/s6$ gcc codegen.c
   s0901@hp-5:~/s6$ ./a.out 
   ENTER EXP	:a+b*t+(t/2)
   LDA  b
   MUL t
   STA T1
   LDA  a
   ADD T1
   STA T2
   LDA  t
   DIV #2
   STA T3
   LDA T2
   ADD T3
   STA T4
   DO U WANT TO CONTINUE (y/n)	:n
   s0901@hp-5:~/s6$ 
   
 */
