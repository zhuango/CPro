#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>

struct rwlock{
	int count;
	pthread_rwlock_t rlock;
	pthread_rwlock_t wlock;
};

void *thr_fn1(void *arg)
{
	struct rwlock *RWlock;
	RWlock = (struct rwlock*)arg;

	pthread_rwlock_wrlock(&(RWlock->rlock));
	printf("pthread 1 get the write lock\n");
	sleep(5);
	RWlock->count++;
	printf("pthread 1 unlock write lock\n");
	pthread_rwlock_unlock(&(RWlock->rlock));

	pthread_exit((void*)0);
}

void *thr_fn2(void *arg)
{
	struct rwlock *RWlock;
	RWlock = (struct rwlock*)arg;

	pthread_rwlock_rdlock(&(RWlock->rlock));
	printf("pthread 2 get the read lock\n");
	sleep(1);
	RWlock->count++;
	printf("pthread 2 unlock read lcok\n");
	pthread_rwlock_unlock(&(RWlock->rlock));

	pthread_exit((void*)0);
}


int main(void)
{
	int err;
	pthread_t tid1, tid2;
	struct rwlock RWlock;

	RWlock.count = 0;
	if(pthread_rwlock_init(&(RWlock.rlock), NULL) < 0){
		perror("pthread_rwlock_init");
		exit(EXIT_FAILURE);
	}

	if(pthread_rwlock_init(&(RWlock.wlock), NULL) < 0){
		perror("pthread_rwlock_init");
		exit(EXIT_FAILURE);
	}

	err = pthread_create(&tid1, NULL, thr_fn1, &RWlock);
	if(err != 0){
		perror("pthread_create");
		exit(EXIT_FAILURE);
	}
	sleep(1);
	err = pthread_create(&tid2, NULL, thr_fn2, &RWlock);
	if(err != 0){
		perror("pthread_create");
		exit(EXIT_FAILURE);
	}

	if(pthread_join(tid1, NULL) < 0){
		perror("pthread_join");
		exit(EXIT_FAILURE);
	}
	if(pthread_join(tid2, NULL) < 0){
		perror("pthread_join");
		exit(EXIT_FAILURE);
	}

	exit(EXIT_SUCCESS);
}
