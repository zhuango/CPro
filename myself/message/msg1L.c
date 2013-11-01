#include<stdlib.h>
#include<sys/types.h>
#include<errno.h>
#include<string.h>
#include<sys/msg.h>
#include<sys/ipc.h>
#include<stdio.h>


struct message{
	int type;
	char buffer[BUFSIZ];
};

int main(void){
	struct message *msg;
	int msgqid;
	int running = 1;
	int msgtype = 0;

	msg = (struct message *) malloc(sizeof(struct message));
	msgqid = msgget( (key_t)123,0666 | IPC_CREAT);
	if(msgqid == -1){
		fprintf(stderr,"create message error\n");
		exit(EXIT_FAILURE);
	}

	while(running){

		if( msgrcv(msgqid,msg,BUFSIZ,msgtype,0) == -1){
			printf("receive info error:%s\n",errno);
			exit(EXIT_FAILURE);
		}

		printf("you wrote: %s",msg->buffer);

		if(strncmp(msg->buffer,"end",3) == 0){
			running = 0;
		}
	}

	if( msgctl(msgqid,IPC_RMID,0) == -1 ){
		fprintf(stderr,"delete message error\n");
		exit(EXIT_FAILURE);
	}

	exit(EXIT_SUCCESS);
}
