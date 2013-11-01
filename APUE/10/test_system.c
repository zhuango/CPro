#include<stdio.h>
#include<stdlib.h>
#include<signal.h>

static void sig_int(int signo)
{
	printf("caught SIGINT\n");
}

static void sig_quit(int signo)
{
	printf("caught SIGCHLD\n");
}

int main(void)
{
	if(signal(SIGINT, sig_int) == SIG_ERR){
		perror("signal");
		exit(EXIT_FAILURE);
	}

	if(signal(SIGCHLD, sig_quit) == SIG_ERR)
	{
		perror("signal");
		exit(EXIT_FAILURE);
	}

	if(system("/bin/ed") < 0){
		perror("system");
		exit(EXIT_FAILURE);
	}

	exit(EXIT_SUCCESS);
}
