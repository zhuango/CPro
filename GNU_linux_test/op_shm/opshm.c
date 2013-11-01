#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<ctype.h>

#define BUFSZ 4096

int main(void)
{
	int shmid;

	char *shmbuf;
	int fd;
	int i;

	if( (shmid = shmget(IPC_PRIVATE,BUFSZ,0666)) < 0){
		perror("shmid");
		exit(EXIT_FAILURE);
	}

	if( (shmbuf = shmat(shmid,0,0)) < (char *)0){
		perror("shmat");
		exit(EXIT_FAILURE);
	}
	printf("%p\n",shmbuf);

	if( (shmbuf = malloc(sizeof(char) * BUFSZ)) == NULL){
		perror("malloc");
		exit(EXIT_FAILURE);
	}
	printf("%p\n",shmbuf);

	for(i = 0;i < BUFSZ;i++){
		shmbuf[i] = rand();
	}

	fd = open("opsh.out",O_CREAT | O_WRONLY,0666);
	write(fd,shmbuf,BUFSZ);

	free(shmbuf);
	exit(EXIT_SUCCESS);
}
