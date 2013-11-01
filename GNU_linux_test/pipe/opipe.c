#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>

int main(void)
{
	int fd[2];

	if( (pipe(fd)) < 0){
		perror("pipe");
		exit(EXIT_FAILURE);
	}

	printf("descriptors are %d, %d\n",fd[0],fd[1]);
	close(fd[0]);
	close(fd[1]);

	exit(EXIT_SUCCESS);
}
