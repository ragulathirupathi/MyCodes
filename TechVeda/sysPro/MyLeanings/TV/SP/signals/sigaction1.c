#include<stdio.h>
#include<signal.h>
#include<stdlib.h>
#include<unistd.h>
void mySignalHandler(int signum)
{

	printf("called = %s, signalnum = %d\n" ,__func__, signum);
//	sleep(8);
}


int main(void)
{
	//signal(SIGINT, mySignalHandler);
	struct sigaction act = {0};
	//act.sa_flags = SA_NODEFER;
	act.sa_flags = SA_RESTART;
//	act.sa_flags = SA_RESTORER;
	act.sa_handler = mySignalHandler;
	int ret = sigaction(SIGINT, &act,NULL);
	if(ret < 0)
		perror("installl error:");
	while(1)
	{
		printf("Inside while\n");
		sleep(20);
	}

	return 0;
}

