#include<stdio.h>
#include<stdlib.h>
#include<signal.h>
#include<pthread.h>

struct timefun{
	int timeout;
	void (*fun)(int);
};

void *pth_alarm1(void *arg)
{
	struct timefun *tf;
	tf = (struct timefun*)arg;

	if(signal(SIGALRM, tf->fun) < 0){
		perror("signal");
		exit(EXIT_FAILURE);
	}

	alarm(tf->timeout);
	printf("pthread 1 go to sleep\n");
	sleep(tf->timeout);
	pthread_exit((void*)0);
}

void *pth_alarm2(void *arg)
{
	struct timefun *tf;
	tf = (struct timefun*)arg;
	
	if(signal(SIGALRM, tf->fun) < 0){
		perror("signal");
		exit(EXIT_FAILURE);
	}
	alarm(tf->timeout);
	printf("pthread 2 go to sleep\n");
	sleep(tf->timeout);

	pthread_exit((void*)0);
}

void alarm_test(int signo)
{
	printf("alarm 1 !!!\n");
}

void alarm_test2(int signo)
{
	printf("alarm 2!!!\n");
}

void *count(void *arg)
{
	int i = 0;
	while(i != 10){
		sleep(1);
		printf("count %d\n",++i);
	}
	pthread_exit((void*)0);
}

int main(void)
{
	pthread_t tid1, tid2, tid3;
	struct timefun tf1, tf2;
	
	tf1.timeout = 2;
	tf2.timeout = 2;

	tf1.fun = alarm_test;
	tf2.fun = alarm_test2;

	pthread_create(&tid3, NULL, count, NULL);
	pthread_create(&tid1, NULL, pth_alarm1, &tf1);
	sleep(1);
	pthread_create(&tid2, NULL, pth_alarm2, &tf2);

	pthread_join(tid3, NULL);
	pthread_join(tid1, NULL);
	pthread_join(tid2, NULL);


	exit(EXIT_SUCCESS);
}
