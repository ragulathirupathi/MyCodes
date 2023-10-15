#include<stdio.h>
#include<pthread.h>
#include<semaphore.h>

int gData[1000];
int inde = 0;

sem_t wait_sem1, wait_sem2;

void fillData(void)
{
	for(int loop = 0; loop < 50; loop++)
	{
		gData[loop] = loop;
	}
}





void* evenThread(void* ptr)
{

	printf("This is even index printer thread\n");
	while(1)
	{
		sem_wait(&wait_sem2);
		printf("E= %d \n", gData[inde++]);
		if(inde >= 50)
			break;
		sem_post(&wait_sem1);	
	}
	pthread_exit(NULL);


}

void* oddThread(void* ptr)
{

	printf("This is odd index printer thread\n");
	while(1)
	{
		sem_wait(&wait_sem1);
		
		if(inde >= 50)
			break;
		printf("O = %d \n", gData[inde++]);

		sem_post(&wait_sem2);

	}
	pthread_exit(NULL);

}

int main(void)
{
	pthread_t tidEven, tidOdd;
	
	sem_init(&wait_sem1,0,0);
	sem_init(&wait_sem2,0,1);
	fillData();

	pthread_create(&tidEven, NULL,evenThread,NULL);
	sleep(2);
	pthread_create(&tidOdd, NULL,oddThread,NULL);

	//assuming thread created successfully no erro check condition 
	

	pthread_exit(NULL); //would wait until all threads completed its execution 


	return 0;
}
