#include<stdio.h>
#include<stdlib.h>
#include<sys/msg.h>
#include<sys/stat.h>
#include<sys/types.h>

int main(int argc, char *argv[])
{
<<<<<<< HEAD
	int readid;
	key_t Rkey;
=======
	int readid, writeid;
	key_t Rkey, Wkey;
>>>>>>> b377d5b6d37e1e0791c3b0af7035f3dc99c42dd4
	
	Rkey = Ftok("/tmp/msg", 0);

	readid = Msgget(Rkey, 0644 | IPC_CREAT);

	server(readid);

	exit(EXIT_FAILURE);
}
