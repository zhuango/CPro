#include<stdio.h>
#include<stdlib.h>
#include<signal.h>


int main(void)
{
	sigset_t sigset;
	int err;
	
	if((err = sigfillset(&sigset)) < 0){/* fill 0 into sigset */
		perror("sigfillset");
		exit(EXIT_FAILURE);
	}
	printf("fill signal : %d\n",sigset);

	if((err = sigemptyset(&sigset)) < 0){
		perror("sigemptyset");
		exit(EXIT_FAILURE);
	}; /* set a empty signal set */
	printf("empty signal : %d\n",sigset);


	if(err = sigaddset(&sigset, SIGUSR1) < 0){/* add signal SIGUSR1 into the sigset */
		perror("sigaddset");
		exit(EXIT_FAILURE);
	}

	printf("SIGUSR1 is : %d\n", SIGUSR1);
	printf("add SIGUSR1 sigset: %d\n",sigset);
	if((err = sigismember(&sigset, SIGUSR1)) < 0){
		perror("sigismember");
		exit(EXIT_FAILURE);
	}
	printf("is there a signal named SIGUSR1!: %d\n",err);

	if(err = sigdelset(&sigset, SIGUSR1) < 0){/* delete the signal SIGUSR1 */
		perror("sigdelset");
		exit(EXIT_FAILURE);
	}
	printf("delete SIGUSR1 sigset: %d\n",sigset);

	if(err = sigismember(&sigset, SIGUSR1) < 0){/* test the signal SIGUSR1 */
		perror("sigismember");
		exit(EXIT_FAILURE);
	}
	printf("is there a signal named SIGUSR1: %d\n", err);

	return 0;
}
