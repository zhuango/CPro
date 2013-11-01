#include<signal.h>
#include<stdlib.h>
#include<stdio.h>

void err_quit(char *);

int main(void)
{
	sigset_t newset;

	if( (sigemptyset(&newset)) < 0)
		err_quit("sigemptyset");

	if( (sigaddset(&newset,SIGCHLD)) < 0)
		err_quit("sigaddset");

	if( (sigismember(&newset,SIGCHLD)))
		puts("SIGCHLD is in signal mask");
	else
		puts("SIGCHLD is not in signal mask");

	if(sigismember(&newset,SIGTERM))
		puts("SIGTERM is in signal mask");
	else
		puts("SIGTERM is not in sugnal mask");

	exit(EXIT_SUCCESS);
}

void err_quit(char *msg)
{
	perror(msg);
	exit(EXIT_FAILURE);
}
