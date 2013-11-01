#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<sys/msg.h>
#include"msgbuf.h"

void client(int readid, int writeid)
{
	struct msgbuf *buf;
	struct msgbuf *buf2;
	buf = malloc(sizeof(struct msgbuf));
	buf2 = malloc(sizeof(struct msgbuf));
	buf2->mesg_type = 2;
	buf2->mesg_len = MAXDATA;
	buf->mesg_len = MAXDATA;
	buf->mesg_type = 1;
	buf->mesg_data[0] = 'L';
	buf->mesg_data[1] = 'i';
	buf->mesg_data[2] = 'f';
	buf->mesg_data[3] = '\0';
	buf->mesg_len = MAXDATA;
	printf("client writeid: %d\n", writeid);
	mesg_send(writeid, buf);

	mesg_recv(readid, buf2);

	printf("recv from server: %s\n", buf2->mesg_data);
}
