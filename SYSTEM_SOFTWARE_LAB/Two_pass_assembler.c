#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define max 100
#define intrlen 3
#define wordlen 3

//enum error(noerror,
struct sym
{
  char l[6];
  unsigned int v;
}symtab[max];


struct opcode      //opcode object
{
  char code[6];
  char ml_eq[3];       //machine language equvivalent
};

struct opcode optab[] = {{"JSUB","48"},{"LDA","00"},{"STA","0C"},
			 {"STX","10"},{"STL","14"},{"COMP","28"},
			 {"J","30"},{"LDL","08"},{"RSUB","4C"},
			 {"LDX","04"},{"TD","E0"},{"RD","D8"},
			 {"STCH","54"},{"TIX","2C"},{"LDCH","50"},
			 {"WD","DC"},{"END","--"},{"J","3C"},
			 {"JGT","34"},{"JLT","38"},{"JEQ","30"}};
const int optablimit = 21;


struct token
{
  char label[6];
  char opcode[6];
  char operand[20];
};


int symtablimit;
unsigned int locctr;
unsigned int STARTADDR;
unsigned int textstart;
int errorflg=0;
int textlen;
char text[61];
FILE *out,*list;
char listfile[10];
char outfile[10];



/* search the optab for the given opcode 
   returns the hex of the opcode if found
   returns -1 if not found  */

int op_search(char op[6])
{
  int i = 0;
  int ret = -1;
  // printf("%s\n",op);
  for(i=0;i<optablimit;i++)
    {
     
      if(strcmp(optab[i].code,op)==0)
	ret = i;
      //      printf("%s%sp%d\n",optab[i].code,op,ret);
    }
  return ret;
}


/*write header record*/

void write_head(FILE * out,char s[6],int len)
{
  fseek(out,0,0);
  //printf("%x\n",len);
  fprintf(out,"H%-6s%06x%06x \n",s,STARTADDR,len);
}

/*close current text rec*/

void close_text(FILE *out)
{
  int len;
  if(textlen==-1) return;
  len=(strlen(text)/2);
  fprintf(out,"T%06x%02x%s\n",textstart,len,text);
  textlen=-1;
  strcpy(text,"");
}

/*Intilize new text rec
and close cuurent one(if any)*/
void init_text(FILE * out,unsigned int x)
{
  if(textlen!=-1) close_text(out);
  textstart=x;
  textlen=0;
  strcpy(text,"");
}


/* add a hex-machine-lang-code
to current text rec if it has space
to include else init a new add to it
*/
void text_add(FILE *out,char * s)
{
  if(textlen==-1||textlen==59)
    {
    init_text(out,locctr);
    }
  if(textlen+strlen(s)>=59)
    {
      init_text(out,locctr);
    }
  strcat(text,s);
  textlen=textlen+strlen(s);
}

int insert(char * s,unsigned int val)
{
  if(search(s)==-1)
    {
      strcpy(symtab[symtablimit].l,s);
      symtab[symtablimit].v=val;
      symtablimit++;
      return 0;
    }
  else return -1;
    
}

int search(char *s)
{
  int i;
  for(i=0;i<symtablimit;i++)
    {
      if(strcmp(symtab[i].l,s)==0)
	return symtab[i].v;
    }
  return -1;
}


/* read one line of input from the source file 
   returns 1 if a line is read
   returns 0 if empty line */
int readline(FILE *file,char *line)
{
  int ret = 1;
  int cnt = 0;
  char p;
  while((p = fgetc(file))!=EOF && p != '\n')
    {
      line[cnt++]=p;
    }
  line[cnt]='\0';
  if(line[0]=='\0')
    ret = 0;
  return ret;
}

