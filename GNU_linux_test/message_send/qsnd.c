#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/msg.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>

#define BUFSZ 512

struct msg{
	long msg_type;
	char msg_text[BUFSZ];
};

int main(int argc,char **argv)
{
	int qid;
	int len;
	key_t key;
	key = 113;
	struct msg pmsg;

	if( (qid = msgget(key,IPC_CREAT | 0666)) < 0){
		perror("msgget");
		exit(EXIT_FAILURE);
	}

	printf("Enter message to post <%d>:\n",qid);
	if( (fgets((&pmsg)->msg_text,BUFSZ,stdin)) == NULL){
		puts("no message to post");
		exit(EXIT_SUCCESS);
	}

	pmsg.msg_type = getpid();

	len = strlen(pmsg.msg_text);
	if( (msgsnd(qid,&pmsg,len,0)) < 0){
		perror("msgsnd");
		exit(EXIT_FAILURE);
	}

	puts("message poeted");
	exit(EXIT_SUCCESS);
}
