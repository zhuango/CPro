#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/sem.h>
#include<stdio.h>
#include<stdlib.h>

int main(void)
{
	int semid;
	int nsems = 1;
	int flags = 0666;
	struct sembuf buf;

	semid = semget(IPC_PRIVATE,nsems,flags);
	if(semid < 0){
		perror("semget");
		exit(EXIT_FAILURE);
	}

	printf("semaphore created : %d\n",semid);

	buf.sem_num = 0;
	buf.sem_op = 1;
	buf.sem_flg = IPC_NOWAIT;

	if ( (semop(semid,&buf,nsems)) < 0){
		perror("semop");
		exit(EXIT_FAILURE);
	}

	system("ipcs -s");
	exit(EXIT_SUCCESS);
}
