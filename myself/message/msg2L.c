#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/msg.h>
#include<errno.h>
#include<malloc.h>
#include<string.h>
#define BUFFER 512

struct message{
	int type;
	char buffer[BUFFER];
};

int main(void){
	int running = 1;
	int msgqid;
	struct message *msg;
	char buffer[BUFFER];

	msg = (struct message *) malloc (sizeof(struct message));
	msgqid = msgget( (key_t)123 , 0666 | IPC_CREAT);

	if(msgqid == -1){
		fprintf(stderr,"create message error\n");
		exit(EXIT_FAILURE);
	}

	while(running){
		printf("Please input something : ");
		fgets(buffer,BUFFER,stdin);
		msg->type = 1;
		strcpy(msg->buffer,buffer);

		if( msgsnd(msgqid,msg,BUFFER,0) == -1){
			printf("send message error\n");
			exit(EXIT_FAILURE);
		}

		if(strncmp(buffer,"end",3) == 0){
			running = 0;
		}
	}

	exit(EXIT_FAILURE);
}
