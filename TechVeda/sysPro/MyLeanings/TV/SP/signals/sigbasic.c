#include<stdio.h>
#include<signal.h>
#include<stdlib.h>
#include<unistd.h>
void mySignalHandler(int signum)
{

	printf("called = %s, signalnum = %d\n" ,__func__, signum);

}


int main(void)
{
	signal(SIGINT, mySignalHandler);

	while(1)
	{
		printf("Inside while\n");
		sleep(20);
	}

	return 0;
}
