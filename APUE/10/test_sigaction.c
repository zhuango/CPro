#include<stdio.h>
#include<stdlib.h>
#include<signal.h>

typedef void Sigfunc(int);

int signumber = 0;

void print(int signo)
{
	signumber++;
	printf("alrm %d~~~~\n",signumber);
	sleep(10);
	printf("alrm %d end\n", signumber);
}

Sigfunc *Signal(int signo, Sigfunc *func)
{
	struct sigaction act, oact;
	
	act.sa_handler = func;
	sigemptyset(&act.sa_mask);

	act.sa_flags = 0;
	if(signo == SIGALRM){
#ifdef	SA_INTERRUPT
		act.sa_flags |= SA_INTERRUPT;
#endif
	}else{
#ifdef	SA_RESTART
		act.sa_flags |= SA_RESTART;
#endif
	}

	if(sigaction(signo, &act, &oact) < 0){
		return (SIG_ERR);
	}

	return (oact.sa_handler);
}


int main(void)
{
	if(Signal(SIGALRM, print) == SIG_ERR){
		perror("signal");
		exit(EXIT_FAILURE);
	}

	alarm(2);

	sleep(3);

	exit(EXIT_SUCCESS);
}
