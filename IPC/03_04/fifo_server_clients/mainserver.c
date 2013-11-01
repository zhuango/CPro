#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<string.h>
#include<errno.h>

#define MAXLINE 1024
#define FIFO1 "/tmp/fifo"
int main(int argc, char *argv[])
{
	int 	readfifo, writefifo, dummyfd, fd;
	char 	*ptr, buff[MAXLINE], fifoname[MAXLINE];
	pid_t 	pid;
	ssize_t n;

	if((mkfifo(FIFO1, 0644) < 0 && (errno != EEXIST))){
		perror("mkfifo");
		exit(EXIT_FAILURE);
	}

	readfifo = Open(FIFO1, O_RDONLY, 0);
<<<<<<< HEAD
	//Open the Write for waiting the client writing
=======
>>>>>>> b377d5b6d37e1e0791c3b0af7035f3dc99c42dd4
	dummyfd = Open(FIFO1, O_WRONLY, 0);

	while((n = Readline(readfifo, buff, MAXLINE)) > 0){
		if(buff[n-1] == '\n')
			n--;
		buff[n] = '\0';
<<<<<<< HEAD
		
		/* Cut space */
=======

>>>>>>> b377d5b6d37e1e0791c3b0af7035f3dc99c42dd4
		if((ptr = strchr(buff, ' ')) == NULL){
			printf("bogus request: %s\n", buff);
			continue;
		}
<<<<<<< HEAD
		/* Set the end of name */
		*ptr++ = 0;
		/* Get the client process pid */
		pid = atol(buff);
		/* Get the client pipe */
=======

		*ptr++ = 0;
		pid = atol(buff);
>>>>>>> b377d5b6d37e1e0791c3b0af7035f3dc99c42dd4
		snprintf(fifoname, sizeof(fifoname), "/tmp/fifo.%ld", (long)pid);
		if((writefifo = open(fifoname, O_WRONLY, 0)) < 0){
			perror("writefifo open");
			exit(EXIT_FAILURE);
		}
<<<<<<< HEAD
		/* Open the requested file and read, then sent to client */
=======
>>>>>>> b377d5b6d37e1e0791c3b0af7035f3dc99c42dd4
		if((fd = open(ptr, O_RDONLY, 0)) < 0){
			snprintf(buff + n, sizeof(buff) - n, ": can't open, %s\n",
					strerror(errno));
			n = strlen(ptr);
			Write(writefifo, ptr, n);
			Close(writefifo);
		}else{
			while((n = Read(fd, buff, MAXLINE)) > 0){
				Write(writefifo, buff, n);
			}
			Close(fd);
			Close(writefifo);
		}
	}
	exit(EXIT_SUCCESS);
}
