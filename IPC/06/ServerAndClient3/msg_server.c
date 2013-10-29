#include<stdio.h>
#include<stdlib.h>
#include<sys/msg.h>
#include<sys/stat.h>
#include<sys/types.h>
int main(int argc, char *argv[])
{
	int msgqid;
	key_t key;
	key = Ftok("/tmp/msg1", 0);
	msgqid = Msgget(key, 0644 | IPC_CREAT);
	server(msgqid, msgqid);

	exit(EXIT_FAILURE);
}
