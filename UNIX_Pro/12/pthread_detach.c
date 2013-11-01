#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include<pthread.h>

void *detach_thr(void *arg)
{
	printf("This is a pthread use to print a string, Enter '\\n' end this process!\n");
//	pthread_exit((void*)0);
}

int Pthread_create(void *(*func)(void *), void *arg)
{
	int err;
	pthread_t	tid;/* Use to create a new pthread */
	pthread_attr_t	*attr;/* Use to change the pthread state */
	
	attr = malloc(sizeof(pthread_attr_t ));

	err = pthread_attr_init(attr);/*init a pthread_attr_t struct*/
	if(err != 0){
		return (err);
	}

	err = pthread_attr_setdetachstate(attr, PTHREAD_CREATE_DETACHED);/* use the value attr to set a state named PTHREAD_CREATE_DETACHED */
	if(err == 0){
		err = pthread_create(&tid, attr, func, arg);/* no error, then create a new pthread */
	}
	pthread_attr_destroy(attr);/* destory the state value attr */
	return (err);
}

int main(void)
{
	int err;
	pthread_t tid;

	err = Pthread_create(detach_thr, (void*)0);/* create a new pthread */
	if(err != 0){
		perror("Phtread_create");
		exit(EXIT_FAILURE);
	}
	getchar();
	exit(EXIT_SUCCESS);
}
