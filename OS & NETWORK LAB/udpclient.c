//UDP CLIENT

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
  int ret,len,datalen;
  char input[LEN],output[LEN];
  //creaate socket
  sock=socket(AF_INET,SOCK_DGRAM,0);
  if(sock==-1)
    {
      perror("\error in creating socket");
      exit(-1);
    }
  server.sin_family=AF_INET;
  server.sin_addr.s_addr=inet_addr(argv[1]);
  server.sin_port=htons(atoi(argv[2]));
  bzero(&server.sin_zero,8);
  while(1)
    {
     datalen=sizeof(server);
     fgets(input,LEN,stdin);
     len= sendto(sock,input,LEN,0,(struct sockaddr*)&server,datalen);
     len=recvfrom(sock,output,LEN,0,(struct sockaddr*)&server,&datalen);
     // output[len]='\0';
     if(strncmp(input,"quit",3)==0)
       break;
     printf("\n%s",output);
    }
  close(sock);
  return 0;
}
