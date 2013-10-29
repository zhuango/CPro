#include<pthread.h>
#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>

void *print(){
	printf("youxi\n");
	return (void*)0;
}

int main(void){
	pthread_t tidp;

	int error;

	error = pthread_create(&tidp,NULL,print,NULL);

	if(error){
		printf("pthread is not created...\n");
		return -1;
	}

	sleep(1);
	printf("pthread is created ...\n");
	return 0;
}
