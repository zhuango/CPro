#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>

int main(void)
{
	int fd;
	int n,i;
	if((fd = open("C_write", O_WRONLY | O_CREAT, 0644)) < 0){
		perror("open");
		exit(EXIT_FAILURE);
	}

	for(i = 0; i < 1000000; i++){
		if((n = write(fd, "sfawfdsaqww", 11)) < 0){
			perror("write");
			exit(EXIT_FAILURE);
		}
	}
	exit(EXIT_FAILURE);
}
