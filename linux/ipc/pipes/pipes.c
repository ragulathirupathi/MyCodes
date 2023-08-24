#include<stdio.h>
#include<unistd.h>
#include <string.h>

int main(void)
{
	int pipefd[2];
	const char *pwstr = "This is the writing string";
	char buffer[256];
	if( -1 == pipe(pipefd))
	{
		printf("Failed to create the pipes\n");
		return -1;
	}
	
	write(pipefd[1],pwstr,strlen(pwstr));
	read(pipefd[0],buffer,strlen(pwstr));
	
	printf("Read data = %s",buffer);
	
	return 0;



}
