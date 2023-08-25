#include<stdio.h>
#include<signal.h>
#include<stdlib.h>
#include<unistd.h>


int main(void)
{
	sigset_t set;
	sigemptyset(&set);
	sigaddset(&set,62);
	sigaddset(&set,60);
	sigaddset(&set,58);
	if(-1 == sigprocmask(SIG_BLOCK | SIG_SETMASK, &set, NULL))
		return 0;
	
	


	getchar();


	printf("Pending segnals will be shown\n");

	sigset_t mySet;
       	sigpending(&mySet);

	if(sigismember(&mySet, 62))
		printf("Member\n");
	if(sigismember(&mySet, 60))
		printf("pending\n");
	if(sigismember(&mySet, 58))
		printf("Pending\n");

	if(-1 == sigprocmask(SIG_UNBLOCK | SIG_SETMASK, &set, NULL))
		return 0;
	while(1)
	{
		printf("Inside while\n");
		sleep(2);
	}

	return 0;
}

