#include<stdio.h>
#include<stdlib.h>
#include<string.h>

short int expanding;
short int level=0;
short int def_index=0;
short int name_index=0;
short int name_max=0;
int line_no=0;
FILE *in,*out;
struct token
{
  char label[6];
  char opcode[6];
  char operand[20];
};

struct line{
  char l[100];
  struct token t;
}cur_line;

struct nametab
{
  char name[6];
  unsigned int start;
  unsigned int end;
}namtab[20];
struct deftab{
  char tab[100][100];
  int max;
}deftab;


struct argtab{
  char tab[6][10];
  int max;
}argtab;


struct parmtab{
  char tab[6][10];
  int max;
}parmtab;


void processline();
void tokenize(char *str,struct token *t);
void expand();
void define();
int search(char *str);
int insert(char *str);
void getline();
void macro();
int open_file(char *filename);

//main()
//{
//}
main(int argc,char * argv[])
{
  char * filename;
  char str[100];
  int  proceed =0;
  if(argc != 2) 
    {
      printf("ERROR!:No input file\n");
      exit(0);
    }
  filename=argv[1];
  if(open_file(filename)!=0)
    {
      exit(0);
    }

  deftab.max=0;
  argtab.max=0;
  parmtab.max=0;
  expanding=0;
  macro();

  fclose(out);
  fclose(in);
}//*/
int open_file(char *filename)
{
  char outfile[20];
  in=fopen(filename,"r");
  if(in==NULL)
    {
      printf("ERROR!:No input file:%s\n",filename );
      return 1;
    }
  strcpy(outfile,"e_");
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
void macro()
{
  expanding=0;
  do
    {
      // printf("%s||||\n",cur_line.t.opcode);
      getline();
      processline();
    } while(strcasecmp(cur_line.t.opcode,"END")!=0);                                                                   
}

void processline()
{

  if(search(cur_line.t.opcode)!=-1) expand();
  else if(strcasecmp(cur_line.t.opcode,"MACRO")==0) define();
  else
    {
      fprintf(out,"%s",cur_line.l); 
      //write into expanded file
    }
}

void getline()
{
  char line[100],line2[100];
  char str[10];
  if(expanding)
    {
      int i,k;
      char *start;
      //TODO
      //read next line from deftab
      strcpy(line,deftab.tab[def_index++]);
      for(i=0;i<argtab.max;i++)
	{
	  sprintf(str,"?%d\0\0",i);
	  start=strstr(line,str);
	  if(start!=NULL)
	    {
	      strcpy(line2,start+2);
	      strcpy(start,argtab.tab[i]);
	      strcat(line,line2);
	      //substitute arg from argtab
	    }
	}
      //modify cur_line=newline   and tokenaze it
      strcpy(cur_line.l,line);
      tokenize(cur_line.l,&(cur_line.t));
    }
  else
    {
      //TODO
      //if next line is not comment(if comment add to o/p file)
      //read next line to cur_line,tokenize
      while(fgets(cur_line.l,100,in))
	{
	  line_no++;
	  if(cur_line.l[0]==';')
	    {
	      fprintf(out,"%s",cur_line.l); 
	      continue;
	    }
	  tokenize(cur_line.l,&(cur_line.t));
	  break;
	}
    }
}
void define()
{
  level=1;
  char parm[60];
  char *l;
  char *tok;
  //insert(macroname)
  strcpy(namtab[name_max].name,cur_line.t.label);
  //insert_deftab(macro-protype)
  namtab[name_max].start=deftab.max;
  strcpy(deftab.tab[deftab.max++],cur_line.l);  
  strcpy(parm,cur_line.t.operand);
  //seting parmtab
  parmtab.max=0;
  for(l=parm;;l=NULL)
    {
      tok = strtok(l,",");
      if(tok == NULL) break;
      strcpy(parmtab.tab[parmtab.max++],tok);
    }

  while(level>0)
    {
      char line[100],line2[100];
      char str[10];
      int i;
      char *start;
      getline();
      
      //subtitute postional arg for parameter
      
      strcpy(line,cur_line.l);
      for(i=0;i<parmtab.max;i++)
	{
	  sprintf(str,"?%d\0\0",i);
	  start=strstr(line,parmtab.tab[i]);
	  if(start!=NULL)
	    {
	      strcpy(line2,start+2);
	      strcpy(start,str);
	      strcat(line,line2);
	    }
	}
      if(strcasecmp(cur_line.t.opcode,"MACRO")==0) 
	{
	  level++;
	  continue;
	}
      else if(strcasecmp(cur_line.t.opcode,"MEND")==0) 
	{
	  level--;
	  continue;
	}
      //enter line to deftab
      //      printf("%d\n",deftab.max);
      strcpy(deftab.tab[deftab.max++],line);
    }
  //store NAMTAB ptr to start and end of def
  namtab[name_max++].end=deftab.max;
}
void expand()
{
  int i;
  int noofparm=0;
  int noofarg=0;
  char line[100];
  char *l,*tok;
  expanding=1;

  i= search(cur_line.t.opcode);
  //get 1-st line from deftab
  def_index=namtab[i].start;
  strcpy(line,deftab.tab[def_index++]);
  for(l=line;;l=NULL)
    {
      tok = strtok(l,",");
      if(tok == NULL) break;
      noofparm++;
    }
  //set up argtab
  argtab.max=0;
  strcpy(line,cur_line.t.operand);
  for(l=line;;l=NULL)
    {
      tok = strtok(l,",");
      if(tok == NULL) break;
      strcpy(argtab.tab[argtab.max++],tok);
      noofarg++;
    }
  if(noofarg!=noofparm)
    {
      printf("a=%d p=%d\n",noofarg,noofparm);
      printf("Error:%d:No of arg does not match\n",line_no);
    }
  //write macro invocation as comment in outfile
  fprintf(out,";%s",cur_line.l); 
  //   while(not end of macrodef)
  // printf("%d");
   while(def_index<namtab[i].end) 
   {
     // printf("test\n");
     getline();
     processline();
   }
  expanding=0;
}

int search(char *str)
{
  int i;
  for(i=0;i<name_max;i++)
    {
      if(strcasecmp(str,namtab[i].name)==0)
	{
	  return i;
	} 
    }
  return -1;
}
void tokenize(char *str,struct token *t)
{
  char *l;
  char str1[100];
  char *tok;
  int i=0;
  int flag1=0;
  char fld1[6],fld2[60],fld3[60];
  strcpy(str1,str);
  strcpy(t->label,"\0");
  strcpy(t->opcode,"\0");
  strcpy(t->operand,"\0");

  for(i=0,l=str1;;l=NULL,i++)
    {
      tok = strtok(l," \t\n");
      if(tok == NULL) break;
      if(i==0) strcpy(fld1,tok);
      else if(i==1) strcpy(fld2,tok);
      else if(i==2) strcpy(fld3,tok);
    }
  if(i>2)
    {
      strcpy(t->label,fld1);
      strcpy(t->opcode,fld2);
      strcpy(t->operand,fld3);
    }
  else if(i==2)
    {
      if(strcasecmp(fld2,"START")==0||strcasecmp(fld2,"RSUB")==0)
	{
	  strcpy(t->label,fld1);
	  strcpy(t->opcode,fld2);
	}
      else
	{
	  strcpy(t->opcode,fld1);
	  strcpy(t->operand,fld2);
	}
    }
  else
    {
      strcpy(t->opcode,fld1);
    }
}




/**


OUTPUT::
--------

   s0901@T-R-SL-1-32:~/s6$ gcc macro.c
   s0901@T-R-SL-1-32:~/s6$ ./a.out test

INPUTFILE (test):
-----------------
   s0901@T-R-SL-1-32:~/s6$ cat test
   name START
   LDA t1
   LDA t2
   TESTD MACRO &D
   TEST TD &D
   JLT TEST
   MEND
   MS MACRO &E
   LDA &E
   STA T1
   MEND
   TESTD X'02'
   LDA t1
   MS T3
   t1 WORD 2
   t2 BYTE C'r'
   T3 BTYE X'0A'
   END

OUTPUTFILE(e_test):
------------------
   s0901@T-R-SL-1-32:~/s6$ cat e_test 
   name START
   LDA t1
   LDA t2
   ;TESTD X'02'
   TEST TD X'02'
   JLT TEST
   LDA t1
   ;MS T3
   LDA T3
   STA T1
   t1 WORD 2
   t2 BYTE C'r'
   T3 BTYE X'0A'
   END

   s0901@T-R-SL-1-32:~/s6$ exit
   
   Process shell finished

 */
