#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<sys/types.h>
#include<errno.h>

#define FIFO "/tmp/fifo"
int main(void)
{
	int fd;
	int n;
	struct stat statbuf;
	if((mkfifo(FIFO, 0644) < 0) && (errno != EEXIST)){
		perror("mkfifo");
		exit(EXIT_FAILURE);
	}

	if((fd = open(FIFO, O_WRONLY, 0)) < 0){
		perror("open");
		exit(EXIT_FAILURE);
	}

	if((n = write(fd, "Fuck", 4)) < 0){
		perror("write");
		exit(EXIT_FAILURE);
	}
	if(fstat(fd, &statbuf) < 0){
		perror("fstat");
		exit(EXIT_FAILURE);
	}
	printf("%s length: %d\n", FIFO, statbuf.st_size);

	exit(EXIT_FAILURE);
}
