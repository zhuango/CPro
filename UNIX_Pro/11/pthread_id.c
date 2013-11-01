#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>

pthread_t ntid;/* use to create new pthread */

void printids(const char *s)/* print the pthread id */
{
	pid_t	pid;
	pthread_t 	tid;

	pid = getpid();/* print the process is */
	tid = pthread_self();/* get the pthread is */
	/* print info  */
	printf("%s pid %u tid %u (0x%x)\n", s, (unsigned int)pid, (unsigned int)tid, (unsigned int)tid);
}

/* new pthread function */
void *thr_fn(void *arg)
{
	printids("new thread: ");
	return ((void*)0);/* return (void*)0 */
}

int main(void)
{
	int err;
	err = pthread_create(&ntid, NULL, thr_fn, NULL);/* create a new pthread */
	if(err != 0){/* error? */
		perror("pthread_create");
		exit(EXIT_FAILURE);
	}
	printf("+++++++++++++++++%u\n", ntid);/* the pthread id in this value */
	printids("main thread: ");/* print the info */
	sleep(1);/* sleep 1 seconds */
	exit(EXIT_SUCCESS);/* exit */
}
