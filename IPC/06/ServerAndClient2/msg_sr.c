#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<sys/ipc.h>
#include<sys/msg.h>
#include"msgbuf.h"
ssize_t mesg_send(int id, struct msgbuf *mptr)
{
	return (msgsnd(id, &(mptr->mesg_type), MAXDATA, 0));
}

ssize_t mesg_recv(int id, struct msgbuf *mptr)
{
	ssize_t n;
	n = msgrcv(id, &(mptr->mesg_type), mptr->mesg_len, mptr->mesg_type, 0);
	mptr->mesg_len = n;

	return(n);
}
