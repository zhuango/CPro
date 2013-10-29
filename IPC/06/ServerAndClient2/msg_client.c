#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<sys/msg.h>
void clinet(int, int);

int main(void)
{
	int readid, writeid;
	key_t Rkey, Wkey;

	Wkey = Ftok("/tmp/msg", 0);
	Rkey = Ftok("/tmp/msg2", 0);

	readid = Msgget(Rkey, 0644 | IPC_CREAT);
	writeid = Msgget(Wkey, 0644 | IPC_CREAT);

	client(readid, writeid);

	Msgctl(readid, IPC_RMID, NULL);
	Msgctl(writeid, IPC_RMID, NULL);

	exit(EXIT_SUCCESS);
}
