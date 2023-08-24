#include<stdlib.h>
#include<stdio.h>
#include <unistd.h>
int main(void)
{
	pid_t pid;
	int   count = 0;
	pid = fork();
	
	if(pid)
	{
		printf("I am the parent pid = %d, ppid = %d\n", getpid(), getppid());
		while(count < 20 )
		{
			sleep(50);
			count++;
			printf("Parent sleep\n");
		}
	}
	else
	{
		printf("I am the child pid = %d, ppid = %d\n", getpid(), getppid());
		while(count < 20 )
		{
			sleep(50);
			count++;
			printf("Child sleep\n");
		}
	}

	return 0;
}
