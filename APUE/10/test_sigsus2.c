#include<stdio.h>
#include<stdlib.h>
#include<signal.h>

volatile sig_atomic_t quitflag;

static void sig_int(int signo)
{
	if(signo == SIGINT){
		printf("interrup\n");
	}else if(signo == SIGQUIT){
		quitflag = 1;
	}
}

int main(void)
{
	sigset_t newmask, oldmask, zeromask;

	if(signal(SIGQUIT, sig_int) == SIG_ERR){
		perror("signal");
		exit(EXIT_FAILURE);
	}if(signal(SIGINT, sig_int) == SIG_ERR){
		perror("signal");
		exit(EXIT_FAILURE);
	}

	sigemptyset(&zeromask);
	sigemptyset(&newmask);
	sigaddset(&newmask, SIGQUIT);

	if(sigprocmask(SIG_BLOCK, &newmask, &oldmask) < 0){
		perror("sigprocmask");
		exit(EXIT_FAILURE);
	}

	while(quitflag == 0)
		sigsuspend(&zeromask);

	printf("you get the quit key????\n");

	quitflag = 0;

	if(sigprocmask(SIG_SETMASK, &oldmask, NULL) < 0){
		perror("sigprocmask");
		exit(EXIT_FAILURE);
	}

	exit(EXIT_SUCCESS);
}