void tokenize(char *line,struct token *t)
{
  char *l;
  char *tok;
  int i=0;
  int flag1=0;
  strcpy(t->label,"\0");
  strcpy(t->opcode,"\0");
  strcpy(t->operand,"\0");

  for(i=0,l=line;;l=NULL,i++)
    {
      tok = strtok(l," \t");
      if(tok == NULL)
	break;
      // printf("%s\n",tok);
      if(i==0)
	{
	  if(op_search(tok)!=-1||!strcmp(tok,"END")||!strcmp(tok,"START"))
	    {
	      // printf("\t%s\n",tok);
	      strcpy(t->opcode,tok);
	      flag1=1;
	    }
	  else
	    {
	      strcpy(t->label,tok);
	    }
	}
      if(i==1)
	{
	  if(flag1==1)
	    {
	      strcpy(t->operand,tok);
	    }
	  else
	    {
	      strcpy(t->opcode,tok);
	    }
	}
      if(i==2)
	{
	  strcpy(t->operand,tok);
	}
    }
  if(flag1==0 && i<2)
    {
      int errorflg=-1;
      //printf("\nUnknown Opcode\n");
    }
}
char* getHexOperand(char *strop,char *  hexop)
{
  int i;
  char *cptr;
  char str[80];
  strcpy(str,strop);
  if(str[0]=='X')
    {
      cptr == strtok(str+1," '");
      if(cptr != NULL)
	{
	  sprintf(hexop,"%04X",(unsigned int)strtoul(cptr,0,16));
	}
      else
	return NULL;
    }
  else if(str[0] == 'C')
    {
      cptr = strtok(str+1," '");
      if(cptr!=NULL)
	{
	  for(i=0;cptr[i]!='\0';i++)
	    {
	      sprintf(hexop+(2*i),"%02X",cptr[i]);
	    }
	  hexop[2*i]='\0';
	}
      else 
	return NULL;
    }
  else
    {
      sprintf(hexop,"%06X",(unsigned int)strtoul(str,0,16));
    }
  return hexop;
}

int operandlen(char *str)
{
  char *cptr;
  if(str[0] == 'X'||str[0] == 'C')
    {
      cptr = strtok(str+1," '");
      if(cptr != NULL)
	{
	  return strlen(cptr);
	}
      else 
	return 0;
    }
  return 0;
}


