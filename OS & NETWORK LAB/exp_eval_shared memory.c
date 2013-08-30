/*Expression evaluation using fork and shared memory*/

#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/shm.h>
#include<sys/stat.h>
#include<stdlib.h>

#define MEMSIZE 27

main()
{
  int a,b,c,d,e,f,res;
  pid_t pid;
  key_t key;
  int seg_id;
  int *shm_child,*shm_parent;

  key=1432;

  pid=fork();

  if(pid>0)     //parent
    {
      sleep(2);
      printf("Enter the values of c and d:");
      scanf("%d %d",&c,&d);
      e=c*d;
      seg_id=shmget(key,MEMSIZE,IPC_CREAT|0666);
      if(seg_id==-1)
	{
	  printf("Error in creating shm in parent\n");
	  exit(1);
	}
      if((shm_parent=shmat(seg_id,NULL,0))==(int *)-1)
	{
	  printf("Error in attaching parent to memory:\n");
	  exit(1);
	}
      *shm_parent=e;
      printf("The value of (c*d) in memory:%d\n",*shm_parent);
      sleep(5);
    }
  else  //child
    {
      printf("Enter the values of a and b:");
      scanf("%d %d",&a,&b);
      f=a*b;
      sleep(3);
      if((seg_id=shmget(key,MEMSIZE,0666))<0)
	{
	  printf("Error in creating shm in child\n");
	  exit(1);
	}
      //shm_child=shmat(seg_id,NULL,0);
      if((shm_child=shmat(seg_id,NULL,0))==(int *)-1)
	{
	  printf("Error in attaching child to memory\n");
	  exit(1);
	}
      res=f+*shm_child;
      printf("The Result is:%d\n",res);
    }
}
