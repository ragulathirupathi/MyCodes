#include<stdio.h>
#include<unistd.h>
#include<sys/syscall.h>
int main(void)
{

	char data[20] = "Test data\n";
	syscall(1,1,data,10);
	return 0;
}
