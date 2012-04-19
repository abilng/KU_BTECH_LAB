#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct memory
{
  unsigned int loc;
  short used;
};
struct memory * mem;
//int * mem;
int memlen=0;
int startaddr=0;
char prgname[10];
void write_file()
{
  FILE *f1;
  int i;
  char outfile[13];
  sprintf(outfile,"%s.op\0",prgname);
  f1=fopen(outfile,"w");
  for(i=0;i<memlen;i=i+4)
    {
      int j;
      fprintf(f1,"%06x\t",i+startaddr);
      for(j=i;(j<i+4)&&j<memlen;j++)
	  {
	    if(!mem[j].used)  fprintf(f1,"XX");
	    else  fprintf(f1,"%02x",mem[j].loc);
          }
      fprintf(f1,"\n");
    }
 
  fclose(f1);
}
void init_mem()
{
  int i;
  for(i=0;i<memlen;i++)
    {
      mem[i].loc=0x0;
      mem[i].used=0;
    }
}

void load_text(char textrec[])
{
  // text rec form: T^LOC^^LL--------------
  int i,j;
  unsigned int start_add;
  unsigned  int len;
  unsigned int byte;
  char part1[6],part2[3];
  char tmp[6];
  char text[70];
  strncpy(part1,textrec+1,6);
  strncpy(part2,textrec+7,2);
  strcpy(text,textrec+9);
  strcpy(tmp,"\0\0\0\0\0\0");
  sprintf(tmp,"%s\0\n",part1); sscanf(tmp,"%X",&start_add);
  strcpy(tmp,"\0\0\0\0\0\0");// strcpy(tmp,"");
  sprintf(tmp,"%s\0\n",part2); sscanf(tmp,"%X",&len);
  j=(start_add-startaddr);
  for(i=0;i<len;i++)
    {
      strcpy(tmp,"\0\0\0\0\0\0");
      strncpy(tmp,text+2*i,2);
      sscanf(tmp,"%X",&byte);
      //    printf("%02X\n",byte);
      mem[j+i].loc=mem[j+i].loc+byte;
      mem[j+i].used=1;
    }
 
  return;
}

void header(char headrec[])
{
  // HPRGNAMsrtadd^^len^
  char tmp[10];
  strncpy(prgname,headrec+1,6);
  strncpy(tmp,headrec+7,6);
  sscanf(tmp,"%X",&startaddr);
  strncpy(tmp,headrec+13,6);
  sscanf(tmp,"%X",&memlen);
  mem=(struct memory *)malloc((memlen)*(sizeof(struct memory)));
  init_mem();
}
void end()
{
  write_file();
  free(mem);
  printf("created o/p file:%s.op \n",prgname);
}



main(int argc,char * argv[])
{

  FILE *in;
  char * filename;
  char str[100];
  int  proceed =0;
  if(argc != 2) 
    {
      printf("ERROR!:No input file\n");
      exit(0);
    }
  filename=argv[1];
  in=fopen(filename,"r");
  if(in==NULL)
    {
      printf("ERROR!:No input file\n");
      exit(0);
    }
  while(fgets(str,100,in))
    {
      if(!proceed)
	{
	  if(str[0]=='H')
	    {
	      header(str);
	      proceed=1;
	    }
	}
      else
	{
	  if(str[0]=='E')
	    {
	      end();
	      break;
	    }
	  if(str[0]=='T') load_text(str);
	}
    }
  fclose(in);

}




/*

OUTPUT::

s0901@T-R-SL-1-32:~/s6$ gcc loader.c
s0901@T-R-SL-1-32:~/s6$ ./a.out PGMNAM.obj 
created o/p file:PGMNAM.op 
s0901@T-R-SL-1-32:~/s6$ 

INPUT FILE:::PGMNAM.obj 

HPGMNAM00000000000d 
T00000006000006000009
T0000090400000372
E000000

OUTPUT FILE:::PGMNAM.op 

000000	00000600
000004	0009XXXX
000008	XX000003
00000c	72

*/
