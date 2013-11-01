#include<sys/types.h>
#include<sys/ipc.h>
#include<stdio.h>
#include<stdlib.h>

int main(void)
{
	int qid;
	key_t key;

	key = 123;

	if( (qid = msgget(key,IPC_CREAT | 0666)) < 0){
		perror("msgget: create");
		exit(EXIT_FAILURE);
	}

	printf("created queue id = %d\n",qid);

	if( (qid = msgget(key,0)) < 0){
		perror("msgget: open");
		exit(EXIT_FAILURE);
	}

	printf("opened queue id = %d\n",qid);

	exit(EXIT_SUCCESS);
}
