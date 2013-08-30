
/*Inter Process Communication usimg Message Queue*/

#include<stdio.h>
#include<sys/msg.h>
#include<string.h>

struct mydata
{
  long mtype;
  char message[25];
}mq;

main()
{
  pid_t id;
  char rev[25];
  key_t key;
  int i,j;
  id=fork();
  if(!id)       //receiver-child
    {
      key=ftok("filepath",'a');
      id=msgget(key,0666);
      msgrcv(id,&mq,sizeof(mq.message),2,0);
      printf("RECEIVER:The message \"%s\"  is received\n",mq.message);
   
      for(i=strlen(mq.message)-1,j=0;i>=0;i--,j++)
	rev[j]=mq.message[i];
      rev[j]='\0';
 
      strcpy(mq.message,rev);
      msgsnd(id,&mq,sizeof(mq.message),0);
      printf("RECEIVER:The reverse is sent back\n");
    }
  else         //sender-parent
    {
      mq.mtype=2;
      key=ftok("filepath",'a');
      id=msgget(key,IPC_CREAT|0666);
      printf("SENDER:Enter the message:");
      scanf("%s",mq.message);
      msgsnd(id,&mq,sizeof(mq.message),0);
      msgrcv(id,&mq,sizeof(mq.message),2,0);
      printf("SENDER:The reverse is  %s\n",mq.message);
    }
}

/*
OUTPUT:

SENDER:Enter the message:HELLO
RECEIVER:The message "HELLO"  is received
RECEIVER:The reverse is sent back
SENDER:The reverse is  OLLEH
*/

