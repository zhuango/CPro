#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/msg.h>
#include<sys/stat.h>

int main(int argc, char *argv[])
{
	int msgqid;
	if(argc != 2){
		printf("Usage: <msgqid>\n");
		exit(EXIT_FAILURE);
	}
	msgqid = atoi(argv[1]);
	if(msgctl(msgqid, IPC_RMID, NULL) < 0){
		perror("msgctl");
		exit(EXIT_FAILURE);
	}

	exit(EXIT_SUCCESS);
}
