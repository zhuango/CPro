#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<errno.h>
#include<string.h>

#define MAXLINE 1024

int Read(int, char*, int);
int Write(int, char*, int);
void Close(int);

void server(int readfd, int writefd)
{
	int 	fd;
	ssize_t	n;
	char 	buff[MAXLINE];

	if((n = Read(readfd, buff, MAXLINE)) == 0){/* Get file name */
		perror("end_of_file when read pathname");
		exit(EXIT_FAILURE);
	}
	buff[n] = '\0';/* Eat the '\n' and set the end*/

	if((fd = open(buff, O_RDONLY)) < 0){
		snprintf(buff + n, sizeof(buff) - n, ": can't open: %s\n",
				strerror(errno));/* filename: can't open: <error> */
		n = strlen(buff);
		Write(writefd, buff, n);/* tell client(parent) */
	}else{
		while((n = Read(fd, buff, MAXLINE)) > 0){/* Read file */
			Write(writefd, buff, n);/* send to client(parent) */
		}
		Close(fd);
	}
}

