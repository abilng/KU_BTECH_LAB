#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//#define get(c)  ( c=fgetc(in),if(c==EOF){ eof=1; return t;})

FILE *in,*out;
short int eof;
typedef struct token_struct
{
char token[20];
char lexeme[20];
}token;

char keywords[][20]={"auto","break","case","char","const","continue","default"
		     ,"do","double","else","enum","extern","float","for",
		     "goto","if","int","long","register","return","short",
		     "signed","sizeof","static","struct","switch","typedef",
		     "union","unsigned","void","volatile","while"};

int noofkeywords=32;
int iskeyword(char s[]);
token gettoken();
int open_file(char *filename);
void tokenize();


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
  tokenize();
  fclose(out);
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
  strcpy(outfile,"tok_");
  strcat(outfile,filename);
  out=fopen(outfile,"w");
  if(out==NULL)
    {
      fclose(in);
      printf("ERROR!:Can't Create output file:%s\n",outfile);
      return 1;
    }
 return 0;
}

void tokenize()
{
  token t;
  eof=0;
  for(;;)
    {
      t=gettoken();
      if(eof) return;
      else
	{
	  fprintf(out,"%s   ->    %s\n",t.lexeme,t.token);
	}
    }
}

int iskeyword(char s[])
{
  int i;
  for(i=0;i<noofkeywords;i++)
    {
      if(strcmp(keywords[i],s)==0) return 1;
    }
  return 0;
}

