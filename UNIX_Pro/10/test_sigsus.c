#include<stdio.h>
#include<signal.h>
#include<stdlib.h>

void print_mask(char *message)
{
	sigset_t sigset;
	if(sigprocmask(0,NULL, &sigset) < 0){
		perror("sigprocmask");
		exit(EXIT_FAILURE);
	}
	printf("%s %d\n", message, sigset);
}

static void sig_int(int);

int main(void)
{
	sigset_t newmask, waitmask, oldmask;
	printf("++++++++++++++++++++++++++++++++++++++++\n");
	print_mask("main program start: ");
	if(signal(SIGINT, sig_int) == SIG_ERR){
		perror("signal");
		exit(EXIT_FAILURE);
	}

	sigemptyset(&waitmask);
	sigaddset(&waitmask, SIGUSR1);
	sigemptyset(&newmask);
	sigaddset(&newmask, SIGINT);
	
	if(sigprocmask(SIG_BLOCK, &newmask, &oldmask) < 0){
		perror("sigprocmask");
		exit(EXIT_FAILURE);
	}

	print_mask("SIGINT signal die: ");

	if(sigsuspend(&waitmask) != -1){
		perror("sigsuspend");
		exit(EXIT_FAILURE);
	}

	print_mask("suspend SIGUSR1: ");

	if(sigprocmask(SIG_SETMASK, &oldmask, NULL) < 0){
		perror("sigprocmask");
		exit(EXIT_FAILURE);
	}

	print_mask("program exit: ");

	exit(EXIT_SUCCESS);
}

static void sig_int(int signo)
{
	print_mask("in sig_int ");
}
