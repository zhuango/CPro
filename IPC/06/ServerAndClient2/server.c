#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/types.h>
#include<sys/msg.h>
#include<signal.h>
#include<sys/stat.h>
#include"msgbuf.h"
int Readid;
void sigint(int num)
{
	Msgctl(Readid, IPC_RMID, NULL);
	exit(EXIT_FAILURE);
}

void server(int readid)
{
	struct msgbuf *buf;
	int n, writeid;
	buf = malloc(sizeof(struct msgbuf));
	buf->mesg_len = MAXDATA;
	buf->mesg_type = 1;

	if( signal(SIGINT, sigint) < 0) {
		perror("signal");
		exit(EXIT_FAILURE);
	}
	Readid = readid;

	for(;;){
		/* Get the client msgid */
		n = mesg_recv(readid, buf);
		buf->mesg_data[n] = '\0';
		writeid = atoi(buf->mesg_data);
		/* Recvive message */
		n = mesg_recv(readid, buf);
		buf->mesg_data[n] = '\0';
		printf("recv from client: %s\n",buf->mesg_data);
		
		sleep(1);

		buf->mesg_type = 1;
		printf("send to %d \n", writeid);
		mesg_send(writeid, buf);
	}
}
