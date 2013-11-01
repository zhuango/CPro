#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/msg.h>
#include<stdio.h>
#include<stdlib.h>

#define BUFSZ 512

struct msg{
	long msg_type;
	char msg_text[BUFSZ];
};

int main(int argc,char **argv)
{
	int qid;
	int len;

	struct msg pmsg;

	if (argc != 2){
		puts("USAGE:qrd<queue ID>");
		exit(EXIT_FAILURE);
	}
	qid = atoi(argv[1]);

	len = msgrcv(qid,&pmsg,BUFSZ,0,0);
	if( len > 0){
		(&pmsg)->msg_text[len] = '\0';
		printf("reading queue: is %d\n",qid);
		printf("message type: %05ld\n",(&pmsg)->msg_type);
		printf("message length: %d bytes \n",len);
		printf("message text: %s\n",(&pmsg)->msg_text);
	}else{
		perror("msgrcv");
		exit(EXIT_FAILURE);
	}

	exit(EXIT_SUCCESS);
}
