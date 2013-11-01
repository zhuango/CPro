#include<sys/wait.h>
#include<stdio.h>
#include<stdlib.h>
#include<errno.h>
#include<unistd.h>
#include<string.h>

#define MAXLINE 1024

static void sig_int(int);

int main(void)
{
	char buf[MAXLINE];
	pid_t pid;
	int status;

	if(signal(SIGINT,sig_int) == SIG_ERR){
		perror("signal error");
		exit(EXIT_FAILURE);
	}

	printf("%% ");
	while(fgets(buf,MAXLINE,stdin) != NULL){

		if(buf[strlen(buf) - 1] = '\n')
			buf[strlen(buf) - 1] = 0;

		if((pid = fork()) < 0){
			perror("fork error");
			exit(EXIT_FAILURE);
		}else if(pid == 0){
			execlp(buf,buf,(char*)0);
			perror("couldn't execute");
			exit(127);
		}

		if((pid = waitpid(pid,&status,0)) < 0){
			perror("waitpid error");
			exit(EXIT_FAILURE);
		}
		printf("%% ");
	}

	exit(EXIT_SUCCESS);
}

void sig_int(int signal)
{
	printf("interrrupt\n");
}
