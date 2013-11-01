#include<sys/types.h>
#include<unistd.h>
#include<signal.h>
#include<stdio.h>
#include<stdlib.h>

int main(void)
{
	sigset_t set,pendset;
	struct sigaction action;

	sigemptyset(&set);

	sigaddset(&set,SIGTERM);
	sigprocmask(SIG_BLOCK,&set,NULL);
	kill(getpid(),SIGTERM);
	sigpending(&pendset);

	if( sigismember(&pendset,SIGTERM)) {
		sigemptyset(&action.sa_mask);
		action.sa_handler = SIG_IGN;
		sigaction(SIGTERM,&action,NULL);
	}

	sigprocmask(SIG_UNBLOCK,&set,NULL);
	exit(EXIT_SUCCESS);
}
