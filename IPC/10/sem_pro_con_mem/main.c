#include<stdio.h>
#include<stdlib.h>
#include<semaphore.h>
#include<fcntl.h>
#include<pthread.h>

#define NBUFF 10
int nitems;
struct {
	unsigned char buff[NBUFF];
	sem_t *mutex, *nempty, *nstored;
}share;

void *produce(void *), *consume(void *);
int Sem_init(sem_t *sem, int share, unsigned int value);
int Sem_destroy(sem_t *sem);
int Pthread_create(pthread_t *restrict, const pthread_attr_t *restrict, void *(*)(void *), void *);
int Pthread_join(pthread_t, void **);

int main(int argc, char *argv[])
{
	pthread_t tid_produce, tid_consume;
	if(argc != 2){
		printf("Usage: %s <nitems>\n", argv[0]);
		exit(EXIT_FAILURE);
	}
	nitems = atoi(argv[1]);
	printf("nitems = %d\n", nitems);
	share.mutex		= malloc(sizeof(sem_t));
	share.nempty	= malloc(sizeof(sem_t));
	share.nstored	= malloc(sizeof(sem_t));
	Sem_init(share.mutex, 0, 1);
	Sem_init(share.nempty, 0, NBUFF);
	Sem_init(share.nstored, 0, 0);

//	pthread_setconcurrency(2);
	Pthread_create(&tid_produce, NULL, produce, NULL);
	Pthread_create(&tid_consume, NULL, consume, NULL);

	Pthread_join(tid_produce, NULL);
	Pthread_join(tid_consume, NULL);

	Sem_destroy(share.mutex);
	Sem_destroy(share.nempty);
	Sem_destroy(share.nstored);

	exit(EXIT_SUCCESS);
}

void *produce (void *arg)
{
	int i;
	for(i = 0; i < nitems; i ++ ){
		sem_wait(share.nempty);
		sem_wait(share.mutex);
		share.buff[i % NBUFF] = i;
		sem_post(share.mutex);
		sem_post(share.nstored);
	}

	return 0;
}

void *consume(void *arg)
{
	int i;
	for(i = 0; i < nitems; i++){
		sem_wait(share.nstored);
		sem_wait(share.mutex);
		if(share.buff[i % NBUFF] != i){
			printf("error : share.buff[%d] = %d, right answer is : %d\n", i % NBUFF, share.buff[i], i);
		}
		sem_post(share.mutex);
		sem_post(share.nempty);
	}

	return 0;
}

int Sem_init(sem_t *sem, int share, unsigned int value)
{
	int ret;
	if((ret = sem_init(sem, share, value)) == -1){
		perror("sem_init");
		exit(EXIT_FAILURE);
	}

	return ret;
}

int Sem_destroy(sem_t *sem)
{
	int ret;
	if((ret = sem_destroy(sem)) < 0){
		perror("sem_destroy");
		exit(EXIT_FAILURE);
	}
	return ret;
}

int Pthread_create(pthread_t *restrict tid, const pthread_attr_t *restrict attr,
		void*(*fun)(void *), void *restrict arg)
{
	int ret;
	if((ret = pthread_create(tid, attr, fun, arg)) < 0){
		perror("pthread_create");
		exit(EXIT_FAILURE);
	}

	return ret;
}

int Pthread_join(pthread_t tid, void **arg)
{
	int ret;
	if((ret = pthread_join(tid, arg)) < 0){
		perror("pthread_join");
		exit(EXIT_FAILURE);
	}

	return ret;
}
