#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main(void)
{
	pid_t pid;

	if((pid = fork()) < 0) {
		perror("fork error");
		exit(EXIT_FAILURE);
	}else if(pid == 0) {
		if(execlp("ls","-l",(char *)0) < 0) {
			perror("execlp error");
			exit(EXIT_FAILURE);
		}
	}

	if(waitpid(pid,NULL) < 0) {
		perror("waitpid error");
		exit(EXIT_FAILURE);
	}

	if((pid = fork()) < 0) {
		perror("fork error");
		exit(EXIT_FAILURE);
	}else if(pid == 0) {
		if(execlp("ls","-l",(char *)0) < 0) {
			perror("execlp error2");
			exit(EXIT_FAILURE);
		}
	}

	exit(EXIT_SUCCESS);
}
