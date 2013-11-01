#include<stdio.h>
#include<stdlib.h>
#include<sys/msg.h>

struct msgbuf{
	long mtype;
	char mtext[2];
};

int main(int argc, char *argv[])
{
	int msgqid;
	struct msgbuf buf;

	if(argc != 3){
		printf("Usage: %s <msgqid> <datatype>\n", argv[0]);
		exit(EXIT_SUCCESS);
	}
	msgqid =atoi(argv[1]);

	if(msgrcv(msgqid, &buf, 2, atoi(argv[2]), IPC_NOWAIT) < 0){
		perror("msgrcv");
		exit(EXIT_FAILURE);
	}

	printf("date type: %ld recv : %s\n",buf.mtype, buf.mtext);

	system("ipcs -q");

	exit(EXIT_FAILURE);
}
