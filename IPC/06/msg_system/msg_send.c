#include<stdio.h>
#include<stdlib.h>
#include<sys/ipc.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<sys/msg.h>

struct msgbuf{
	int mtype;/* type of message */
	char mtext[2];/* message */
};

int main(int argc, char *argv[])
{
	int msgqid;/* message queue ID */
	key_t key;/* ftok gets the key */

	struct msgbuf *buf;
	if(argc != 3){/* get the pathname and the type of message */
		printf("Usage: %s <pathname> <datatype>\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	if((key = ftok(argv[1], 0)) < 0){/* get the key because the pathname */
		perror("ftok");/* error? */
		exit(EXIT_FAILURE);
	}
	if((msgqid = msgget(key, 0644)) < 0){/* get the message queue ID because the key */
		perror("msgget");
		exit(EXIT_FAILURE);
	}
	buf = malloc(sizeof(struct msgbuf));/* create space for message struct */
	buf->mtype = atoi(argv[2]);/* type you want */
	/* message */
	buf->mtext[0] = 'w';
	buf->mtext[1] = '\0';
	/* send the message */
	if(msgsnd(msgqid, buf, 2, 0) < 0){
		perror("msgsnd");/* error? */
		exit(EXIT_FAILURE);
	}

	system("ipcs -q");/* see the messaeg queue info */
	exit(EXIT_SUCCESS);
}
