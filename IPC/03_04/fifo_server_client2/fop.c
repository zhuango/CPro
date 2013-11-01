#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
/* Open */
int Open(const char *filename, int type, mode_t mode)
{
	int fd;
	if((fd = open(filename, type, 0)) < 0){
		perror("open");
		exit(EXIT_FAILURE);
	}
	return (fd);
}
/* write */
int Write(int writefd, char *buff, int len)
{
	int n;
	if((n = write(writefd, buff, len)) < 0){ 
		perror("write");
		exit(EXIT_FAILURE);
	}   

	return (n);
}
/* read */
int Read(int readfd, char *buff, int maxline)
{
	int n;
	if((n = read(readfd, buff, maxline)) < 0){ 
		perror("read");
		exit(EXIT_FAILURE);
	}   

	return (n);
}
/* close */
void Close(int fd)
{
	if(close(fd) < 0){
		perror("close");
		exit(EXIT_FAILURE);
	}
}
