#include<stdio.h>
#include<unistd.h>
#include<sys/syscall.h>
int main(void)
{
	char msg[] = "Hello World\n";
	ssize_t bytes_written;

	bytes_written = syscall(1,1,msg,14);

	return 0;
}
