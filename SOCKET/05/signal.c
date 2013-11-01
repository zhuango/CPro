#include<stdio.h>
#include<stdlib.h>
#include<signal.h>

typedef void Sigfunc(int);

Sigfunc *signal(int signo, Sigfunc *func)
{
	struct sigaction act, oact;/* new and old signal configuration */
	act.sa_handler = func;/* func to deal the signal */
	sigemptyset(&act.sa_mask);/* clear the signal mask */
	act.sa_flags = 0;/* flag = 0 */

	if(signo == SIGALRM){
#ifdef SA_INTERRUPT
		act.sa_flags |= SA_INTERRUPT;
#endif
	}else{
#ifdef SA_RESTART
		act.sa_flags |= SA_RESTART;
#endif
	}

	if(sigaction(signo, &act, &oact) < 0)/* set the signal */
		return (SIG_ERR);
	return (oact.sa_handler);
}

