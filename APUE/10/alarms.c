#include<stdio.h>
#include<signal.h>
#include<stdlib.h>
#include<setjmp.h>
#include<pthread.h>
static jmp_buf env;
void sig_alrm(int signo)
{
	printf("nima\n");
	longjmp(env, 1);
}

void *print(void *arg)
{
	int i=0;
	while(1){
		sleep(1);
		printf("time go %d\n",++i);
	}
}

int main(void)
{
	pthread_t tid;
	if(signal(SIGALRM, sig_alrm) < 0){
		perror("signal");
		exit(EXIT_FAILURE);
	}

	if(pthread_create(&tid, NULL, print, NULL) < 0){
		perror("phread_create");
		exit(EXIT_FAILURE);
	}

	alarm(5);
	if(setjmp(env) < 0){
		perror("setjmp");
		exit(EXIT_FAILURE);
	}

	printf("I'm gono sleep\n");
	sleep(10);
	printf("I'm sleep 6 seconds\n");

	return 0;
}
