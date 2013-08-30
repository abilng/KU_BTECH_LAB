//TCP SERVER

#include<sys/socket.h>
#include<sys/types.h>
#include<stdio.h>
#include<errno.h>
#include<strings.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<stdlib.h>
#include<unistd.h>
#define LEN 1024
#define MAX_CLIENTS 5

int main(int argc,char *argv[])
{
  int sock;
  int new,data_len;
  int ret,sock_len;
  socklen_t val;
  struct sockaddr_in sock_server;
  struct sockaddr_in sock_client;
  ssize_t size;
  char msg[LEN];
  //create socket
  sock=socket(AF_INET,SOCK_STREAM,0);
  if(sock==-1)
    {
      perror("\error in creating socket");
      exit(-1);
    }
  sock_server.sin_family=AF_INET;
  //sock_server.sin_port=htons(5000);
  sock_server.sin_port=htons(atoi(argv[1]));
  sock_server.sin_addr.s_addr=INADDR_ANY;
  bzero(&sock_server.sin_zero,8);
  sock_len=sizeof(struct sockaddr_in);
  //bind socket to interface
  ret=bind(sock,(struct sockaddr*)&sock_server,sizeof(sock_server));
    if(ret==-1)
    {
      perror("\nerror in binding socket to the interface");
      exit(-1);
    }
  //listen to connections from client
  ret=listen(sock,MAX_CLIENTS);
  if(ret==-1)
    {
      perror("\nerror in listen");
      exit(-1);
    }
  //accept connetion from client
  while(1)
    {
      new=accept(sock,(struct sockaddr *)&sock_client,&sock_len);
      if(new==-1)
		{
		  perror("\naccepting new connection failed");
		  exit(-1);
	}
      else
	{
	  printf("\nnewclient connected from port %d and IP %s",ntohs(sock_client.sin_port),inet_ntoa(sock_client.sin_addr));
	  data_len=1;
	  while(data_len)
	    {
	      data_len=recv(new,msg,LEN,0);
	      if(data_len)
			{
			  send(new,msg,data_len,0);
			  msg[data_len]='\0';
			  printf("\nsend messsage :%s",msg);
			}
		}
		printf("\nclient disconnected");
		close(new);
		}
    }
    return 0;
}
