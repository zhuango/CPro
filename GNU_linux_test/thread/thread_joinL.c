#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>

void *thread(void *str){
	int i;
	for(i=0;i<3;i++){
		sleep(2);
		printf("this is thread :%d\n",i);
	}

	return NULL;
}

int main(void){
	pthread_t cthread;
	int i;

	int ret = pthread_create(&cthread,NULL,thread,NULL);

	printf("this thread is created ,the main wait for the thread\n");

	pthread_join(cthread,NULL);

	printf("thread was exit\n");

	for(i=0;i<3;i++){
		sleep(1);
		printf("this is main : %d\n",i);
	}

	return 0;
}
