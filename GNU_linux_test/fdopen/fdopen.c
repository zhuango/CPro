#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<stdlib.h>
#include<stdio.h>

int main(void)
{
	int fd;
	char path[] = "hello";

	if ( (fd = open(path,O_CREAT | O_TRUNC | O_WRONLY | 0644)) < 0){
		perror("open");
		exit(EXIT_FAILURE);
	}else{
		printf("opened %s\n",path);
		printf("descriptor is %d\n",fd);
	}

	if( close(fd) < 0){
		perror("close");
		exit(EXIT_FAILURE);
	}else{
		printf("closed %s \n",path);
	}

	exit(EXIT_SUCCESS);
}
