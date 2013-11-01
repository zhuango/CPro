#include<stdio.h>
#include<sys/time.h>
#include<signal.h>
#include<stdlib.h>

int main(void)
{
	void countdown(int);

	signal(SIGALRM, countdown);/*set the signal function*/
	if(set_ticker(500) == -1)
		perror("set_ticker");
	else
		while(1)
			pause();

	return 0;
}

void countdown(int signum)
{
	static int num = 10;
	printf("%d.. ",num--);
	fflush(stdout);
	if(num < 0){
		printf("DONE!\n");
		exit(EXIT_SUCCESS);
	}
}

int set_ticker(int n_msecs)
{
	struct itimerval new_timeset;
	long n_sec, n_usecs;

	n_sec = n_msecs/1000;			//the second
	n_usecs = (n_msecs % 1000) * 1000L;	//the usecond

	/*set the loop time*/
	new_timeset.it_interval.tv_sec = n_sec;
	new_timeset.it_interval.tv_usec = n_usecs;

	/*set the begin time*/
	new_timeset.it_value.tv_sec = n_sec;
	new_timeset.it_value.tv_usec = n_usecs;

	return setitimer(ITIMER_REAL, &new_timeset, NULL);
}
