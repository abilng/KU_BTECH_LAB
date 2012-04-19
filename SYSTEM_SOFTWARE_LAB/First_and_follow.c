#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct nonterminal
{
  char S;
  char exp[10][20];
  int noofexp;
  char first[20];
  char follow[20];
  int fc;
  int folc;
}nonterminals[20];

int noofpro=0;
char terminals[20];
int noofter=0;
FILE *in;

void print_first();
void print_follow();
void first_follow();
int insert(int P,char c,int type);
void find_all_firsts();
void find_all_follows();
int isterminal(char s);
int getpro(char s);
void readpro();
void first(int i);
void follow(int i);

main(int argc,char * argv[])
{
  char * filename;
  char str[100];
  int  proceed =0;
  if(argc != 2) 
    {
      printf("ERROR!:No input file\n");
      abort();
    }
  filename=argv[1];
  if(open_file(filename)!=0)
    {
      exit(0);
    }
  //  terminals[0]='$';
  first_follow();
  //  fclose(out);
  fclose(in);
}
int open_file(char *filename)
{
  char outfile[20];
  in=fopen(filename,"r");
  if(in==NULL)
    {
      printf("ERROR!:No input file:%s\n",filename );
      return 1;
    }
 return 0;
}

void first_follow()
{
  readpro();
  find_all_firsts();
  find_all_follows();
  print_first();
  print_follow();
 }


int isterminal(char s)
{
  int i;
  for(i=0;i<noofter;i++)
    if(s==terminals[i]) return i;  
  return -1;
}

int getpro(char s)
{
  int i;
  for(i=0;i<noofpro;i++)
    if(s==nonterminals[i].S) return i;  
  return -1;
}
void readpro()
{
  int i,len,j;
  //int k;
  char s[100];
  char *k;
  while(fgets(s,100,in))
    {
      k=strchr(s+3,';');
      if(k!=0) strcpy(k,"\0\0");    
      i=getpro(s[0]);
      if(i<0)
	{
	  nonterminals[noofpro].S=s[0];
	  nonterminals[noofpro].fc=0;  
	  nonterminals[noofpro].folc=0;
	  strcpy(nonterminals[noofpro].exp[0],s+3);
	  nonterminals[noofpro].noofexp++;
	  i=noofpro;
	  noofpro++;
 
	}
      else
	{
	  nonterminals[i].S=s[0];  
	  strcpy(nonterminals[i].exp[nonterminals[i].noofexp++],s+3);
	}
      len=strlen(s);
      for(j=3;j<strlen(s);j++)
	{
	  if(islower(s[j])||s[j]=='*'||s[j]=='+'||
	     s[j]=='/'||s[j]=='-'||s[j]=='('||s[j]==')')
	    {
	      if(isterminal(s[j])==-1&&s[j]!='e')
		 terminals[noofter++]=s[j];
	    }
	}
    }

}

void first(int i)
{
  int k,j,l;
  int f;
  int ise,ise2;
  char *p;
  for(k=nonterminals[i].noofexp-1;k>=0;k--)
    {
      p=nonterminals[i].exp[k];
      for(j=0,ise=1;j<strlen(p)&&ise;j++)
	{
	  if(isterminal(p[j])!=-1||p[j]=='e')
	    {
	      insert(i,p[j],0);
	      ise=0;
	      break;
	    }
	  else
	    {
	      f=getpro(p[j]);
	      if(f==i) continue;
	      ise2=0;
	      for(l=0;l<nonterminals[f].fc;l++)
		{
		  if(nonterminals[f].first[l]!='e')
		    { 
		      insert(i,nonterminals[f].first[l],0);
		    }
		  else ise2=1;
		}
	      ise=ise2;
	    }	 
	  
	}
      if(ise) insert(i,'e',0);
    } 
}

void find_all_firsts()
{
  /**
   * find first(A) for all A in V 
   */

  int i;
  for(i=noofpro-1;i>=0;i--)
    {
      first(i);
    }
}




