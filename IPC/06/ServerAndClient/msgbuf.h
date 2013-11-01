#ifndef __MSGBUFF_H__
#define __MSGBUFF_H__

#define MAXMESSAGE 1024
#define MAXDATA (MAXMESSAGE - (2*sizeof(long)))
#define MESSAGEINFO (sizeof(struct msgbuf) - MAXDATA)
struct msgbuf{
	long mesg_len;
	long mesg_type;
	char mesg_data[MAXDATA];
};

#endif
