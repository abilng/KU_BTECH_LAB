#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<semaphore.h>
#include<pthread.h>

void *func(int n);
pthread_t philosopher[15];
pthread_mutex_t chopstick[15];
int N;

int main()
{
  int i,k;
  void *exit_status;
  printf("\nenter the no of philosohers :");
  scanf("%d",&N);
  for(i=0;i<N;i++)
    {
      k=pthread_mutex_init(&chopstick[i],NULL);
      if(k==-1)
	{
	  printf("\nmutex failed :)");
	  exit(1);
	}
    }
  for(i=0;i<N;i++)
    {
      k=pthread_create(&philosopher[i],NULL,(void *)func,(int *)i);
      if(k!=0)
	{
	  printf("\nthread creation failed :");
	  exit(1);
	}
    }
  for(i=0;i<N;i++)
    {
      k=pthread_join(philosopher[i],&exit_status);
      if(k!=0)
	{
	  printf("\nmutex is still running");
	  exit(1);
	}
    }
  for(i=0;i<N;i++)
    {
      k=pthread_mutex_destroy(&chopstick[i]);
      if(k!=0)
	{
	  printf("\nthread destroy failed :");
	  exit(1);
	}
    }
  return 0;
}


void *func(int n)
{
  printf("\nphilosopher %d is thinking ",n+1);
  pthread_mutex_lock(&chopstick[n]);
  pthread_mutex_lock(&chopstick[(n+1)%N]);
  printf("\nphilosopher %d is eating ",n+1);
  sleep(3);
  printf("\nphilosopher %d has finished eating ",n+1);
  pthread_mutex_unlock(&chopstick[n]);
  pthread_mutex_unlock(&chopstick[(n+1)%N]);
}
