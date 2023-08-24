#include<signal.h>
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>

void commonSigHandler(int sigNum)
{

	printf("Signal called with signal numer = %d\n", sigNum);
	if( SIGUSR1 == sigNum )
	{
		printf(" SIGUSR1 raised\n");
		
	}
	else if( SIGUSR2 == sigNum )
	{
	
		printf(" SIGUSR2 raised\n");
	}
	else
	{
	
		printf(" Interrupt  raised and pasue will success\n");
	}
	
	
	

}

//this file will tell the sigint usage   " CTRL + c "
int main(void)
{
	signal(SIGINT, commonSigHandler);
	signal(SIGUSR1,commonSigHandler);
	signal(SIGUSR2,commonSigHandler);
	pause();
	while(1)
	{
	
		printf("In while loop \n");
		sleep(10);
		raise(SIGUSR1);
		raise(SIGUSR2);
		
	}


	return 0;
}
