#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#define MAXLINE 1024

int main(void)
{
	int n;
	int fd[2];
	pid_t pid;
	char line[MAXLINE];
	if(pipe(fd) < 0){
		perror("pipe");
		exit(EXIT_FAILURE);
	}
	if((pid = fork()) < 0){
		perror("fork");
		exit(EXIT_FAILURE);
	}else if(pid == 0){/* child */
		close(fd[0]);
		if(write(fd[1], "Fuck You!", 9) < 0){
			perror("write");
			exit(EXIT_FAILURE);
		}
	}else{/* parent */
		close(fd[1]);
		if((n = read(fd[0], line, MAXLINE)) < 0){
			perror("read");
			exit(EXIT_FAILURE);
		}
		line[n] = 0;
		printf("received string : %s\n", line);
	}

	exit(EXIT_SUCCESS);
}
