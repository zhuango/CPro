#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<sys/msg.h>
#include<string.h>
#include"msgbuf.h"

void client(int readid, int writeid)
{
	struct msgbuf *buf;
	struct msgbuf *buf2;
	int n;
	buf = malloc(sizeof(struct msgbuf));
	buf2 = malloc(sizeof(struct msgbuf));
	buf2->mesg_type = 1;
	buf2->mesg_len = MAXDATA;
	buf->mesg_len = MAXDATA;
	buf->mesg_type = 1;

	n = sprintf(buf->mesg_data, "%d", readid);
	buf->mesg_len = n;
<<<<<<< HEAD
//	buf2->mesg_len = n;
	buf->mesg_data[n] = '\0';
//	mesg_send(writeid, buf);
=======
	buf->mesg_data[n] = '\0';
	mesg_send(writeid, buf);
>>>>>>> b377d5b6d37e1e0791c3b0af7035f3dc99c42dd4

	buf->mesg_data[0] = 'L';
	buf->mesg_data[1] = 'i';
	buf->mesg_data[2] = 'u';
	buf->mesg_data[3] = '\0';
<<<<<<< HEAD
	mesg_send(writeid, buf);
	printf("client writeid: %d\n", writeid);
=======
	printf("client writeid: %d\n", writeid);
	mesg_send(writeid, buf);
>>>>>>> b377d5b6d37e1e0791c3b0af7035f3dc99c42dd4

	mesg_recv(readid, buf2);
	printf("recv from %d: %s\n", readid, buf2->mesg_data);
}
