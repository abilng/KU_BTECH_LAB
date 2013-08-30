

//UDP SERVER

#include<sys/socket.h>
#include<sys/types.h>
#include<stdio.h>
#include<errno.h>
#include<strings.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#define LEN 1024
#define MAX_CLIENTS 5

int main(int argc,char *argv[])
{
  int sock;
  int new,datalen;
  int ret,sock_len,len;
  socklen_t val;
  struct sockaddr_in sock_client;
  ssize_t size;
  char msg[LEN];
  //create socket
  sock=socket(AF_INET,SOCK_DGRAM,0);
  if(sock==-1)
    {
      perror("\error in creating socket");
      exit(-1);
    }
  sock_client.sin_family=AF_INET;
  //sock_server.sin_port=htons(5000);
  sock_client.sin_port=htons(atoi(argv[1]));
  sock_client.sin_addr.s_addr=INADDR_ANY;
  bzero(&sock_client.sin_zero,8);
  sock_len=sizeof(struct sockaddr_in);
  //bind socket to interface
  ret=bind(sock,(struct sockaddr*)&sock_client,sizeof(sock_client));
    if(ret==-1)
    {
      perror("\nerror in binding socket to the interface");
      exit(-1);
    }
  //communication
  while(1)
    {
      datalen=sizeof(sock_client);
    len=recvfrom(sock,msg,LEN,0,(struct sockaddr*)&sock_client,&datalen);
    printf("\n%s ",msg);
    len=sendto(sock,msg,LEN,0,(struct sockaddr*)&sock_client,datalen);
    if(strncmp(msg,"quit",3)==0)
      {
	printf("\nquiting server\n");
	break;
      }
    }
close(sock);
return 0;
}
