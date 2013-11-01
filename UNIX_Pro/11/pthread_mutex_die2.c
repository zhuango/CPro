#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>

struct lock_value{
	int count;
	pthread_mutex_t lock1;
	pthread_mutex_t lock2;
};

void *thr_fn1(void *arg)
{
	struct lock_value *lock;
	lock = (struct lock_value*)arg;

	pthread_mutex_lock(&(lock->lock1));
	printf("pthread 1 get the lock1\n");
	sleep(2);
	lock->count ++;
	printf("pthread 1 want the lock2...\n");
	pthread_mutex_lock(&(lock->lock2));
	printf("pthread 1 get the lock2\n");
	pthread_mutex_unlock(&(lock->lock2));
	pthread_mutex_unlock(&(lock->lock1));
	printf("pthread 1 Done\n");

	pthread_exit((void*)0);
}

void *thr_fn2(void *arg)
{
	struct lock_value *lock;
	lock = (struct lock_value*)arg;

	pthread_mutex_lock(&(lock->lock2));
	printf("pthread 2 get the lock2\n");
	lock->count++;
	printf("pthread 2 want the lock1...\n");
	pthread_mutex_lock(&(lock->lock1));
	printf("pthread 2 get the lock1\n");
	pthread_mutex_unlock(&(lock->lock1));
	pthread_mutex_unlock(&(lock->lock2));

	pthread_exit((void*)0);
}

int main(void)
{
	int err;
	pthread_t tid1, tid2;
	struct lock_value lv;
	lv.count = 0;

	if(pthread_mutex_init(&(lv.lock1), NULL) < 0){
		perror("pthread_mutex_init ");
		exit(EXIT_FAILURE);
	}
	if(pthread_mutex_init(&(lv.lock2), NULL) < 0){
		perror("Pthread_mutex_init");
		exit(EXIT_FAILURE);
	}

	err = pthread_create(&tid1, NULL, thr_fn1, &lv);
	if(err != 0){
		perror("pthread_create");
		exit(EXIT_FAILURE);
	}
	sleep(1);
	err = pthread_create(&tid2, NULL, thr_fn2, &lv);
	if(err != 0){
		perror("pthread_create 2");
		exit(EXIT_FAILURE);
	}

	if(pthread_join(tid1, NULL) < 0){
		perror("pthread_join");
		exit(EXIT_FAILURE);
	}
	if(pthread_join(tid2, NULL) < 0){
		perror("ptrhead_join2");
		exit(EXIT_FAILURE);
	}

	//pthread_mutex_destroy(&(lv.lock1));
	//pthread_mutex_destroy(&(lv.lock2));

	exit(EXIT_FAILURE);
}
