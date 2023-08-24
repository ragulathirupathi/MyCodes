#include<stdio.h>
#include<pthread.h>
#include<unistd.h>


static int gVar = 0;
pthread_mutex_t lock;

void* IncrementValue(void)
{
//	pthread_mutex_lock(&lock);
	gVar++;
//	pthread_mutex_unlock(&lock);

}

void* DecrementValue(void )
{
//	pthread_mutex_lock(&lock);
	gVar--;
//	pthread_mutex_unlock(&lock);
}




int main(void)
{
	pthread_t tid[2];
	pthread_mutex_init(&lock,NULL);
	pthread_create(&tid[0],NULL,IncrementValue,NULL);
	pthread_create(&tid[0],NULL,DecrementValue,NULL);
	while(1)
	{
		usleep(1000);
		pthread_mutex_lock(&lock);
		if(gVar != 0)
			printf("Value = %d\n",gVar);
		pthread_mutex_unlock(&lock);
	}


	return 0;
}

