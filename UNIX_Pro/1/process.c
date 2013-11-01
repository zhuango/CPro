#include<stdio.h>
#include<stdlib.h>
#include<sys/wait.h>//for the wait
#include<string.h>
#include<unistd.h>

#define MAXLINE 1024
void err_quit(char *);

int main(void)
{
	char buf[MAXLINE];
	pid_t pid;
	int status;

	printf("%% ");//print ......

	while(fgets(buf,MAXLINE,stdin) != NULL){
		if(buf[strlen(buf) - 1] == '\n'){
			buf[strlen(buf) - 1] = 0;
		}
		if((pid = fork()) < 0){
			err_quit("foek error");
		}else if(pid == 0){
			execlp(buf,buf,(char*)0);
			err_quit("couldn't execute");
			exit(127);
		}

		if((pid = waitpid(pid,&status,0)) < 0){
			err_quit("waitpid error");
		}

		printf("%% ");
	}
	
	exit(EXIT_SUCCESS);
}

void err_quit(char *msg)
{
	perror(msg);
	exit(EXIT_FAILURE);
}