void follow(int P)
{
  int k,j,l,m,i;
  int strl;
  int f;
  char *p;
  char T;
  int ise,ise2;
  T=nonterminals[P].S;
  for(i=noofpro-1;i>=0;i--)
    {
      for(k=nonterminals[i].noofexp-1;k>=0;k--)
	{
	  p=nonterminals[i].exp[k];
	  strl=strlen(p);
	  for(j=0;j<strlen(p);j++)
	    {
	      if(p[j]==T)
		{
		  ise=1;
		  for(m=j+1;m<strl&&ise;m++)
		    {
		      if(isterminal(p[m])!=-1)
			{
			  insert(P,p[m],1);
			  ise=0;
			  break;
			}
		      else
			{
			  f=getpro(p[m]);
			  if(f==P) continue;
			  ise2=0;
			  for(l=0;l<nonterminals[f].fc;l++)
			    {
			      if(nonterminals[f].first[l]!='e')
				{ 
				  insert(P,nonterminals[f].first[l],1);
				}
			      else ise2=1;
			    }
			  ise=ise2;
			}
		    }
		  if(ise)
		    {
		      if(i==P) continue;
		      for(l=0;l<nonterminals[i].folc;l++)
			{
			  insert(P,nonterminals[i].follow[l],1);
			}
		    }
		}//if(p[j]==..
	    }//for(j=0...
	}//for(k=no..
    }// for(i=noof...
}

int insert(int P,char c,int type)
{
  int i;
  if(type==0)
    {
       for(i=0;i<nonterminals[P].fc;i++)
	 {
	   if(nonterminals[P].first[i]==c)
	     return 0;
	 }
       nonterminals[P].first[(nonterminals[P].fc)++]=c;
       return 1;
    }
  else if(type==1)
    {
      for(i=0;i<nonterminals[P].folc;i++)
	 {
	   if(nonterminals[P].follow[i]==c)
	     return 0;
	 }
       nonterminals[P].follow[(nonterminals[P].folc)++]=c;
       return 1;
    }
}



void find_all_follows()
{
  /**
   * find follow(A) for all A in V
   */
  int i;
  insert(0,'$',1);
  for(i=0;i<noofpro;i++)
    //  for(i=noofpro-1;i>=0;i--)
    {
      follow(i);
    }
}


void print_first()
{
  int i,j;
  printf("\n");
  for(i=0;i<noofpro;i++)
    {
      printf("First(%c) ==>  ",nonterminals[i].S);
      for(j=0;j<nonterminals[i].fc;j++)
	printf("%c ",nonterminals[i].first[j]);
      printf("\n");
    }
  for(i=0;i<noofter;i++)
    {
      printf("First(%c) ==>  ",terminals[i]);
      printf("%c ",terminals[i]);
      printf("\n");
    }
}
void print_follow()
{
  int i,j;
  printf("\n");
  for(i=0;i<noofpro;i++)
    {
      printf("follow(%c) ==>  ",nonterminals[i].S);
      for(j=0;j<nonterminals[i].folc;j++)
	printf("%c ",nonterminals[i].follow[j]);
      printf("\n");
    }
}



/**

OUTPUT:
-------


s0901@hp-5:~/s6$ gcc first_follow.c 

INPUT FILE:
-----------

s0901@hp-5:~/s6$ cat fin 
E->TG;
G->+TG;
G->e;
T->FH;
H->*FH;
H->e;
F->(E);
F->i;

s0901@hp-5:~/s6$ ./a.out fin

First(E) ==>  i ( 
First(G) ==>  e + 
First(T) ==>  i ( 
First(H) ==>  e * 
First(F) ==>  i ( 
First(+) ==>  + 
First(*) ==>  * 
First(() ==>  ( 
First()) ==>  ) 
First(i) ==>  i 

follow(E) ==>  $ ) 
follow(G) ==>  $ ) 
follow(T) ==>  + $ ) 
follow(H) ==>  + $ ) 
follow(F) ==>  * + $ ) 
s0901@hp-5:~/s6$ 
s0901@hp-5:~/s6$ 
s0901@hp-5:~/s6$ exit

Process shell finished



 */
