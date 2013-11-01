#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<fcntl.h>
#include"fifo.h"
#define MAXLINE 1024
void client(int , int);
void Unlink(const char*);

int main(int argc, char *argv[])
{
	int 	readfd, writefd;

	writefd = Open(FIFO1, O_WRONLY, 0);
	readfd = Open(FIFO2, O_RDONLY, 0);

	client(readfd, writefd);

	Close(readfd);
	Close(writefd);

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
