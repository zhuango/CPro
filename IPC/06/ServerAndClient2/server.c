#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/msg.h>
#include<sys/stat.h>
#include"msgbuf.h"

void server(int readid)
{
	struct msgbuf *buf;
	int n, writeid;
	buf = malloc(sizeof(struct msgbuf));
	buf->mesg_len = MAXDATA;
	buf->mesg_type = 1;

	for(;;){
		n = mesg_recv(readid, buf);
		buf->mesg_data[n] = '\0';
		writeid = atoi(buf->mesg_data);

		n = mesg_recv(readid, buf);
		buf->mesg_data[n] = '\0';
		printf("recv from client: %s\n",buf->mesg_data);
		
		sleep(1);

		buf->mesg_type = 1;
		printf("send to %d \n", writeid);
		mesg_send(writeid, buf);

	}
}
