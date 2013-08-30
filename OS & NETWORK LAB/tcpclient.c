//TCP CLIENT

#include<sys/socket.h>
#include<sys/types.h>
#include<stdio.h>
#include<errno.h>
#include<strings.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<stdlib.h>
#include<string.h>
#define LEN 1024

int main(int arc,char *argv[])
{
  int sock;
  struct sockaddr_in server;
  int ret,len;
  char input[LEN],output[LEN];
  //creaate socket
  sock=socket(AF_INET,SOCK_STREAM,0);
  if(sock==-1)
    {
      perror("\error in creating socket");
      exit(-1);
    }
  server.sin_family=AF_INET;
  server.sin_addr.s_addr=inet_addr(argv[1]);
  server.sin_port=htons(atoi(argv[2]));
  bzero(&server.sin_zero,8);
  //connect to the server
  ret=connect(sock,(struct sockaddr *)&server,sizeof(struct sockaddr_in));
  if(ret==-1)
    {
      perror("\nerror in getting connection ");
      exit(-1);
    }
  while(1)
    {
      fgets(input,LEN,stdin);
      if(strcmp(input,"q")!=0)
	{
	  send(sock,input,strlen(input),0);
	  
	  len=recv(sock,output,LEN,0);
	  output[len]='\0';
	  printf("\n%s",output);
	}
      else
	break;
    }
  close(sock);
    return 0;
}
