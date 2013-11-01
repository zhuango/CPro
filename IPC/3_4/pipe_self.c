#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

#define MAXLINE 1024
int main(void)
{
	int 	fd[2];
	pid_t	pid;
	char line[MAXLINE];

	if(pipe(fd) < 0){
		perror("pipe");
		exit(EXIT_FAILURE);
	}
	if(write(fd[1], "Fuck You!", 9) < 0){
		perror("write");
		exit(EXIT_FAILURE);
	}
	if(read(fd[0], line, MAXLINE) < 0){
		perror("read");
		exit(EXIT_FAILURE);
	}
	printf("read: %s\n", line);

	exit(EXIT_SUCCESS);
}
