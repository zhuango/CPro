#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#include<stdio.h>
#include<stdlib.h>

#define BUFSZ 4096

int main(int argc,char **argv)
{
	int shmid;
	char *shmbuf;


	if( (shmid = shmget(IPC_PRIVATE,BUFSZ,0666)) < 0){
		perror("shmget");
		exit(EXIT_FAILURE);
	}

	if( (shmbuf = shmat(shmid,0,0)) < (char *)0){
		perror("shmat");
		exit(EXIT_FAILURE);
	}

	printf("segment attached at %p\n",shmbuf);

	system("ipcs -m");

	if( (shmdt(shmbuf)) < 0){
		perror("shmdt");
		exit(EXIT_FAILURE);
	}

	puts("segment detached");

	system("ipcs -m");
	exit(EXIT_SUCCESS);
}
