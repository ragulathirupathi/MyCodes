#include<stdio.h>
#include<fcntl.h>

int main(void)
{
	int fd = open("testfile", O_CREAT , 0777);

	if( fd == -1)
		printf("not opened\n");
	return 0;
}
