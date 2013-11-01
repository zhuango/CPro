#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>

pthread_cond_t cond;
int count = 0;

void *thr_fn1(void *arg)
{
	pthread_mutex_t *lock;
	lock = (pthread_mutex_t*)arg;

	pthread_mutex_lock(lock);
	printf("thread 1 get the lock\n");
	sleep(5);
	printf("thread 1 wait the cond and unlock the lock...\n");
	while(count == 0){
		pthread_cond_wait(&cond, lock);
	}
	printf("pthread 1 get the cond signal and lock again\n");
	sleep(3);
	pthread_mutex_unlock(lock);
	printf("pthread 1 unlock lock\n");

	pthread_exit((void*)0);

}

void *thr_fn2(void *arg)
{
	pthread_mutex_t *lock;
	lock = (pthread_mutex_t*)arg;

	pthread_mutex_lock(lock);
	printf("pthread 2 get the lock and go to sleep...\n");
	count ++;
	sleep(3);
	pthread_mutex_unlock(lock);
	printf("ptrhead 2 unlock the lock\n");
	sleep(3);
	printf("pthread 2 send the signal\n");
	pthread_cond_signal(&cond);

	pthread_exit((void*)0);
}

int main(void)
{
	pthread_t tid1, tid2;
	pthread_mutex_t lock;
	if(pthread_mutex_init(&lock, NULL) < 0){
		perror("pthread_mutex_init");
		exit(EXIT_FAILURE);
	}
	if(pthread_cond_init(&cond, NULL) < 0){
		perror("pthread_cond_init");
		exit(EXIT_FAILURE);
	}
	if(pthread_create(&tid1, NULL, thr_fn1, &lock) < 0){
		perror("pthread_create");
		exit(EXIT_FAILURE);
	}
	sleep(1);
	if(pthread_create(&tid2, NULL, thr_fn2, &lock) < 0){
		perror("pthread_create");
		exit(EXIT_FAILURE);
	}
	
	if(pthread_join(tid1, NULL) < 0){
		perror("pthread_join1");
		exit(EXIT_FAILURE);
	}

	if(pthread_join(tid2, NULL) < 0){
		perror("pthread_join2");
		exit(EXIT_FAILURE);
	}

	exit(EXIT_SUCCESS);
}