token gettoken()
{
  const char end='\0';
  char c;
  token t;
  int state=0;
  int start=0;
  int i=0;
  t.lexeme[i]=end;
  while(1)
    {
      switch(state)
	{
	case 0:                 //start state
	  c=fgetc(in);
	  if(c==EOF){ eof=1; return t;}
	  else if(c==' '||c=='\n'||c=='\t') state=0;
	  else if(isalpha(c)){ t.lexeme[i++]=c;	 state=1; }
	  else { state=fail(start); start=state; ungetc(c,in);}
	  break;
	case 1:                  //read each char to for a token
	  c=fgetc(in);
	  if(c==EOF){ eof=1; return t;}
	  else if(isalnum(c)){t.lexeme[i++]=c; state=1;}
	  else { state=2; ungetc(c,in);}
	  break;
	case 2: //end of token
	  t.lexeme[i]=end;	    
	  if(iskeyword(t.lexeme)) strcpy(t.token,"KEYWORD");
	  else strcpy(t.token,"ID");
	  return t;
	  break;
	case 3:// START READING NUMBERS
	  c=getc(in);
	  if(c==EOF){eof=1; return t;}
	  if(c==' '||c=='\t'||c=='\n')state=3;
	  if(isdigit(c)){ t.lexeme[i++]=c; state=4;}
	  else { state=fail(start); start=state; ungetc(c,in); }
	  break;	

	case 4://READING NUMBERS
	  c=getc(in);
	  if(c==EOF){eof=1; return t;}
	  if(isdigit(c)){ t.lexeme[i++]=c; state=4;}
	  else if(c=='.'){ t.lexeme[i++]=c; state=5;}
	  else if(c=='E'||c=='e'){ t.lexeme[i++]=c;state=7;}
	  else { state=12; ungetc(c,in); }
	  break;

	case 5://reading decimal part
	  c=getc(in);
	  if(c==EOF){eof=1; return t;}
	  if(isdigit(c)){ t.lexeme[i++]=c; state=6;}
	  else { state=11; ungetc(c,in); }
	  break;	
	case 6://reading 
	  c=getc(in);
	  if(c==EOF){eof=1; return t;}
	  if(isdigit(c)){ t.lexeme[i++]=c; state=6;}
	  else if(c=='E'||c=='e'){ t.lexeme[i++]=c; state=7;}
	  else { state=11; ungetc(c,in); }
	  break;	
	case 7://reading exponent part
	  c=getc(in);
	  if(c==EOF){eof=1; return t;}
	  if(isdigit(c)){ t.lexeme[i++]=c; state=9;}
	  else if(c=='+'||c=='-'){ t.lexeme[i++]=c; state=8;}
	  else 
	    {
	      ungetc(c,in); 
	      t.lexeme[i]=end;
	      fseek(in,-strlen(t.lexeme),1); 
	      state=fail(start);
	      start=state;
	      i=0;
	    }  
	  break;	
	case 8://reading 1-st digit  after "e+/-" 
	  c=getc(in);
	  if(c==EOF){eof=1; return t;}
	  if(isdigit(c)){ t.lexeme[i++]=c; state=9;}
	  else {
	      ungetc(c,in); 
	      t.lexeme[i]=end;
	      fseek(in,-strlen(t.lexeme),1); 
	      state=fail(start);
	      start=state;
	      i=0;
	      }
	  break;	
	case 9://reading pure int after "._" 0r ".+/-_" 
	  c=getc(in);
	  if(c==EOF){eof=1; return t;}
	  if(isdigit(c)){ t.lexeme[i++]=c; state=9;}
	  else { state=10; ungetc(c,in); }
	  break;	
	case 10://end of const
	  t.lexeme[i]=end;
	  strcpy(t.token,"REAL_CONST(EXP)");
	  return t; 
	case 11:
	  t.lexeme[i]=end;
	  strcpy(t.token,"REAL_CONST");
	  return t; 
	case 12:
	  t.lexeme[i]=end;
	  strcpy(t.token,"INT_CONST");
	  return t; 
	  
	case 13:
	  c=getc(in);
	  if(c==EOF){eof=1; return t;}
	  if(c==' '||c=='\t'||c=='\n')state=13; 
	  else if(c=='<'){ t.lexeme[i++]=c; state=14;}
	  else if(c=='='){ t.lexeme[i++]=c; state=15;}
	  else if(c=='!'){ t.lexeme[i++]=c; state=16;}
	  else if(c=='>'){ t.lexeme[i++]=c; state=17;}
	  else { state=fail(start); start=state; ungetc(c,in);}
	  break;
	case 14:
	  c=getc(in);
	  if(c==EOF){eof=1; return t;}
	  if(c=='='){ t.lexeme[i++]=c; state=18;}
	  if(c=='>'){ t.lexeme[i++]=c; state=18;}
	  else if(c=='<') state=33; // <<
	  else { state=18; ungetc(c,in); }
	  break;	
	case 15: //=
	  c=getc(in);
	  if(c==EOF){eof=1; return t;}
	  if(c=='='){ t.lexeme[i++]=c; state=18;}
	  else state=27;   
	  break;	
	case 16:
	  c=getc(in);
	  if(c==EOF){eof=1; return t;}
	  if(c=='='){ t.lexeme[i++]=c; state=18;}
	  else state=32; 
	  break;	 
	case 17:
	  c=getc(in);
	  if(c==EOF){eof=1; return t;}
	  if(c=='='){ t.lexeme[i++]=c; state=18;}
	  else if(c=='>') state=34;   //>>  
	  else { state=18; ungetc(c,in); }
	  break;	
	case 18:
	  t.lexeme[i]=end;
	  strcpy(t.token,"RELOP");
	  eof=0;
	  return t; 

	case 19:
	  c=getc(in);
	  if(c==EOF){eof=1; return t;}
	  if(c==' '||c=='\t'||c=='\n')state=19; 
	  else if(c=='+'){ t.lexeme[i++]=c; state=20;}
	  else if(c=='-'){ t.lexeme[i++]=c; state=22;}
	  else if(c=='*'){ t.lexeme[i++]=c; state=39;}
	  else if(c=='/'){ t.lexeme[i++]=c; state=25;}
	  else if(c=='%'){ t.lexeme[i++]=c; state=26;}
	  else if(c=='='){ t.lexeme[i++]=c; state=27;}
	  else { state=fail(start); start=state; ungetc(c,in);}
	  break;
	case 20:
	  c=getc(in);
	  if(c==EOF){eof=1; return t;}
	  if(c=='+'){ t.lexeme[i++]=c; state=21;}
	  else if(c=='='){ t.lexeme[i++]=c; state=27;}
	  else { state=28; ungetc(c,in); }
	  break;	
	case 21:
	  t.lexeme[i]=end;
	  strcpy(t.token,"INC_OP");
	  eof=0;
	  return t; 
	case 22:
	  c=getc(in);
	  if(c==EOF){eof=1; return t;}
	  if(c=='-'){ t.lexeme[i++]=c; state=23;}
	  else if(c=='='){ t.lexeme[i++]=c; state=27;}
	  else { state=27; ungetc(c,in); }
	  break;	
	case 23:
	  t.lexeme[i]=end;
	  strcpy(t.token,"DEC_OP");
	  eof=0;
	  return t; 
	case 24:
	  c=getc(in);
	  if(c==EOF){eof=1; return t;}
	  if(c=='='){ t.lexeme[i++]=c; state=27;}
	  else { state=27; ungetc(c,in); }
	  break;	
	case 25:
	  c=getc(in);
	  if(c==EOF){eof=1; return t;}
	  if(c=='='){ t.lexeme[i++]=c; state=27;}
	  else { state=27; ungetc(c,in); }
	  break;	
	case 26:
	  c=getc(in);
	  if(c==EOF){eof=1; return t;}
	  if(c=='='){ t.lexeme[i++]=c; state=27;}
	  else { state=28; ungetc(c,in); }
	  break;	
	case 27:
	  t.lexeme[i]=end;
	  strcpy(t.token,"ASGMNT_OP");
	  eof=0;
	  return t; 
	case 28:
	  t.lexeme[i]=end;
	  strcpy(t.token,"ARITH_OP");
	  eof=0;
	  return t;  



	case 29:
	  c=getc(in);
	  if(c==EOF){eof=1; return t;}
	  if(c==' '||c=='\t'||c=='\n')state=29; 
	  else if(c=='&'){ t.lexeme[i++]=c; state=30;}
	  else if(c=='|'){ t.lexeme[i++]=c; state=31;}
	  else if(c=='!'){ t.lexeme[i++]=c; state=32;}
	  else { state=fail(start); start=state; ungetc(c,in);}
	  break;
	case 30:
	  c=getc(in);
	  if(c==EOF){eof=1; return t;}
	  if(c=='&'){ t.lexeme[i++]=c; state=32;}
	  else state=34; 
	  break;	
	case 31:
	  c=getc(in);
	  if(c==EOF){eof=1; return t;}
	  if(c=='|'){ t.lexeme[i++]=c; state=32;}
	  else state=34; 
	  break;	
	case 32:
	  t.lexeme[i]=end;
	  strcpy(t.token,"LOG_OP");
	  eof=0;
	  return t; //TODO replace
	case 33:
	  c=getc(in);
	  if(c==EOF){eof=1; return t;}
	  if(c==' '||c=='\t'||c=='\n')state=33; 
	  else if(c=='&'){ t.lexeme[i++]=c; state=34;}
	  else if(c=='|'){ t.lexeme[i++]=c; state=34;}
	  else if(c=='^'){ t.lexeme[i++]=c; state=34;}
	  else if(c=='<'){ t.lexeme[i++]=c; state=35;}
	  else if(c=='>'){ t.lexeme[i++]=c; state=36;}
	  else { state=fail(start); start=state; ungetc(c,in);}
	break;
	case 34:
	  t.lexeme[i]=end;
	  strcpy(t.token,"BIT_OP");
	  eof=0;
	  return t; 
	case 35:
	  c=getc(in);
	  if(c==EOF){eof=1; return t;}
	  if(c=='<'){ t.lexeme[i++]=c; state=34;}
	  break;

	case 36:
	  c=getc(in);
	  if(c==EOF){eof=1; return t;}
	  if(c=='>'){ t.lexeme[i++]=c; state=34;}
	  break;
	case 37:
	  c=getc(in);
	  if(c==EOF){eof=1; return t;}
	  if(c==' '||c=='\t'||c=='\n')state=37; 
	  else if(c=='{'||c=='}'||c=='('||c==')'
		  ||c=='['||c==']'||c=='#'||c==','
		  ||c=='.'||c==':'||c=='\\')
	    { t.lexeme[i++]=c; state=38;}
	  else { state=fail(start); start=state; ungetc(c,in);}
	  break;
	case 38:
	  t.lexeme[i]=end;
	  strcpy(t.token,"SPCL_CHAR");
	  eof=0;
	  return t; 
	case 39:
	  c=getc(in);
	  if(c==EOF){eof=1; return t;}
	  if(c==' '||c=='\t'||c=='\n')state=39; 
	  else if(c=='\"'){ t.lexeme[i++]=c; state=40;}
	  else if(c=='\''){ t.lexeme[i++]=c; state=42;}
	  else { state=fail(start); start=state; ungetc(c,in);}
	  break;
	case 40:
	  c=getc(in);
	  if(c==EOF){eof=1; return t;}
	  if(c=='\"'){ t.lexeme[i++]=c; state=41;}
	  else { t.lexeme[i++]=c; state=40; }
	  break;
	case 41:
	  t.lexeme[i]=end;
	  strcpy(t.token,"STR_CONST");
	  eof=0;
	  return t; 
	case 42:
	  c=getc(in);
	  if(c==EOF){eof=1; return t;}
	  t.lexeme[i++]=c;
	  state=43; 
	  break;
	case 43:
	  c=getc(in);
	  if(c==EOF){eof=1; return t;}
	  if(c=='\''){ t.lexeme[i++]=c; state=44;}
	  else 
	    {
	      ungetc(c,in); 
	      t.lexeme[i]=end;
	      fseek(in,-strlen(t.lexeme),1); 
	      state=fail(start);
	      start=state;
	      i=0;
	    }  
	  break;
	case 44:
	  t.lexeme[i]=end;
	  strcpy(t.token,"CHARACTER CONST");
	  eof=0;
	  return t; 
	default:
	  c=getc(in);
	  if(c==';')
	    {
	      t.lexeme[i++]=c; 
	      t.lexeme[i]=end;
	      strcpy(t.token,"DELIMITER");
	      //eof=0;
	      return t;
	    }
	  t.lexeme[i++]=c; 
	  t.lexeme[i]=end;
	  strcpy(t.token,"Unknown_token");
	  //eof=0;
	  return t;
	

	}
    }
}


