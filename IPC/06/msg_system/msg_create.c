#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/msg.h>
#include<sys/stat.h>
#include<sys/ipc.h>
int main(int argc, char *argv[])
{
	int msgqid;
	key_t key;
	if(argc != 2){
		printf("Usage: %s <pathname> \n", argv[0]);
		exit(EXIT_FAILURE);
	}
	if((key = ftok(argv[1], 0)) < 0){
		perror("ftok");
	}
	printf("%lx\n", key);
	if((msgqid = msgget(key, 0644 | IPC_CREAT)) < 0){
		perror("msgqid");
		exit(EXIT_FAILURE);
	}
	system("ipcs -q");
/*
	if(msgctl(msgqid, IPC_RMID, NULL) < 0){
		perror("msgctl");
		exit(EXIT_FAILURE);
	}
*/
	exit(EXIT_FAILURE);
}
