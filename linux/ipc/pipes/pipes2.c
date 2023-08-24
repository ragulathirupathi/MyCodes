#include<stdio.h>
#include<unistd.h>
#include <string.h>

int main(void)
{
	int pipefd1[2]; //parent write, child read
	int pipefd2[2]; //parent read, child write
	if( -1 == pipe(pipefd1) )
	{
		printf("Failed to create the pipes \n");
		return -1;
	}
	if( -1 == pipe(pipefd2))
	{
		printf("Failed to create the pipes \n");
		return -1;
	}
	
	pid_t pidchild;
	
	pidchild = fork();
	
	if(pidchild == 0)
	{
		//child process
		char buffer[256];
		close(pipefd1[1]); //closing child write
		close(pipefd2[0]); //closing child read
		printf("child process ready to send data\n");
		int inc = 10;
		while(inc)
		{
			write(pipefd2[1],"Child data",8);
			inc--;	
			sleep(1);	
		}
		printf("child process ready to receive  data\n");
		inc = 10;
		while(inc)
		{
			read(pipefd1[0],buffer,8);
			inc--;	
			printf("Read data by child = %s\n",buffer);	
		}
		
		
	
	
	}
	else
	{
		//parent process
		char buffer[256];
		close(pipefd1[0]); //closing parent read
		close(pipefd2[1]); //closing parent write
		printf("parent process ready to receive data\n");
		int inc = 10;
		while(inc)
		{
			read(pipefd2[0],buffer,8);
			inc--;	
			printf("Read data by parent = %s\n",buffer);	
		}
		inc = 10;
		printf("parent process ready to send data\n");
		while(inc)
		{
			write(pipefd1[1],"Parent data",8);
			inc--;	
			sleep(1);	
		}

	
	
	}
	
	
	return 0;



}
