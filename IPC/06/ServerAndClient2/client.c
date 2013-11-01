#include<stdio.h>
#include<stdlib.h>
<<<<<<< HEAD
#include<string.h>
#include<signal.h>
=======
>>>>>>> b377d5b6d37e1e0791c3b0af7035f3dc99c42dd4
#include<sys/types.h>
#include<sys/stat.h>
#include<sys/msg.h>
#include"msgbuf.h"

<<<<<<< HEAD
int Readid;

void sigint(int num)
{
	Msgctl(Readid, IPC_RMID, NULL);
	exit(EXIT_FAILURE);
}
=======
>>>>>>> b377d5b6d37e1e0791c3b0af7035f3dc99c42dd4
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
<<<<<<< HEAD
	
	if(signal(SIGINT, sigint) < 0) {
		perror("signal");
		exit(EXIT_FAILURE);
	}

	Readid = readid;
	sprintf(buf->mesg_data, "%d", readid);
	buf->mesg_len = strlen(buf->mesg_data);
	mesg_send(writeid, buf);
	printf("Send to Server: %s\n", buf->mesg_data);
=======
	sprintf(buf->mesg_data, "%d", writeid);
	mesg_send(writeid, buf);
>>>>>>> b377d5b6d37e1e0791c3b0af7035f3dc99c42dd4

	buf->mesg_data[0] = 'L';
	buf->mesg_data[1] = 'i';
	buf->mesg_data[2] = 'u';
<<<<<<< HEAD
	buf->mesg_len = strlen(buf->mesg_data);
	
=======
	buf->mesg_len = MAXDATA;
	printf("client writeid: %d\n", writeid);
>>>>>>> b377d5b6d37e1e0791c3b0af7035f3dc99c42dd4
	mesg_send(writeid, buf);

	mesg_recv(readid, buf2);

<<<<<<< HEAD
	printf("Recv from server: %s\n", buf2->mesg_data);
=======
	printf("recv from server: %s\n", buf2->mesg_data);
>>>>>>> b377d5b6d37e1e0791c3b0af7035f3dc99c42dd4
}
