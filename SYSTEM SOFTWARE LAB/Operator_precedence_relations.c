#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct production
{
  char S; //NONTERMINAL
  char exp[10][20];//PRODUCTIONS WITH this NON TERMINAL AT LEFT
  int noofexp;//NO OF PRO of this
  int leading[20];
  int trailing[20];
  int lc;
  int tc;
}productions[20];

int noofpro=0;
char terminals[20];
int noofter=0;
FILE *in,*out;
char table[20][20];
//void copy(int a[],int b[],int al,int bl);

void print_l();
void print_t();
void op_p();
void insert(int P,char c,int type);
void find_all_leadings();
void find_all_trailings();
int isterminal(char s);
int getpro(char s);
void readpro();
void leading(int i);
void trailing(int i);
void print_table();
void create_table();

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
  op_p();
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

void op_p()
{
  int i;
  readpro();
  find_all_leadings();
  find_all_trailings();
  create_table();
  printf("Terminals::   ");
  for(i=0;i<noofter;i++) printf("%c ",terminals[i]);
  printf("\n");
  print_l();
  print_t();
  print_table();
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
    if(s==productions[i].S) return i;  
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
      if(k!=0) strcpy(k,"\0\0");    //replace ';' by '\0'
      i=getpro(s[0]);
      if(i<0)
	{
	  productions[noofpro].S=s[0];
	  productions[noofpro].tc=0;  
	  productions[noofpro].lc=0;
	  strcpy(productions[noofpro].exp[0],s+3);
	  productions[noofpro].noofexp++;
	  i=noofpro;
	  noofpro++;
 
	}
      else
	{
	  productions[i].S=s[0];  
	  strcpy(productions[i].exp[productions[i].noofexp++],s+3);
	}
      len=strlen(s);
      for(j=3;j<strlen(s);j++)
	{
	  if(islower(s[j])||s[j]=='*'||s[j]=='+'||
	     s[j]=='/'||s[j]=='-'||s[j]=='('||s[j]==')')
	    {
	      if(isterminal(s[j])==-1)
		 terminals[noofter++]=s[j];
	    }
	}
    }

}
void leading(int i)
{
  int k,j,l;
  int lead;
  char *p;
  for(k=productions[i].noofexp-1;k>=0;k--)
    {
      p=productions[i].exp[k];
      for(j=0;j<strlen(p)&&j<2;j++)
	{
	  if(isterminal(p[j])!=-1)
	    {
	      insert(i,p[j],0); //if terminal
	    }
	  else if(j==0)
	    {
	      lead=getpro(p[j]);
	      if(lead==i) continue;
	      for(l=0;l<productions[lead].lc;l++)
		{
		  insert(i,productions[lead].leading[l],0);
		}
	    }	 
	  
	}
    } 
}


void find_all_leadings()
{
  /**
   * find leading(A) for all A in V 
   */
  int i;
  
  for(i=noofpro-1;i>=0;i--)
    {
      leading(i);
    }
}




void trailing(int i)
{
  int k,j,l;
  int t,strl;
  char *p; 
  for(k=productions[i].noofexp-1;k>=0;k--)
    {
      p=productions[i].exp[k];
      strl=strlen(p);
      for(j=strlen(p)-1;(j>strl-3)&&j>=0;j--)
	{
	  if(isterminal(p[j])!=-1)
	    {
	      insert(i,p[j],1);//if teminal
	    }
	   else if(j==strlen(p)-1)
	    {
	      t=getpro(p[j]);
	      if(t==i) continue;
	      for(l=0;l<productions[t].tc;l++)
		{
		  insert(i,productions[t].trailing[l],1);
		}
	    }	 
	  
	}
    }

}
void insert(int P,char c,int type)
{
  int i;
  if(type==0)
    {
       for(i=0;i<productions[P].lc;i++)
	 {
	   if(productions[P].leading[i]==c)
	     return;
	 }
       productions[P].leading[(productions[P].lc)++]=c;
    }
  else if(type==1)
    {
      for(i=0;i<productions[P].tc;i++)
	 {
	   if(productions[P].trailing[i]==c)
	     return;
	 }
       productions[P].trailing[(productions[P].tc)++]=c;
    }
}



void find_all_trailings()
{
  /**
   * find trailing(A) for all A in V
   */
  int i;
  //  for(i=0;i<noofpro;i++)
  for(i=noofpro-1;i>=0;i--)
    {
      trailing(i);
    }
}



