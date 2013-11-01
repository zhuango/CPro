#include<stdio.h>
#include<pthread.h>
#include<unistd.h>

void *clean(void *arg){
	printf("clean up : %s\n",(char *) arg);
	return (void *)0;
}

void *thr_fn1(void *arg){
	printf("thread 1 start\n");

	pthread_cleanup_push( (void *) clean,"thread 1 first handler");
	pthread_cleanup_push( (void *) clean,"thread q second handler");

	printf("thread 1 push completr\n");

	if(arg){
		return ( (void *)1);
	}

	pthread_cleanup_pop(0);
	pthread_cleanup_pop(0);

	return (void *)1;
}

void *thr_fn2(void *arg){
	printf("thread 2 start\n");

	pthread_cleanup_push( (void *) clean,"thread 2 first  handler");
	pthread_cleanup_push( (void *) clean,"thread 2 second handler");

	printf("thread 2 push complete\n");

	if(arg){
		pthread_exit( (void *)2);
	}

	pthread_cleanup_pop(0);
	pthread_cleanup_pop(0);
	pthread_exit( (void *) 2);
}

int main(void){
	int err;

	pthread_t tid1,tid2;
	void *tret;

	err = pthread_create(&tid1,NULL,thr_fn1,(void *)1);
	if( err != 0){
		printf("err ..\n");
		return -1;
	}

	err = pthread_create(&tid2,NULL,thr_fn2,(void*)1);

	if(err != 0){
		printf("error...\n");
		return -1;
	}
	printf("thread 1 exit code %d\n",(int)tret);

	err = pthread_join(tid1,&tret);

	if(err != 0){
		printf("error...\n");
		return -1;
	}
	printf("thread 2 exit code %d\n",(int)tret);

	return 1;
}
