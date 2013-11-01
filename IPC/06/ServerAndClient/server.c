#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/msg.h>
#include<sys/stat.h>
<<<<<<< HEAD
#include<signal.h>
#include"msgbuf.h"
int Readid, Writeid;

void SigInt(int num)
{
	Msgctl(Writeid, IPC_RMID, NULL);
	Msgctl(Readid, IPC_RMID, NULL);
	exit(EXIT_FAILURE);
}
=======
#include"msgbuf.h"
>>>>>>> b377d5b6d37e1e0791c3b0af7035f3dc99c42dd4

void server(int readid, int writeid)
{
	struct msgbuf *buf;
<<<<<<< HEAD
	struct msgbuf *buf2;

	Readid = readid;
	Writeid = writeid;

	if( signal(SIGINT, SigInt) < 0 ) {
		perror("signal");
		exit(EXIT_FAILURE);
	}
=======
>>>>>>> b377d5b6d37e1e0791c3b0af7035f3dc99c42dd4
	int n;
	buf = malloc(sizeof(struct msgbuf));
	buf->mesg_len = MAXDATA;
	buf->mesg_type = 1;
<<<<<<< HEAD
	buf2->mesg_len = MAXDATA;
	buf2->mesg_type = 1;
=======
>>>>>>> b377d5b6d37e1e0791c3b0af7035f3dc99c42dd4

	for(;;){
		printf("Server Waiting ... readid : %d \n", readid);
		n = mesg_recv(readid, buf);
		buf->mesg_data[n] = '\0';
		printf("recv from client: %s\n",buf->mesg_data);
<<<<<<< HEAD
		
		sleep(1);
		buf->mesg_type = 1;
		mesg_send(writeid, buf);
		printf("Send %s to client\n\n", buf->mesg_data);
=======
		sleep(1);
		buf->mesg_type = 1;
		mesg_send(writeid, buf);
>>>>>>> b377d5b6d37e1e0791c3b0af7035f3dc99c42dd4

	}
}
