#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<fcntl.h>
#include"fifo.h"
#include<errno.h>
#define MAXLINE 1024
void client(int , int);
void Unlink(const char*);

int main(int argc, char *argv[])
{
	int 	readfd, writefd;

	if(mkfifo(FIFO1, 0644) < 0 && (errno != EEXIST)) {
		perror("mkfifo error");
		exit(EXIT_FAILURE);
	}

	if(mkfifo(FIFO2, 0644) < 0 && (errno != EEXIST)) {
		perror("mkfifo");
		exit(EXIT_FAILURE);
	}

	writefd = open(FIFO1, O_WRONLY, 0);
	readfd = open(FIFO2, O_RDONLY, 0);

	client(readfd, writefd);

	close(readfd);
	close(writefd);

	Unlink(FIFO1);
	Unlink(FIFO2);
	exit(EXIT_SUCCESS);
}

void Unlink(const char *fifo)
{
	if(unlink(fifo) < 0){
		perror("unlink");
		exit(EXIT_FAILURE);
	}
}
