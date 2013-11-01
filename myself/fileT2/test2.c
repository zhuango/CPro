#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>

int main(void)
{
	int fd, fd1;

	if((fd = open("result", O_WRONLY | O_CREAT, 0644)) < 0){
		perror("open");
		exit(EXIT_FAILURE);
	}

	printf("In the pingu\n");
	if((fd1 = dup(fd)) < 0){
		perror("dup");
		exit(EXIT_FAILURE);
	}
	if((fd1 = dup2(fd, 2)) < 0){
		perror("dup2");
		exit(EXIT_FAILURE);
	}

	if((fd = dup2(fd, 1)) < 0){
		perror("dup2");
		exit(EXIT_FAILURE);
	}
	fprintf(stderr, "Bong!!!!!\n");
	printf("Ni MA B\n");
	exit(EXIT_SUCCESS);
}
