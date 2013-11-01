#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main(int argc, char *argv[])
{
	int 	fd[2], n;
	char 	c;
	pid_t 	childpid;

	if(pipe(fd) < 0){
		perror("pipe");
		exit(EXIT_FAILURE);
	}
	if((childpid = fork()) < 0){
		perror("fork");
		exit(EXIT_FAILURE);
	}else if(childpid == 0){
		sleep(3);
		if((n = read(fd[0], &c, 1)) < 0){
			perror("read C");
			exit(EXIT_FAILURE);
		}
		printf("child read: %c\n", c);
		if(write(fd[0], "c", 1) < 0){
			perror("write C");
			exit(EXIT_FAILURE);
		}
		exit(EXIT_SUCCESS);
	}

	if(write(fd[1], "p", 1) != 1){
		perror("write P");
		exit(EXIT_FAILURE);
	}
	if((n = read(fd[1], &c, 1)) < 0){
		perror("read P");
		exit(EXIT_FAILURE);
	}
	printf("parent read %c\n", c);

	exit(EXIT_SUCCESS);
}
