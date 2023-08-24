#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<unistd.h>
pthread_mutex_t gMutex;
pthread_mutex_t gDeadLockOne;
pthread_mutex_t gDeadLockTwo;
void* ThreadOne(void *arg)
{
  int num = 2000;
  pthread_mutex_lock(&gMutex);
  while(num)
  {
	  printf("*");
	  num--;
	  usleep(10);
  }
  pthread_mutex_unlock(&gMutex);
}

void* ThreadTwo(void *arg)
{

  int num = 2000;
  pthread_mutex_lock(&gMutex);
  while(num)
  {
	  printf("#");
	  num--;
	  usleep(10);
  }
  pthread_mutex_unlock(&gMutex);



}


void* DeadLockOne(void* arg)
{
	int num = 10000;
	while(num)
	{
		pthread_mutex_lock(&gDeadLockOne);
		sleep(1);
		pthread_mutex_lock(&gDeadLockTwo);
		printf("Deadlock should happen\n");
		usleep(10);
		num--;
		pthread_mutex_unlock(&gDeadLockOne);
		pthread_mutex_unlock(&gDeadLockTwo);
	}
}
void* DeadLockTwo(void* arg)
{
	int num = 10000;
	while(num)
	{
		pthread_mutex_lock(&gDeadLockOne);
		sleep(1);
		pthread_mutex_lock(&gDeadLockTwo);
		printf("Deadlock should happen\n");
		usleep(10);
		num--;
		pthread_mutex_unlock(&gDeadLockOne);
		pthread_mutex_unlock(&gDeadLockTwo);
	}
}

int main(void)
{
     pthread_t tid[4];
#if 0
     pthread_create(&tid[0],NULL,&ThreadOne,NULL);
     pthread_create(&tid[1],NULL,&ThreadTwo,NULL);
     pthread_mutex_init(&gMutex,NULL);
     pthread_join(tid[0],NULL);
     pthread_join(tid[1],NULL);
     pthread_mutex_destroy(&gMutex);
#endif
     pthread_create(&tid[2],NULL,&DeadLockOne,NULL);
     pthread_create(&tid[3],NULL,&DeadLockTwo,NULL);
     pthread_mutex_init(&gDeadLockOne,NULL);
     pthread_mutex_init(&gDeadLockTwo,NULL);
     pthread_join(tid[2],NULL);
     pthread_join(tid[3],NULL);
     pthread_mutex_destroy(&gDeadLockOne);
     pthread_mutex_destroy(&gDeadLockTwo);
     printf("Main thread exiting\r\n");
     return 0;
}
