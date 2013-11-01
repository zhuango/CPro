#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<sys/msg.h>
void clinet(int, int);

int main(void)
{
	int msgqid;
	key_t Rkey, Wkey;

	Wkey = Ftok("/tmp/msg1", 0);

	msgqid = Msgget(Wkey, 0644 | IPC_CREAT);

	client(msgqid, msgqid);

	exit(EXIT_SUCCESS);
}
