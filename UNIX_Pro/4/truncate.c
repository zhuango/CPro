#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>

int main(void)
{
	int trun_fd;

	if((trun_fd = open("foo",O_WRONLY)) < 0){
		perror("open");
		exit(EXIT_FAILURE);
	}

	if(ftruncate(trun_fd, 10) < 0){
		perror("trun_fd");
		exit(EXIT_FAILURE);
	}

	return 0;
}
