#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>

int main(void)
{
	int fd;
	char buf[] = "I'm a hole file";
	if( (fd = open("file.hole",O_WRONLY | O_CREAT | O_EXCL,0644)) < 0){
		perror("open");
		exit(EXIT_FAILURE);
	}

	if(write(fd,buf,15) < 0){
		perror("write");
		exit(EXIT_FAILURE);
	}
	lseek(fd,1024,SEEK_CUR);
	if(write(fd,buf,15) < 0){
		perror("write");
		exit(EXIT_FAILURE);
	}

	exit(EXIT_SUCCESS);
}
