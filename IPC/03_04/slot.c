#include<stdio.h>
#include<stdlib.h>
#include<sys/msg.h>

int Msgget(key_t key, int oflag){
	int id;
	if((id = msgget(key, oflag)) < 0){
		perror("msgget");
		exit(EXIT_FAILURE);
	}
	return (id);
}

void Msgctl(int msqid, int cmd, struct msqid_ds *buff)
{
	if(msgctl(msqid, cmd, NULL) < 0){
		perror("msgclt");
		exit(EXIT_FAILURE);
	}
}

int main(int argc, char *argv[])
{
	int 	i,msqid;
	for(i = 0; i < 10; i++){
		msqid = Msgget(IPC_PRIVATE, IPC_CREAT);/* Create a message queue */
		printf("msqid = %d\n", msqid);

		Msgctl(msqid, IPC_RMID, NULL);/* Delete message queeu */
	}

	exit(EXIT_SUCCESS);
}
