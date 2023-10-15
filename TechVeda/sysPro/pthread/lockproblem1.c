#include<stdio.h>
#include<pthread.h>

pthread_mutex_t mtx;

int testFunction()
{
	pthread_mutex_lock(&mtx);

	printf("This should not be executed\n");
	
	pthread_mutex_unlock(&mtx);
}


void* myThread(void*   ptr)
{

	printf("myThread\n");
	while(1)
	{
		pthread_mutex_lock(&mtx);
		sleep(1);
		printf("Inside the while\n");
		testFunction();
		pthread_mutex_unlock(&mtx);
	}
	pthread_exit(NULL);


}


int main(void)
{
	pthread_t tid;

	pthread_mutexattr_t attr;

//	pthread_mutexattr_settype(&attr,PTHREAD_MUTEX_RECURSIVE);

	pthread_mutex_init(&mtx,&attr);

	tid = pthread_create(&tid, NULL,myThread,NULL);

	//assuming thread created successfully no erro check condition 
	

	pthread_exit(NULL); //would wait until all threads completed its execution 


	return 0;
}