void create_table()
{
  /**
   * create parsing table 
   */
  int i,j,k,l;
  int index;  
  int index1;  
  char x0,x1,x2;
  int li;
  for(i=0;i<=noofter+1;i++)
    for(j=0;j<=noofter+1;j++)
      table[i][j]='#';

  table[0][0]=' ';
  for(i=1;i<=noofter;i++)table[i][0]=terminals[i-1];
  for(i=1;i<=noofter;i++)table[0][i]=terminals[i-1];

  table[noofter+1][0]='$';
  table[0][noofter+1]='$';
  for(i=0;i<productions[0].lc;i++)
    {
      index=isterminal(productions[0].leading[i]);
      if(index!=-1)
	table[noofter+1][index+1]='<';
    }
  for(i=0;i<productions[0].tc;i++)
    {
      index=isterminal(productions[0].trailing[i]);
      if(index!=-1)
	table[index+1][noofter+1]='>';
    }

  for(i=0;i<noofpro;i++)
    {
      for(j=productions[i].noofexp-1;j>=0;j--)      
	{
	  for(k=1;k<strlen(productions[i].exp[j]);k++)
	    {
	      int i0,i1,i2;
	      x0=productions[i].exp[j][k-1];
	      x1=productions[i].exp[j][k];
	      i0=isterminal(x0);
	      i1=isterminal(x1);
	      if(i0!=-1&&i1!=-1)
		{
		  table[i0+1][i1+1]='=';
		}
	
	      if(i0==-1&&i1!=-1)
		{
		  li=getpro(x0);
		  for(l=0;l<productions[li].tc;l++)
		    {
		      index1=isterminal(productions[li].trailing[l]);
		      if(index1!=-1)
			{
			  table[index1+1][i1+1]='>';
			}		   
		    }
		}
	      if(i0!=-1&&i1==-1)
		{
		  li=getpro(x1);
		  for(l=0;l<productions[li].lc;l++)
		    {
		      index1=isterminal(productions[li].leading[l]);
		      if(index1!=-1)
			{
			  table[i0+1][index1+1]='<';
			}
		    }
		}
	      if(k<strlen(productions[i].exp[j]))
		{
		  x2=productions[i].exp[j][k+1];
		  i2=isterminal(x2);
		  if(i0!=-1&&i2!=-1&&i1==-1)
		    {
		      table[i0+1][i2+1]='=';
		    }
	     
		}
	    }
	
	}
    }
}


void print_table()
{
  int i,j;
  printf("\n");
  for(i=0;i<=noofter+1;i++)
    {
      for(j=0;j<=noofter+1;j++)
	printf("%c ",table[i][j]);
      printf("\n");
    }
  printf("\n");
 
}
void print_l()
{
  int i,j;

  printf("\n");
  for(i=0;i<noofpro;i++)
    {
      printf("leading(%c) ==>  ",productions[i].S);
      for(j=0;j<productions[i].lc;j++)
	printf("%c ",productions[i].leading[j]);
      printf("\n");
    }

}
void print_t()
{
  int i,j;
  printf("\n");
  for(i=0;i<noofpro;i++)
    {
      printf("trailing(%c) ==>  ",productions[i].S);
      for(j=0;j<productions[i].tc;j++)
	printf("%c ",productions[i].trailing[j]);
      printf("\n");
    }

}







/**
OUTPUT::
--------

s0901@T-R-SL-1-35:~/s6$ gcc op_p.c

INPUT FILE:
-----------
s0901@T-R-SL-1-35:~/s6$ cat opin 
E->E+T;
E->T;
T->T*F;
T->F;
F->(E);
F->i;


s0901@T-R-SL-1-35:~/s6$ ./a.out opin 

Terminals::   + * ( ) i 

leading(E) ==>  i ( * + 
leading(T) ==>  i ( * 
leading(F) ==>  i ( 

trailing(E) ==>  i ) * + 
trailing(T) ==>  i ) * 
trailing(F) ==>  i ) 

  + * ( ) i $ 
+ > < < > < > 
* > > < > < > 
( < < < = < # 
) > > # > # > 
i > > # > # > 
$ < < < # < # 


s0901@T-R-SL-1-35:~/s6$  

 */
