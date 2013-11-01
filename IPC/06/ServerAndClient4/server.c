#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/msg.h>
#include<sys/stat.h>
#include"msgbuf.h"

void server(int readid, int writeid)
{
	struct msgbuf *buf;
	int type;
	buf = malloc(sizeof(struct msgbuf));
	buf->mesg_len = MAXDATA;
	buf->mesg_type = 1;

	for(;;){
		buf->mesg_type = 1;
		mesg_recv(readid, buf);
		type = atoi(buf->mesg_data);

		printf("waiting...\n");
		mesg_recv(readid, buf);
		printf("recv from %d: %s(type: %d)\n", readid, buf->mesg_data,
				buf->mesg_type);
		sleep(1);
		buf->mesg_type = type;
		printf("send to client type: %d\n", buf->mesg_type);
		mesg_send(writeid, buf);
	}
}
