#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<signal.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<sys/msg.h>
#include"msgbuf.h"

int Readid;

void sigint(int num)
{
	Msgctl(Readid, IPC_RMID, NULL);
	exit(EXIT_FAILURE);
}
void client(int readid, int writeid)
{
	struct msgbuf *buf;
	struct msgbuf *buf2;
	buf = malloc(sizeof(struct msgbuf));
	buf2 = malloc(sizeof(struct msgbuf));
	buf2->mesg_type = 1;
	buf2->mesg_len = MAXDATA;
	buf->mesg_len = MAXDATA;
	buf->mesg_type = 1;
	
	if(signal(SIGINT, sigint) < 0) {
		perror("signal");
		exit(EXIT_FAILURE);
	}

	Readid = readid;
	sprintf(buf->mesg_data, "%d", readid);
	buf->mesg_len = strlen(buf->mesg_data);
	mesg_send(writeid, buf);
	printf("Send to Server: %s\n", buf->mesg_data);

	buf->mesg_data[0] = 'L';
	buf->mesg_data[1] = 'i';
	buf->mesg_data[2] = 'u';
	buf->mesg_len = strlen(buf->mesg_data);
	
	mesg_send(writeid, buf);

	mesg_recv(readid, buf2);

	printf("Recv from server: %s\n", buf2->mesg_data);
}
