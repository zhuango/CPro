#include<sys/msg.h>
#include<stdlib.h>
#include<stdio.h>
int Msgget(key_t, int);
void Msgsnd(int, const void *, size_t, int);
void Msgctl(int, int, struct msqid_ds*);

typedef unsigned long ulong_t;
struct msgbuf{
	long mtype;
	char mtext[2];
};
int main(int argc, char *argv[])
{
	int msqid;
	struct msqid_ds info;
	struct msgbuf 	buf,buf2;/* two messages */

	msqid = Msgget(IPC_PRIVATE, 0644 | IPC_CREAT);/* Get queue */

	/* message1 */
	buf.mtype = 1;
	buf.mtext[0] = 1;
	buf.mtext[1] = 1;
	/* message2 */
	buf2.mtype = 1;
	buf2.mtext[0] = 1;
	buf2.mtext[1] = 2;

	/* send message */
	Msgsnd(msqid, &buf, 2, 0);
	Msgsnd(msqid, &buf2, 2, 0);

	Msgctl(msqid, IPC_STAT, &info);/* get queue's info(msqid_ds) */

	printf("read-write: %03o, cbytes = %lu, qnum = %lu, gbytes =%lu\n",
			info.msg_perm.mode & 0777, (ulong_t) info.msg_cbytes,
			(ulong_t)info.msg_qnum, (ulong_t) info.msg_qbytes);

	system("ipcs -q");

	Msgctl(msqid, IPC_RMID, NULL);/* delete queue */

	exit(EXIT_FAILURE);
}
/* msgget */
int Msgget(key_t key, int flag)
{
	int msqid;
	if((msqid = msgget(key, flag)) < 0){
		perror("msgget");
		exit(EXIT_FAILURE);
	}
	return (msqid);
}
/* msgsnd */
void Msgsnd(int msqid, const void *ptr, size_t length, int flag)
{
	if(msgsnd(msqid, ptr, length, flag) < 0){
		perror("msgsnd");
		exit(EXIT_FAILURE);
	}
}
/* msgctl */
void Msgctl(int msqid, int cmd, struct msqid_ds *buff)
{
	if(msgctl(msqid, cmd, buff) < 0){
		perror(",sgctl");
		exit(EXIT_FAILURE);
	}
}

