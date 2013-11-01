#include<stdio.h>
#include<stdlib.h>
#include<semaphore.h>
#include<fcntl.h>

int main(void)
{
	if(sem_unlink("test1") < 0){
		perror("sem_unlink");
		exit(EXIT_FAILURE);
	}
	exit(EXIT_FAILURE);
}
