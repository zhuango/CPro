#include<stdio.h>
#include<stdlib.h>
#include<signal.h>
#include<pwd.h>

static void my_alarm(int signo);

int main(void)
{
	struct passwd *ptr;
	signal(SIGALRM, my_alarm);
	alarm(1);

	for( ; ; ){
		if((ptr = getpwnam("Og")) == NULL){
			perror("getpwnam");
			exit(EXIT_FAILURE);
		}
		if(strcmp(ptr->pw_name, "Og") != 0){
			printf("return value corrupted!, pw_name = %s\n",ptr->pw_name);

		}
	}
}

static void my_alarm(int signo)
{
	struct passwd *rootptr;

	printf("in signal handler\n");

	if((rootptr = getpwnam("Og")) == NULL){
		perror("getownam");
		exit(EXIT_FAILURE);
	}

	alarm(1);
}
