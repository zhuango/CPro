#include<fcntl.h>
#include<stdio.h>
#include<stdlib.h>
#include<errno.h>
#include<unistd.h>

char buf1[] = "abcdefghij";
char buf2[] = "ABCDEFGHIJ";

int main(void){
	int fd;

	if((fd = creat("file.hole",0755)) < 0){
		perror("creat");
		exit(EXIT_FAILURE);
	}

	if( write(fd,buf1,10) != 10){
		perror("write error");
		exit(EXIT_FAILURE);
	}

	if(lseek(fd,16384,SEEK_SET) == -1){
		perror("lseek error");
		exit(EXIT_FAILURE);
	}

	if(write(fd,buf2,10) != 10){
		perror("write buf2 error");
		exit(EXIT_FAILURE);
	}

	exit(EXIT_SUCCESS);
}

