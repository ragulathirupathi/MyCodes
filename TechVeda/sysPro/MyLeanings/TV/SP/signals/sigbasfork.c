#include<stdio.h>
#include<signal.h>
#include<stdlib.h>
#include<unistd.h>
void mySignalHandler(int signum)
{

	printf("called = %s, signalnum = %d, pid = %d\n" ,__func__, signum,getpid());
	
}


void childHandler(int signum)
{

	printf("called = %s, signalnum = %d, pid = %d\n" ,__func__, signum,getpid());
}

int main(void)
{
	pid_t pid;
//	signal(SIGINT, mySignalHandler);
	pid = fork();
	if(0 == pid)
	{
		while(1)
		{
			char buff[256];
			signal(SIGTSTP, mySignalHandler);
			printf("Inside child  while pid =  %d, ppid = %d\n", getpid(), getppid());
			read(1,buff, 4);
			printf("Came out of the blocked call\n");
			buff[4] = '\0';
			printf("Read data = %s\n",buff);
			sleep(1);
			raise(SIGTSTP);
			//exit(100);
		}
	}
	else
	{
		
		//signal(SIGCHLD, mySignalHandler);
		struct sigaction act= {0};
		act.sa_handler = mySignalHandler;
		act.sa_flags = SA_NOCLDSTOP;
		sigaction(SIGCHLD,&act,NULL);
		while(1)
		{
			printf("Inside parent  while pid =  %d, ppid = %d\n", getpid(), getppid());
			sleep(20);
		}
	}



	return 0;
}
