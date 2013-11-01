#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/msg.h>
#include<sys/stat.h>
#include<signal.h>
#include"msgbuf.h"
int Readid, Writeid;

void SigInt(int num)
{
	Msgctl(Writeid, IPC_RMID, NULL);
	Msgctl(Readid, IPC_RMID, NULL);
	exit(EXIT_FAILURE);
}

void server(int readid, int writeid)
{
	struct msgbuf *buf;
	struct msgbuf *buf2;

	Readid = readid;
	Writeid = writeid;

	if( signal(SIGINT, SigInt) < 0 ) {
		perror("signal");
		exit(EXIT_FAILURE);
	}
	int n;
	buf = malloc(sizeof(struct msgbuf));
	buf->mesg_len = MAXDATA;
	buf->mesg_type = 1;
	buf2->mesg_len = MAXDATA;
	buf2->mesg_type = 1;

	for(;;){
		printf("Server Waiting ... readid : %d \n", readid);
		n = mesg_recv(readid, buf);
		buf->mesg_data[n] = '\0';
		printf("recv from client: %s\n",buf->mesg_data);
		
		sleep(1);
		buf->mesg_type = 1;
		mesg_send(writeid, buf);
		printf("Send %s to client\n\n", buf->mesg_data);

	}
}
