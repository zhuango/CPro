#include<stdio.h>
#include<stdlib.h>
#include<semaphore.h>
#include<fcntl.h>
#include<pthread.h>

#define NBUFF 	10/* number of product */
#define SEM_MUTEX "mutex"	/* for product one or consume get one */
#define SEM_NEMPTY "nempty"	/* number of empty positions */
#define SEM_NSTORES "nstored"/* number if stored positions */

int nitems;/* number of product you want to produce */
struct{
	int buff[NBUFF];/* product positions */
	sem_t *mutex, *nempty, *nstored;
}share;

char *Unlink(char *);/* delete the semaphore */
sem_t *Sem_open(const char *, int, mode_t, int);
void *produce(void *), *consume(void *);/* produce and consume */

int main(int argc, char **argv)
{
	pthread_t tid_produce, tid_consume;
	if(argc != 2){
		printf("Usage: %s <nitems>\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	nitems = atoi(argv[1]);
	/* get semaphores */
	share.mutex = Sem_open(Unlink(SEM_MUTEX), 
			O_RDWR | O_CREAT, 0644, 1);
	share.nempty = Sem_open(Unlink(SEM_NEMPTY),
			O_RDWR | O_CREAT, 0644, NBUFF);
	share.nstored = Sem_open(Unlink(SEM_NSTORES),
			O_RDWR | O_CREAT, 0644, 0);

	/* produce and consume process can run at same time */
	if(pthread_setconcurrency(2) < 0){
		perror("pthread_setconcurrency");
		exit(EXIT_FAILURE);
	}

	/* create two pthread to run produce and consume */
	if(pthread_create(&tid_produce, NULL, produce, NULL) < 0){
		perror("pthread_create");
		exit(EXIT_FAILURE);
	}
	if(pthread_create(&tid_consume, NULL, consume, NULL) < 0){
		perror("pthread_create");
		exit(EXIT_FAILURE);
	}
	if(pthread_join(tid_produce, NULL) < 0){
		perror("pthread_join");
		exit(EXIT_FAILURE);
	}
	if(pthread_join(tid_consume, NULL) < 0){
		perror("pthread_join");
		exit(EXIT_FAILURE);
	}

	/* delete the semaphore */
	if(sem_unlink(SEM_MUTEX) < 0){
		perror("sem_unlink");
		exit(EXIT_FAILURE);
	}
	if(sem_unlink(SEM_NEMPTY) < 0){
		perror("sem_unlink");
		exit(EXIT_FAILURE);
	}
	if(sem_unlink(SEM_NSTORES) < 0){
		perror("sem_unlink nstores");
		exit(EXIT_FAILURE);
	}

	exit(EXIT_FAILURE);
}

char *Unlink(char *semaphore)
{
	char *sem;
	sem = semaphore;

	sem_unlink(semaphore);
	return sem;
}

sem_t *Sem_open(const char *semaphore, int flag, mode_t mode, int n_sem)
{
	sem_t *sem;
	if((sem = sem_open(semaphore, flag, mode, n_sem)) == SEM_FAILED){
		perror("sem_open");
		exit(EXIT_FAILURE);
	}
	return sem;
}
void *produce(void *arg)
{
	int i;
	for(i = 0; i < nitems; i++){
		sem_wait(share.nempty);/* product one and empty positions reduced */
		sem_wait(share.mutex);/* lock the buff array */
		share.buff[i % NBUFF] = i;
		sem_post(share.mutex);/* unlock buff array */
		sem_post(share.nstored);/* produce one and stored positions increase */
	}

	return NULL;
}

void *consume(void *arg)
{
	int i;
	for(i = 0; i < nitems; i++){
		sem_wait(share.nstored);/* empty positon ++ */
		sem_wait(share.mutex);
		if(share.buff[i % NBUFF] != i){
			printf("err: buff[%d] = %d\n", i % NBUFF, share.buff[i % NBUFF]);
		}
		sem_post(share.mutex);
		sem_post(share.nempty);/* stored position -- */
	}
	return NULL;
}
