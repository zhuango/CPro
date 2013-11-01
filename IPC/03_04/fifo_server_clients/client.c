#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<errno.h>
#include<string.h>
#include<unistd.h>

#define MAXLINE 1024
#define FIFO1 "/tmp/fifo"
void Fgets(char *, int, FILE*);
void Unlink(const char*);
int main(int argc, char *argv[])
{
	int 	readfifo, writefifo;
	size_t 	len;
	ssize_t	n;
	char *ptr, fifoname[MAXLINE], buff[MAXLINE];
	pid_t pid;
<<<<<<< HEAD
	
	/* Get the child pid */
	pid = getpid();
	/* Get a fifo name */
	snprintf(fifoname, sizeof(fifoname), "/tmp/fifo.%ld", (long)pid);
	/* Create a fifo named with pid number */
=======

	pid = getpid();
	snprintf(fifoname, sizeof(fifoname), "/tmp/fifo.%ld", (long)pid);
>>>>>>> b377d5b6d37e1e0791c3b0af7035f3dc99c42dd4
	if((mkfifo(fifoname, 0644) < 0) && (errno != EEXIST)){
		perror("mkfifo");
		exit(EXIT_FAILURE);
	}
<<<<<<< HEAD
	/* Put pid into string with ' ' to sepreate from filename */
	snprintf(buff, sizeof(buff), "%ld ", (long)pid);
	len = strlen(buff);
	ptr = buff + len;
	/* Get filename from stdin begin with "PID[space]" */
	Fgets(ptr, MAXLINE - len, stdin);
	len = strlen(buff);

	/* Sent "PID[space]FILENAME]" to server */
	writefifo = Open(FIFO1, O_WRONLY, 0);
	Write(writefifo, buff, len);
	/* Recvive data */
=======
	snprintf(buff, sizeof(buff), "%ld ", (long)pid);
	len = strlen(buff);
	ptr = buff + len;
	Fgets(ptr, MAXLINE - len, stdin);
	len = strlen(buff);

	writefifo = Open(FIFO1, O_WRONLY, 0);
	Write(writefifo, buff, len);
>>>>>>> b377d5b6d37e1e0791c3b0af7035f3dc99c42dd4
	readfifo = Open(fifoname, O_RDONLY, 0);

	while((n = Read(readfifo, buff, MAXLINE)) > 0){
		Write(STDOUT_FILENO, buff, n);
	}
<<<<<<< HEAD
	/* Close and unlink */
=======
>>>>>>> b377d5b6d37e1e0791c3b0af7035f3dc99c42dd4
	Close(readfifo);
	Unlink(fifoname);
	exit(EXIT_SUCCESS);
}

void Unlink(const char *filename)
{
	if(unlink(filename) < 0){
		perror("unlink");
		exit(EXIT_FAILURE);
	}
}
void Fgets(char *ptr, int maxline, FILE* in)
{
	if(fgets(ptr, maxline, in) == NULL){
		printf("fgets error\n");
		exit(EXIT_FAILURE);
	}
}
