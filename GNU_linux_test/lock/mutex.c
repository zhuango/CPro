#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>
#include<errno.h>

#define INDEX 10000000

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
long int ticks;
time_t end_time;

void idx_th(void *arg);
void mon_th(void *arg);

int main(int argc, char **argv)
{
	pthread_t idx_th_id;
	pthread_t mon_th_id;
	int ret;

	end_time = time(NULL) + 30;

	ret = pthread_create(&idx_th_id,NULL,(void*)idx_th,NULL);
	if(ret != 0){
		perror("pthread_create: idx_th");
		exit(EXIT_FAILURE);
	}

	ret = pthread_create(&mon_th_id,NULL,(void*)mon_th,NULL);
	if(ret != 0){
		perror("pthread_create: mon_th_id");
		exit(EXIT_FAILURE);
	}

	pthread_join(idx_th_id,NULL);
	pthread_join(mon_th_id,NULL);

	exit(EXIT_SUCCESS);
}

void idx_th(void *arg)
{
	long l;

	while(time(NULL) < end_time){

		if(pthread_mutex_lock(&mutex) != 0){
			perror("pthread_metex_lock");
			exit(EXIT_FAILURE);
		}

		for(l=01;l < INDEX; ++l)
			++ticks;

		if(pthread_mutex_unlock(&mutex) != 0){
			perror("pthread_mutex_unlock");
			exit(EXIT_FAILURE);
		}
		sleep(1);
	}
}

void mon_th(void *arg)
{
	int nolock = 0;
	int ret;

	while(time(NULL) < end_time){
		sleep(2);

		ret = pthread_mutex_trylock(&mutex);
		if(ret != EBUSY){
			if(ret != 0){
				perror("pthread_mutex_trylock");
				exit(EXIT_FAILURE);
			}
			printf("mon_th: got lock at %ld ticks\n",ticks);
			if(pthread_mutex_unlock(&mutex) != 0){
				perror("pthread_mutex_unlock");
				exit(EXIT_FAILURE);
			}
		}else{
			nolock++;
		}
	}
	printf("mon_th missed lock %d times\n",nolock);
}

