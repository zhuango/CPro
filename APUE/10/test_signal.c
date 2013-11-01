#include<stdio.h>
#include<stdlib.h>
#include<signal.h>

void sig_del(int signo);

int main(void)
{
	if(signal(SIGUSR1, sig_del) == SIG_DFL){/* the old signal handler fucntion is SIG_DFL */
		printf("Yes , return old handler\n");
		exit(EXIT_SUCCESS);
	}

	return 0;
}

void sig_del(int signo)
{}
