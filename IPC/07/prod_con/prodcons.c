#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#define MAXNITEMS	1000000
#define MAXNPTHREADS	100

int nitems;

struct {
	pthread_mutex_t mutex;
	int		buff[MAXNITEMS];
	int		nput;
	int		nval;
}shared = {
	PTHREAD_MUTEX_INITIALIZER
};

void *produce(void*), *consume(void*);

int  main(int argc, char*argv[])
{
	int i, npthreads, count[MAXNPTHREADS];
	pthread_t tid_produce[MAXNPTHREADS], tid_consume;
	if(argc != 3){
		printf("Usage: %s <Items> <npthread>\n", argv[0]);
		exit(EXIT_FAILURE);
	}
	nitems = min(atoi(argv[1]), MAXNITEMS);/* numbers of products */
	npthreads = min(atoi(argv[2]), MAXNPTHREADS);/* numbers of pthread */


	for(i = 0; i < npthreads; i++){/* create some pthreads to prodcut*/
		count[i] = 0;
		pthread_create(&tid_produce[i], NULL, produce, &count[i]);
	}
	for(i = 0; i < npthreads; i++){/* wait for pthreads */
		if(pthread_join(tid_produce[i], NULL) < 0){
			perror("pthread_join");
			exit(EXIT_FAILURE);
		}
		printf("count[%d] = %d\n", i, count[i]);
	}

	/* create a consume pthread */
	pthread_create(&tid_consume, NULL, consume, NULL);
	pthread_join(tid_consume, NULL);
	exit(EXIT_SUCCESS);
}

void *produce(void *arg)
{
	for(;;){
		Pthread_mutex_lock(&shared.mutex);/* locked */
		if(shared.nput >= nitems){
			Pthread_mutex_unlock(&shared.mutex);/* end of product? and exit pthread */
			pthread_exit((void*)0);
		}

		shared.buff[shared.nput] = shared.nval;
		shared.nput++;
		shared.nval++;
		Pthread_mutex_unlock(&shared.mutex);
		*((int*)arg) += 1;/* counting */
	}
}
void *consume(void *arg)
{
	int 	i;
	for(i = 0; i < nitems; i++){
		if(shared.buff[i] != i){/* not equal , that means lock is not go well */
			printf("*buff[%d] = %d\n", i, shared.buff[i]);
		}
	}
	pthread_exit((void*)0);
}

int min(int a, int b)
{
	if(a > b) return b;
	else return a;
}
