#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<time.h>
#include<sys/time.h>

extern int makepthread(void *(*)(void*), void *);

struct to_info{
	void (*to_fn)(void *);/* function have to call */
	void *to_arg;			/* function's arg */
	struct timespec to_wait;/* time you have to wait */
};

#define SECTONSEC 1000000000/* seconds to nanoseconds */
#define USECTONSEC 1000		/* microsecons ro nanoseconds */

void *timeout_helper(void*arg)
{
	struct to_info *tip;/* get the void pointer arg */
	tip = (struct to_info*)arg;/* turn to struct to_info * */
	nanosleep(&tip->to_wait, NULL);/* wait correct time */
	(*tip->to_fn)(tip->to_arg);/* call the function( retry() ) */

	return (0);
}

/* main will call this function */
void timeout(const struct timespec *when, void (*func)(void *), void *arg)
{
	struct timespec now;/* time for now */
	struct timeval tv;/* for function gettimeofday */
	struct to_info *tip;/* pthread info struct */
	int err;

	gettimeofday(&tv, NULL);/* get the time for now */
	now.tv_sec = tv.tv_sec;/* get the seconds */
	now.tv_nsec = tv.tv_usec * USECTONSEC;/* get the nanoseconds */

	/* not go over now time */
	if((when->tv_sec > now.tv_sec) ||
				(when->tv_sec == now.tv_sec && when->tv_nsec > now.tv_nsec)){
		tip = malloc(sizeof(struct to_info));/* get space for the struct to_info */
		if(tip != NULL){/* get space successfully */
			tip->to_fn = func;/* set the struct elemetent function */
			tip->to_arg = arg;/* set the args */
			tip->to_wait.tv_sec = when->tv_sec - now.tv_sec;/* set the time struct second part */

			if(when->tv_nsec >= now.tv_nsec){/* the nanosecond is later than now ??? */
				tip->to_wait.tv_nsec = when->tv_nsec - now.tv_nsec;/* nanosecond is later than now */
			}else{
				tip->to_wait.tv_sec --;/* not later than now, then second go down a second */
				tip->to_wait.tv_nsec = SECTONSEC - now.tv_nsec + when->tv_nsec;/* get a second , is SECTONSEC nanosecond */
			}

			err = makepthread(timeout_helper, (void*)tip);/* make a new pthread, the new pthread info is in tip */
			if(err != 0){/* error? */
				return ;
			}
		}
	}
	(*func)(arg);/* if the time is go over, then this function will call func(retey()) function! */
}

pthread_mutexattr_t attr;
pthread_mutex_t mutex;

/* new pthread go to call */
void retry(void *arg)
{
	pthread_mutex_lock(&mutex);
	printf("pthread function retry() get the lock and go to sleep ...\n");
	sleep(4);
	pthread_mutex_unlock(&mutex);
	printf("pthread function unlock the lock\n");
}

int main(void)
{
	int err, condition = 1, arg = 1;
	struct timespec when;

	/* init the mutex attr */
	if((err = pthread_mutexattr_init(&attr)) != 0){
		perror("pthread_mutexattr_init");
		exit(EXIT_FAILURE);
	}
	/* set the mutex states (PTHREAD_MUTEX_RECUSIVE) */
	if((err = pthread_mutexattr_settype(&attr,
					PTHREAD_MUTEX_RECURSIVE)) != 0){
		perror("Pthread_mutexattr_settype");
		exit(EXIT_FAILURE);
	}
	/* init the pthread states */
	if((err = pthread_mutex_init(&mutex,&attr)) != 0){
		perror("pthread_mutex_init");
		exit(EXIT_FAILURE);
	}

	pthread_mutex_lock(&mutex);/* get the lock */
	printf("main get the lock already\n");
	if(condition){
		timeout(&when, retry, (void*)arg);/* call the timeout function */
	}
	printf("timeout returned \n");
	pthread_mutex_unlock(&mutex);/* unlock */
	printf("main unlock the mutex\n");

	exit(EXIT_SUCCESS);/* exit */
}

