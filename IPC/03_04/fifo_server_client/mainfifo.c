#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<errno.h>
#include<sys/types.h>
#include<sys/stat.h>
#define FIFO1 "/tmp/fifo.1"
#define FIFO2 "/tmp/fifo.2"

void client(int, int), server(int, int);

int main(int argc, char *argv[])
{
	int readfd, writefd;
	pid_t	childpid;

	if((mkfifo(FIFO1, 0644) < 0) && (errno != EEXIST)){
		perror("mkfifo");
		exit(EXIT_FAILURE);
	}
	if((mkfifo(FIFO2, 0644) < 0) && (errno != EEXIST)){
		unlink(FIFO1);
		perror("mkfifo2");
		exit(EXIT_FAILURE);
	}

	if((childpid = Fork()) == 0){
		readfd = Open(FIFO1, O_RDONLY, 0);
		writefd = Open(FIFO2, O_WRONLY, 0);

		server(readfd, writefd);
		exit(EXIT_SUCCESS);
	}

	writefd = Open(FIFO1, O_WRONLY, 0);
	readfd = Open(FIFO2, O_RDONLY, 0);

	client(readfd, writefd);

	Waitpid(childpid, NULL, 0);

	Close(readfd);
	Close(writefd);

	unlink(FIFO1);
	unlink(FIFO2);

	exit(EXIT_SUCCESS);
}

pid_t Fork()
{
	pid_t pid;
	if((pid = fork()) < 0){
		perror("fork");
		exit(EXIT_FAILURE);
	}
	return (pid);
}

pid_t Waitpid(pid_t pid, int *re, int n)
{
	if(waitpid(pid, re, n) < 0){
		perror("waitpid");
		exit(EXIT_FAILURE);
	}
}
