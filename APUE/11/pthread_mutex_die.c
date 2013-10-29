#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>

int mutex_number = 0;

void *thr_fn1(void *arg)
{
	pthread_mutex_t *lock;
	lock = (pthread_mutex_t*)arg;

	pthread_mutex_lock(lock);
	printf("I'm dying\n");
	pthread_mutex_lock(lock);
	mutex_number ++;
	printf("pthread 1 unlock the lock\n");
	sleep(1);
	pthread_mutex_unlock(lock);

	pthread_exit((void*)0);

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


	err = pthread_join(tid1, NULL);
	if(err != 0){
		perror("pthread_join");
		exit(EXIT_FAILURE);
	}

	pthread_mutex_destroy(&lock);
	exit(EXIT_SUCCESS);
}
