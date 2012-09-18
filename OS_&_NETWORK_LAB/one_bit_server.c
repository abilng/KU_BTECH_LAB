#include<sys/socket.h>
#include<sys/types.h>
#include<string.h>
#include<stdlib.h>
#include<arpa/inet.h>
#include<netinet/in.h>
#include<errno.h>
#include<unistd.h>
#define LEN 1024
#define MAX_CLIENTS 5

void main()
{
  struct sockaddr_in server;
  struct sockaddr_in client;
  int sock;
  sock=(AF_INET,SOCK_DGRAM,0);
  if(sock==-1)
    {
      perror("\nerror in creating socket");
      exit(-1);
    }
}