openopfile(char prgname[])
{
  strcpy(listfile,prgname);
  strcpy(outfile,prgname);
  strcat(listfile,".list");
  strcat(outfile,".obj");
  list=fopen(listfile,"w"); 
  out=fopen(outfile,"w");
}
/*

*/
main(int argc,char * argv[])
{

  FILE *in;
  struct token tok;
  char * filename;
  char str[100];
  char * str1;
  char str2[10];
  char pgmname[7];
  char line[100];
  char line_buffer[100];
  int  proceed =0;
  int lineno=0;
  char opcodehex[2];
  int operandhex;
  int end=0;
  int prglen;
  int i;

  textlen=-1;
  symtablimit=0;
  locctr=0x0;
  if(argc != 2) 
    {
      printf("ERROR!:No input file\n");
      exit(0);
    }
  filename=argv[1];
  in=fopen(filename,"r");
  // list=fopen("a2.list","w");
  if(in==NULL)
    {
      printf("ERROR!:No input file\n");
      exit(0);
    }


  //pass1 start here

   while(readline(in,line))
    {
      lineno++;
      if(line[0]==';') continue;
      strcpy(line_buffer,line);
      tokenize(line_buffer,&tok);
      if(errorflg == -1)
	{
	  printf("\nError!:Invalid opcode [line %d]\n\n",lineno);
	  exit(0);
	}

      if(!strcmp(tok.opcode,"START"))
	{
	  if(strlen(tok.operand)!=0)
	    { 
	      STARTADDR = atoi(tok.operand);
	      strcpy(pgmname,tok.label);
	    }
	  else
	    { 
	      STARTADDR = 0;
	      strcpy(pgmname,"PGMNAM");
	    }
	  locctr=STARTADDR;	 
	  insert(tok.label,STARTADDR);
	  openopfile(pgmname);
	  proceed = 1;
	  //	  write_head(out,pgmname,0x0);
	  fprintf(list,"%06x %s\n",locctr,line); 
	  continue;
	}  // end of if(!strcmp(opc,"START"))..


      if(proceed)
	{
	  if(strlen(tok.label)!=0)
	    {
	      if(insert(tok.label,locctr)!=0)
		{
		  printf("Warning:(Line:%d)Duplicate Symbol",lineno);
		}
	    }
	  //write inter..... file
	  fprintf(list,"%06x %s\n",locctr,line); 
	  if(!strcmp(tok.opcode,"WORD"))
	    {
	      locctr = locctr + 3;
	    }
	  else if(!strcmp(tok.opcode,"BYTE"))
	    {
	      locctr = locctr + operandlen(tok.operand);
	    }
	  else if(!strcmp(tok.opcode,"RESB"))
	    {
	      locctr+=(atoi(tok.operand));
	    }
      	  else if(!strcmp(tok.opcode,"RESW"))
	    {
	      locctr+=(atoi(tok.operand)*wordlen);
	    }
	  else if(!strcmp(tok.opcode,"END"))
	    {
	      prglen=(locctr-STARTADDR);
	      break;   
	    }
	  else
	    {
	      locctr+=(intrlen);
	    }
  
  
	}   // end of if(proceed)..

    }  //end of while(!feof(fin))..
   fclose(in);
   fclose(list);
   // out=fopen("a2.obj","w");
   in=fopen(filename,"r");


 //pass2 start here

   while(readline(in,line))
    {
      lineno++;
      if(line[0]==';') continue;
      strcpy(line_buffer,line);
      tokenize(line_buffer,&tok);
      
      if(!strcmp(tok.opcode,"START"))
	{
	  if(strlen(tok.operand)!=0)
	    { 
	      STARTADDR = atoi(tok.operand);
	      strcpy(pgmname,tok.label);
	    }
	  else
	    { 
	      STARTADDR = 0;
	      strcpy(pgmname,"PGMNAM");
	    }
	  locctr=STARTADDR;	 
	  insert(tok.label,STARTADDR);	 
	  proceed = 1;
	  write_head(out,pgmname,prglen);
	  continue;
	}  // end of if(!strcmp(opc,"START"))..


      if(proceed)
	{
	  
	  if(!strcmp(tok.opcode,"WORD"))
	    {
	      strcpy(str,"");
	      getHexOperand(tok.operand,str);
	      text_add(out,str);
	      locctr = locctr + 3;

	    }
	  else if(!strcmp(tok.opcode,"BYTE"))
	    {
	      strcpy(str,"");
	      getHexOperand(tok.operand,str);
	      text_add(out,str);
	      locctr = locctr + operandlen(tok.operand);
	    }
	  else if(!strcmp(tok.opcode,"RESB"))
	    {
	      if(textlen!=-1) close_text(out);
	      locctr+=(atoi(tok.operand));
	    }
      	  else if(!strcmp(tok.opcode,"RESW"))
	    {

	      if(textlen!=-1) close_text(out);
	      locctr+=(atoi(tok.operand)*wordlen);
	    }
	  else if(!strcmp(tok.opcode,"END"))
	    {
	      close_text(out);
	      fprintf(out,"E%06x\n",STARTADDR);
	      break;   
	    }
	  else
	    {
	      i=op_search(tok.opcode);
	      if(i==-1)
		{
		  printf("ERROR!:Unknown opcode[line %d]\n",lineno);
		  errorflg=-1;
		  strcpy(opcodehex,"00");
		}
	      else
		{
		  strcpy(opcodehex,optab[i].ml_eq);
		  //		  printf("%d %s\n",i,optab[i].ml_eq);
		}
	      operandhex=search(tok.operand);
	      if(operandhex==-1)
		{
		  printf("ERROR!:Unknown opcode[line %d]\n",lineno);
		  operandhex=0x00;
		}
	      sprintf(str,"%2s%04x\0",opcodehex,operandhex);
	      text_add(out,str);
	      locctr+=(intrlen);
	    }//end of elseif lader
	
	  
	}   // end of if(proceed)..

    }  //end of while(!feof(fin))..
   fclose(in);
   fclose(out);
   if(errorflg==0)
     {
       printf("OBJECT FILE \t:%s\nLISTING FILE\t:%s\n",outfile,listfile);
     }
 
}




/*

OUTPUT:

	s0901@T-R-SL-1-32:~/s6$ gcc pass2.c 
	s0901@T-R-SL-1-32:~/s6$ ./a.out ip_op/test 
	OBJECT FILE 	:PGMNAM.obj
	LISTING FILE	:PGMNAM.list
	s0901@T-R-SL-1-32:~/s6$ 


INPUT FILE::::TEST

	;coment
	name START
	label LDA t1
	LDA t2
	t1 RESW 1
	t2 WORD 3
	t3 BYTE C'r'
	END

OBJECT FILE 	:PGMNAM.obj

	HPGMNAM00000000000d 
	T00000006000006000009
	T0000090400000372
	E000000

LISTING FILE	:PGMNAM.list

	000000 name START
	000000 label LDA t1
	000003 LDA t2
	000006 t1 RESW 1
	000009 t2 WORD 3	
	00000c t3 BYTE C'r'
	00000d END

*/
