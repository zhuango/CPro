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

<<<<<<< HEAD
	readfd = open(FIFO1, O_RDONLY, 0);
	writefd = open(FIFO2, O_WRONLY, 0);
=======
	readfd = Open(FIFO1, O_RDONLY);
	writefd = Open(FIFO2, O_WRONLY);
>>>>>>> b377d5b6d37e1e0791c3b0af7035f3dc99c42dd4

	server(readfd, writefd);

	exit(EXIT_SUCCESS);
}
