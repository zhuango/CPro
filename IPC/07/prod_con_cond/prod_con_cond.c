#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#define MAXNITEMS 1000000
#define MAXNPTHREADS 100

int nitems;
int buff[MAXNITEMS];

/* produce something */
struct {
	pthread_mutex_t mutex;
	int npro;
	int nval;
}put = {
	PTHREAD_MUTEX_INITIALIZER
};
/* cond struct */
struct {
	pthread_mutex_t mutex;
	pthread_cond_t cond;
	int nready;
}nready = {
	PTHREAD_MUTEX_INITIALIZER,
	PTHREAD_COND_INITIALIZER
};

void *produce(void*), *consume(void*);
int main(int argc, char *argv[])
{
	int i, npthreads, count[MAXNPTHREADS], total = 0;
	pthread_t tid_produce[MAXNPTHREADS], tid_consume;
	if(argc != 3){
		printf("Usage: %s <Items> <npthread>\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	nitems = min(atoi(argv[1]), MAXNITEMS);/* get the number of prodece */
	npthreads = min(atoi(argv[2]), MAXNPTHREADS);/* number of pthreads */

	/* create pthreads for producer*/
	for(i = 0; i < npthreads; i++){
		count[i] = 0;
		Pthread_create(&tid_produce[i], NULL, produce, &count[i]);
	}
	/* wait for pthreads */
	for(i = 0; i < npthreads; i++){
		if(pthread_join(tid_produce[i], NULL) < 0){
			perror("pthread_join");
			exit(EXIT_FAILURE);
		}
		printf("count[%d] = %d\n", i, count[i]);
	}
	/* create pthread for consume */
	pthread_create(&tid_consume, NULL, consume, NULL);
	pthread_join(tid_consume, NULL);

	for(i = 0; i < npthreads; i++){
		total += count[i];
	}
	printf("total : %d\n", total);
	
	exit(EXIT_FAILURE);
}

void *produce(void *arg)
{
	for(;;){
		pthread_mutex_lock(&put.mutex);/* locked */
		if(put.npro >= nitems){/* done */
			pthread_mutex_unlock(&put.mutex);
			pthread_exit((void*)0) ;
		}
		buff[put.npro] = put.nval;
		put.npro++;
		put.nval++;
		Pthread_mutex_unlock(&put.mutex);/* unlocked */

		Pthread_mutex_lock(&nready.mutex);/* lock for cond */
		if(nready.nready == 0)
			Pthread_cond_signal(&nready.cond);/* send signal */
		nready.nready ++;
		Pthread_mutex_unlock(&nready.mutex);

		*((int*)arg) += 1;
	}
}

void *consume(void *arg)
{
	int i;
	for(i = 0; i < nitems; i++){
		Pthread_mutex_lock(&nready.mutex);
		while(nready.nready == 0)
			Pthread_cond_wait(&nready.cond, &nready.mutex);/* wait for producer */
		nready.nready--;
		Pthread_mutex_unlock(&nready.mutex);

		if(buff[i] != i)
			printf("buff[%d] = %d\n", i, buff[i]);
	}
	return (NULL);
}