int fail(int start)
{

switch(start)
{
 case 0:
   start=3;
   break;
 case 3:
   start=13;
   break;
 case 13:
   start=19;
   break;
 case 19:
   start=29;
   break;
 case 29:
   start=33;
   break;
 case 33:
   start=37;
   break;
 case 37:
   start=39;
   break;
 case 39:
   start=45;
   break;
 case 45:
   start=0;
   break;
   
 }
 return start;
}

/**
OUTPUT::
--------

s0901@T-R-SL-1-35:~/s6$ gcc lex.c
s0901@T-R-SL-1-35:~/s6$ ./a.out e

INPUT FILE:
-----------

s0901@T-R-SL-1-35:~/s6$ cat e
int a;
int main()
{
printf("error")
return 0;
}

OUTPUT FILE
-----------

s0901@T-R-SL-1-35:~/s6$ cat tok_e
int   ->    KEYWORD
a   ->    ID
;   ->    DELIMITER
int   ->    KEYWORD
main   ->    ID
(   ->    SPCL_CHAR
)   ->    SPCL_CHAR
{   ->    SPCL_CHAR
printf   ->    ID
(   ->    SPCL_CHAR
"error"   ->    STR_CONST
)   ->    SPCL_CHAR
return   ->    KEYWORD
0   ->    INT_CONST
;   ->    DELIMITER
}   ->    SPCL_CHAR
s0901@T-R-SL-1-35:~/s6$ 


 */
