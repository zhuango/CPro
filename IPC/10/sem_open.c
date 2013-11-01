#include<stdio.h>
#include<stdlib.h>
#include<semaphore.h>
#include<fcntl.h>

int main(void)
{
	sem_t *sem;

	if((sem = sem_open("test1", O_RDWR | O_CREAT, 0644, 1)) 
			== SEM_FAILED){
		perror("sem_open");
		exit(EXIT_FAILURE);
	}
	if(sem_close(sem) < 0){
		perror("sem_close");
		exit(EXIT_FAILURE);
	}
	exit(EXIT_FAILURE);
}
