#include<stdio.h>
#include<stdlib.h>
#include<signal.h>

static void sig_alarm(int signo)
{
	printf("alarm!!!!\n");
}

int main(void)
{
	int rest;
	if(signal(SIGALRM, sig_alarm) == SIG_ERR){
		perror("signal");
		exit(EXIT_FAILURE);
	}
	alarm(5);

	printf("I;m go to sleep\n");
	rest = sleep(2);
	printf("I;m wake up time : %d\n", rest);

	pause();
	exit(EXIT_SUCCESS);
}

