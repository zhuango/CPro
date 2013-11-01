#include<stdio.h>
#include<signal.h>
#include<stdlib.h>

#define INPUTLEN 100

int main(void)
{
	struct sigaction newhandler;
	sigset_t	 blocked;
	void 		 inthandler();
	char 		 x[INPUTLEN];

	newhandler.sa_handler = inthandler;/*set the signal function*/
	newhandler.sa_flags = SA_RESETHAND | SA_RESTART;/**/

	sigemptyset(&blocked);/*clear the vector of signal*/
	sigaddset(&blocked, SIGQUIT);/*add the signal SIGQUIT block to the vector of signal*/
	newhandler.sa_mask = blocked;

	if(sigaction(SIGINT, &newhandler, NULL) == -1){
		perror("sigaciton");
		exit(EXIT_FAILURE);
	}else
		while(1){
			fgets(x, INPUTLEN, stdin);
			printf("input: %s",x);
		}
}

void inthandler(int s)
{
	printf("Calles with signal %d\n",s);
	sleep(s);
	printf("done handling signal %d\n",s);
}

