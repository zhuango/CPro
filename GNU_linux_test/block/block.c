#include<unistd.h>
#include<signal.h>
#include<stdlib.h>
#include<stdio.h>

void err_quit(char *);

int main(void)
{
	sigset_t newset;

	if( (sigemptyset(&newset)) < 0)
		err_quit("sigemptyset");
	if( (sigaddset(&newset,SIGTERM)) < 0)
		err_quit("sigaddset:SIGTERM");
	if( (sigaddset(&newset,SIGALRM)) < 0)
		err_quit("sigaddset:SIGALRM");

	if( (sigprocmask(SIG_BLOCK,&newset,NULL)) < 0)
		err_quit("sigprocmask");

	pause();
	exit(EXIT_SUCCESS);
}

void err_quit(char *msg)
{
	perror(msg);
	exit(EXIT_FAILURE);
}
