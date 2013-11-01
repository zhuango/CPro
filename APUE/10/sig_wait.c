#include<stdio.h>
#include<stdlib.h>
#include<sys/wait.h>
#include<signal.h>
#include<unistd.h>

static void sig_cld(int);

int main(void)
{
	pid_t pid;

	if(signal(SIGCHLD, sig_cld) == SIG_ERR){
		perror("signal");
		exit(EXIT_FAILURE);
	}
	if((pid = fork()) < 0){
		perror("fork");
		exit(EXIT_FAILURE);
	}else if(pid == 0){
		sleep(2);
		_exit(0);
	}

	pause();
	exit(0);
}

static void sig_cld(int signo)
{
	pid_t pid;
	int status;

	printf("SIGCLD received\n");

	if(signal(SIGCHLD, sig_cld) == SIG_ERR){
		printf("signal");
		exit(EXIT_FAILURE);
	}
	if((pid = wait(&status)) < 0){
		perror("wait");
		exit(EXIT_FAILURE);
	}

	printf("pid = %d\n", pid);
}
