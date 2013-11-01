#include<stdio.h>
#include<stdlib.h>
#include<sys/ipc.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<sys/msg.h>

struct msgbuf{
	int mtype;
	char mtext[2];
};

int main(int argc, char *argv[])
{
	int msgqid;
	key_t key;

	struct msgbuf *buf;
	if(argc != 3){
		printf("Usage: %s <pathname> <datatype>\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	if((key = ftok(argv[1], 0)) < 0){
		perror("ftok");
		exit(EXIT_FAILURE);
	}
	if((msgqid = msgget(key, 0644)) < 0){
		perror("msgget");
		exit(EXIT_FAILURE);
	}
	buf = malloc(sizeof(struct msgbuf));
	buf->mtype = atoi(argv[2]);
	buf->mtext[0] = 'w';
	buf->mtext[1] = '\0';
	if(msgsnd(msgqid, buf, 2, 0) < 0){
		perror("msgsnd");
		exit(EXIT_FAILURE);
	}

	system("ipcs -q");
	exit(EXIT_SUCCESS);
}
