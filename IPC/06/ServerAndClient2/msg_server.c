#include<stdio.h>
#include<stdlib.h>
#include<sys/msg.h>
#include<sys/stat.h>
#include<sys/types.h>

int main(int argc, char *argv[])
{
	int readid;
	key_t Rkey;
	
	Rkey = Ftok("/tmp/msg", 0);

	readid = Msgget(Rkey, 0644 | IPC_CREAT);

	server(readid);

	exit(EXIT_FAILURE);
}
