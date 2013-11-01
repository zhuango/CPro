#include<stdio.h>
#include<stdlib.h>
#include<sys/msg.h>
#include<sys/stat.h>
#include<sys/types.h>
int main(int argc, char *argv[])
{
	int readid, writeid;
	key_t Rkey, Wkey;
	
	Rkey = Ftok("/tmp/msg", 0);
	Wkey = Ftok("/tmp/msg2", 0);

	readid = Msgget(Rkey, 0644 | IPC_CREAT);
	writeid = Msgget(Wkey, 0644 | IPC_CREAT);

	server(readid, writeid);


	exit(EXIT_FAILURE);
}
