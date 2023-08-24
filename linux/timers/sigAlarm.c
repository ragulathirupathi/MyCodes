//This file intent is to make use of the signal SIGALRM and generate the timer interrupt for every 1 sec

#include<signal.h>
#include<stdio.h>
#include<unistd.h>



//just the declaration general declaration as below




void oneSecFunction(int sigNum)
{

	printf("Signal called with signal numer = %d\n", sigNum);
	alarm(1); //will make a loop ,


}



int main(void)
{
	printf("Entering main\n");
	signal(SIGALRM, oneSecFunction);
	alarm(1);
	while(1)
	{
		sleep(10);
		printf("main running\n");
		
	}
	return 0;



}

