#include<stdio.h>
#include<stdlib.h>
#include<signal.h>
#include<errno.h>
int main(void)
{
	sigset_t sigset;
	int errno_save;

	errno_save = errno;
	if(sigprocmask(0, NULL, &sigset) < 0){
		perror("sigprmask");
		exit(EXIT_FAILURE);
	}

	if(sigaddset(&sigset, SIGUSR1) < 0){
		perror("sigaddset");
		exit(EXIT_FAILURE);
	};
	printf("sigmask : %d\n", sigset);
	if(sigismember(&sigset, SIGQUIT)) printf("SIGQUIT\n");
	if(sigismember(&sigset, SIGINT) ) printf("SIGINT\n");
	if(sigismember(&sigset, SIGUSR1)) printf("SIGUSR1\n");
	if(sigismember(&sigset, SIGALRM))printf("SIGALRM\n");

	printf("\n");

	errno = errno_save;

	return 0;
}
