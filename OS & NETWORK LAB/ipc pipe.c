/*Interprocess communication Using Pipe*/

#include<stdio.h>
#include<sys/wait.h>
#include<unistd.h>
#include<stdlib.h>

main()
{
  int pipe_pointer[2],status;
  char message[25];
  pid_t pid;
  if(pipe(pipe_pointer)==-1)
    {
      printf("Error\n");
      exit(1);
    }

  if((pid=fork())==-1)
    {
      printf("Error\n");
      exit(1);
    }
  if(pid==0)   //child
    {
      close(pipe_pointer[0]);         //close read pointer
      printf("In Child Process(Sender):\n");
      printf("Enter the message:");
      scanf("%s",message);
      write(pipe_pointer[1],message,sizeof(message));      //write to pipe
      close(pipe_pointer[1]);//close the write pipe
    }
  else         //parent
    {
      wait(&status);
      close(pipe_pointer[1]);         //close write pointer
      read(pipe_pointer[0],message,25);  //read from pipe into message
      printf("In Parent Process(Receiver):\n");
      printf("Received message is %s\n",message);
      close(pipe_pointer[0]);      //close read pipe
    }
}

/*
OUTPUT:
In Child Process(Sender):
Enter the message:morning
In Parent Process(Receiver):
Received message is morning
*/
