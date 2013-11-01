#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/sem.h>
#include<stdio.h>
#include<stdlib.h>

int main(int argc, char **argv)
{
	int semid;

	if( argc != 2){
		puts("USAGE: sctl<semapthore id>");
		exit(EXIT_FAILURE);
	}

	semid = atoi(argv[1]);

	if( (semctl(semid,0,IPC_RMID)) < 0){
		perror("semctl IPC_RMID");
		exit(EXIT_FAILURE);
	}else{
		puts("semphore removed");
		system("ipcs -s");
	}

	exit(EXIT_SUCCESS);
}
