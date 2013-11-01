#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>

#define MAXLINE 1024
void client(int readfd, int writefd)
{
	char buff[MAXLINE];
	int len;
	ssize_t n;

	printf("Please input a filename :\n");
	if(fgets(buff, MAXLINE, stdin) == NULL){
		perror("fgets");
		exit(EXIT_FAILURE);
	}
	len = strlen(buff);
	if(buff[len - 1] == '\n')
		len --;

	if(write(writefd, buff, len) < 0){
		perror("write");
		exit(EXIT_FAILURE);
	}

	while((n = read(readfd, buff, MAXLINE)) > 0){
		write(STDOUT_FILENO, buff, n);
	}

	exit(EXIT_FAILURE);
}
