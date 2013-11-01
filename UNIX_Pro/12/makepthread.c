#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>

int makepthread(void *(*fn)(void*), void *arg)
{
	int err;
	pthread_t tid;
	pthread_attr_t attr;

	err = pthread_attr_init(&attr);
	if(err != 0){
		perror("pthread_attr_init");
		exit(EXIT_FAILURE);
	}
	err = pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_DETACHED);
	if(err != 0){
		perror("pthread_attr_setdetachstate");
		exit(EXIT_FAILURE);
	}

	if(err == 0){
		err = pthread_create(&tid, &attr, fn, arg);
	}

	pthread_attr_destroy(&attr);

	return (err);
}
