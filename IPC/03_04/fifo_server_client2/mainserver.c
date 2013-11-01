#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<errno.h>
#include"fifo.h"
#define MAXLINE 1024

int main(int argc, char *argv[])
{
	int 	readfd, writefd;
	if((mkfifo(FIFO1, 0644)) < 0 && (errno != EEXIST)){
		perror("mkfifo");
		exit(EXIT_FAILURE);
	}
	if((mkfifo(FIFO2, 0644)) < 0 && (errno != EEXIST)){
		unlink(FIFO1);
		perror("mkfifo");
		exit(EXIT_FAILURE);
	}

	readfd = open(FIFO1, O_RDONLY, 0);
	writefd = open(FIFO2, O_WRONLY, 0);

	server(readfd, writefd);

	exit(EXIT_SUCCESS);
}
