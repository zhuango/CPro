#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>

void *func(void *arg)
{
	int *n;
	n = (int *)arg;
	printf("sdfsdfi%d\n", *n);
}
int main(void)
{
	pthread_t tid[4];
	int i;

	pthread_setconcurrency(5);
	for(i = 0; i < 4; i++){
		printf("+++++++++%d++++++++++\n", i);
		if(pthread_create(&tid[i], NULL, func, &i) < 0){
			perror("pthread");
			exit(EXIT_FAILURE);
		}
	}
	for(i = 0; i < 4; i++){
		pthread_join(tid[i], NULL);
		printf("pthread: %ld\n", tid);
	}
	sleep(1);
	return (0);
}
