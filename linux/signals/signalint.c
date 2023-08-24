#include<stdio.h>
#include<unistd.h>
#include<signal.h>
#include<stdlib.h>

void SigInterruptHandler(int signalNumber)
{
	printf("Signal received successfully\r\n");
	exit(0);
}
int main(void)
{
        if( signal(SIGINT, SigInterruptHandler) == SIG_ERR)
	{
		printf("can not register signal\n");
		exit(0);
	}
	for(;;)
	{
		
		printf("Inside the for loop");
		sleep(1);
	}
	return 0;
}
