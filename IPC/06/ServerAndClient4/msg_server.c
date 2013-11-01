#include<stdio.h>
#include<stdlib.h>
#include<sys/msg.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<signal.h>

int qid;
void rmq(int signo)
{
	Msgctl(qid, IPC_RMID, NULL);
	exit(EXIT_SUCCESS);
}
int main(int argc, char *argv[])
{
	int msgqid;
	key_t key;
	key = Ftok("/tmp/msg1", 0);
	msgqid = Msgget(key, 0644 | IPC_CREAT);
	qid = msgqid;
	
	if(signal(SIGINT, rmq) < 0){
		perror("signal");
		exit(EXIT_FAILURE);
	}
	
	server(msgqid, msgqid);

	exit(EXIT_FAILURE);
}
