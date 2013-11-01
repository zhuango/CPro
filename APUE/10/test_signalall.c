#include<stdio.h>
#include<stdlib.h>
#include<signal.h>

static void sig_quit(int signo);

int main(void)
{
	sigset_t newmask, oldmask, pendmask;

	if(signal(SIGQUIT, sig_quit) == SIG_ERR){
		perror("signal");
		exit(EXIT_FAILURE);
	}

	sigemptyset(&newmask);
	sigaddset(&newmask, SIGQUIT);

	if(sigprocmask(SIG_BLOCK, &newmask, &oldmask) < 0){
		perror("sigprocmask");
		exit(EXIT_FAILURE);
	}

	printf("SIGQUIT is disabled\n");
	sleep(10);
	
	if(sigpending(&pendmask) < 0){
		perror("sigpenging");
		exit(EXIT_FAILURE);
	}

	if(sigismember(&pendmask, SIGQUIT) < 0){
		perror("sigismember");
		exit(EXIT_FAILURE);
	}

	if(sigprocmask(SIG_SETMASK, &oldmask, NULL) < 0){
		perror("sigprocmask");
		exit(EXIT_FAILURE);
	}
	printf("SIGQUIT is enabled\n");
	sleep(5);

	exit(EXIT_SUCCESS);
}

static void sig_quit(int signo)
{
	printf("caught SIGQUIT\n");
	if(signal(SIGQUIT, sig_quit) < 0){
		perror("signal");
		exit(EXIT_FAILURE);
	}

}
