#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>

int main(void)
{
	int fd;
	if((fd = open("te", O_RDONLY | O_CREAT)) == -1){
		perror("open");
		exit(EXIT_FAILURE);
	}

	if(fchown(fd, 500, 500) == -1){
		perror("fchown");
		exit(EXIT_FAILURE);
	}

	exit(EXIT_FAILURE);
}
