#include<stdio.h>
#include<stdlib.h>
#include<signal.h>
#include<setjmp.h>
#include<sys/types.h>

static jmp_buf env;

void jmp(int signo)
{
	printf("jmp!!!\n");
	longjmp(env,1);
}

int main(void)
{
	sigset_t set;

	if(signal(SIGALRM, jmp) == SIG_ERR){
		perror("signal");
		exit(EXIT_FAILURE);
	}

	/* set position that the longjmp function jmp */
	if(setjmp(env) < 0){
		perror("setjmp");
		exit(EXIT_FAILURE);
	}
	/* set the mask as 0 */
/*
	sigemptyset(&set);
	if(sigprocmask(SIG_SETMASK, &set, NULL) < 0){
		perror("sigprocmask");
		exit(EXIT_FAILURE);
	}
*/

	alarm(2);/* if I don't change the mask, then the alarm aignal will be mask
   			if you alarm again ,it's useless the signal will not be call	*/

	sleep(5);

	return 0;
}
