#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/msg.h>
#include<sys/stat.h>
#include"msgbuf.h"

void server(int readid, int writeid)
{
	struct msgbuf *buf;
	int n;
	buf = malloc(sizeof(struct msgbuf));
	buf->mesg_len = MAXDATA;
	buf->mesg_type = 1;

	for(;;){
		printf("Server Waiting ... readid : %d \n", readid);
		n = mesg_recv(readid, buf);
		buf->mesg_data[n] = '\0';
		printf("recv from client: %s\n",buf->mesg_data);
		sleep(1);
		buf->mesg_type = 1;
		mesg_send(writeid, buf);

	}
}
