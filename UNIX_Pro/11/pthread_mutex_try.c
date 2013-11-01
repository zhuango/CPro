#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<errno.h>

int mutex_number = 0;

void *thr_fn1(void *arg)
{
	pthread_mutex_t *lock;
	lock = (pthread_mutex_t*)arg;

	pthread_mutex_lock(lock);
	printf("pthread 1 get the lock\n");
	mutex_number ++;
	sleep(10);
	printf("pthread 1 unlock the lock\n");
	pthread_mutex_unlock(lock);

	pthread_exit((void*)0);

}

void *thr_fn2(void *arg)
{
	pthread_mutex_t *lock;
	lock = (pthread_mutex_t *)arg;

	while(pthread_mutex_trylock(lock) == EBUSY){
		printf("pthread 2 doesn't get the lock\n");
		sleep(1);
	}
	printf("pthread 2 get the lock\n");
	mutex_number ++;
	pthread_mutex_unlock(lock);
}

int main(void)
{
	pthread_mutex_t lock;
	int err;
	pthread_t tid1, tid2;
	if(pthread_mutex_init(&lock, NULL) < 0){
		perror("pthread_mutex_init");
		exit(EXIT_FAILURE);
	}

	err = pthread_create(&tid1, NULL, thr_fn1, &lock);
	if(err != 0){
		perror("pthread_create");
		exit(EXIT_FAILURE);
	}

	sleep(1);

	err = pthread_create(&tid2, NULL, thr_fn2, &lock);
	if(err != 0){
		perror("pthread_create");
		exit(EXIT_FAILURE);
	}

	err = pthread_join(tid1, NULL);
	if(err != 0){
		perror("pthread_join");
		exit(EXIT_FAILURE);
	}

	err = pthread_join(tid2, NULL);
	if(err != 0){
		perror("pthreadjoin2");
		exit(EXIT_FAILURE);
	}

	pthread_mutex_destroy(&lock);
	exit(EXIT_SUCCESS);
}
