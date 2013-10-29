#include<stdio.h>
#include<stdlib.h>
#include<signal.h>

static void sig_usr(int signo);

int main(void)
{
	if(signal(SIGUSR1, sig_usr) == SIG_ERR){
		perror("signal1");
		exit(EXIT_FAILURE);
	}
	if(signal(SIGUSR2, sig_usr) == SIG_ERR){
		perror("signal2");
		exit(EXIT_FAILURE);
	}
//	for( ; ; )
		pause();
}

static void sig_usr(int signo)
{
	if(signo == SIGUSR1)
		printf("received signal 1\n");
	else if(signo == SIGUSR2)
		printf("received signal 2\n");
	else {
		printf("recceived signal %d\n", signo);
	}
}
