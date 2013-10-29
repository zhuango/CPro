#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>

/* pthread 1 return 0*/
void *thr_fn1(void *arg)
{
	printf("thread 1 returning \n");
	return ((void*)0);
}

/* pthread 2 return 2 */
void *thr_fn2(void *arg)
{
	printf("thread 2 returning \n");
	return ((void*)2);
}

int main(void)
{
	int err;/* check the error */
	pthread_t tid1, tid2;/* use to create two pthreads */
	void *tret;/* get the pthread returned value */

	err = pthread_create(&tid1, NULL, thr_fn1, NULL);/* create new pthread */
	if(err != 0){/* error? */
		perror("pthread_craete");
		exit(EXIT_FAILURE);
	}

	err = pthread_create(&tid2, NULL, thr_fn2, NULL);/* create anpther pthread */
	if(err != 0){/* error? */
		perror("pthread_create 2 ");
		exit(EXIT_FAILURE);
	}


	err = pthread_join(tid1, &tret);/* wait the pthread go over */
	if(err != 0){/* error? */
		perror("pthread_join");
		exit(EXIT_FAILURE);
	}
	printf("thread 1 return value: %d\n", (int)tret);/* print the thread 1 returned value */

	err = pthread_join(tid2, &tret);/* wait the pthread go over */
	if(err != 0){/* error? */
		perror("pthread_join");
		exit(EXIT_FAILURE);
	}
	printf("thread 2 return value: %d\n", (int)tret);/* get the pthread 2 returned value */


	exit(EXIT_SUCCESS);/* exit */
}

