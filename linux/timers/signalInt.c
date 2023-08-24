#include<signal.h>
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>

void intSignal(int sigNum)
{

	printf("Signal called with signal numer = %d\n", sigNum);
	exit(0);

}

//this file will tell the sigint usage   " CTRL + c "
int main(void)
{
	signal(SIGINT, intSignal);
	while(1)
	{
	
		sleep(1);
		printf("In while loop \n");
	}


	return 0;
}
