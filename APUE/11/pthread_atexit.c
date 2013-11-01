#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>


/* if you exited, then you may call this funtion */
void cleanup(void *arg)
{
	printf("cleanup : %s\n", (char*)arg);
}

/* pthread 1 function */
void *thr_fn1(void *arg)
{
	printf("thread 1 start\n");
	pthread_cleanup_push(cleanup, "thread 1 first handler");/* set the first handler */
	pthread_cleanup_push(cleanup, "thread 1 second handler");/* set the second handler */
	printf("thread 1 push complete\n");
	if(arg)/* 1 */
		return ((void*)1);/* return from the process, then do not call the atexit funtion */

	pthread_cleanup_pop(0);
	pthread_cleanup_pop(0);
	return ((void*)0);
}

void *thr_fn2(void *arg)
{
	printf("thread 2 start\n");
	pthread_cleanup_push(cleanup, "thread 2 first handler");
	pthread_cleanup_push(cleanup, "thread 2 second handler");
	printf("thread 2 push complete\n");
	if(arg){/* 1 */
		pthread_exit((void*)2);/* exit from the pthread */
	}

	pthread_cleanup_pop(0);
	pthread_cleanup_pop(0);

	pthread_exit((void*)2);
}

int main(void)
{
	int err;
	pthread_t tid1, tid2;
	void *tret;

	/* create a new pthread, arg is 1 */
	err = pthread_create(&tid1, NULL, thr_fn1, (void*)1);
	if(err != 0){/* error? */
		perror("pthread_create");
		exit(EXIT_FAILURE);
	}

	/* create another new pthread, arg is 1 */
	err = pthread_create(&tid2, NULL, thr_fn2, (void*)1);
	if(err != 0){/* error? */
		perror("pthread_create");
		exit(EXIT_FAILURE);
	}
	/* wait the first pthread go over, and get the returned value */
	err = pthread_join(tid1, &tret);
	if(err != 0){/* error? */
		perror("pthread_join");
		exit(EXIT_FAILURE);
	}
	printf("pthread 1 exit code %d\n", (int)tret);/* print the returned value */
	
	/* wait the second pthread go over, and get the returned value */
	err = pthread_join(tid2, &tret);
	if(err != 0){/* error? */
		perror("pthread_join");
		exit(EXIT_FAILURE);
	}
	printf("pthread 2 exit code %d\n", (int)tret);/* print the returned value */

	exit(EXIT_SUCCESS);
}

