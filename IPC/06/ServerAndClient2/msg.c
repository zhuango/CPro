#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<sys/msg.h>
#include<sys/ipc.h>

key_t Ftok(const char *pathname, int id)
{
	key_t key;
	if((key = ftok(pathname , id)) < 0){
		perror("ftok");
		exit(EXIT_FAILURE);
	}

	return (key);
}

int Msgget(key_t key, int flags)
{
	int msgqid;
	if((msgqid = msgget(key, flags)) < 0){
		perror("msgget");
		exit(EXIT_FAILURE);
	}

	return (msgqid);
}

void Msgctl(int msgqid, int opt, struct msqid_ds *buff)
{
	if(msgctl(msgqid, opt, buff) < 0){
		perror("msgctl");
		exit(EXIT_FAILURE);
	}
}
