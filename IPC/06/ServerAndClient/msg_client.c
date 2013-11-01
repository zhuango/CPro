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

<<<<<<< HEAD
//	Msgctl(readid, IPC_RMID, NULL);
=======
	Msgctl(readid, IPC_RMID, NULL);
>>>>>>> b377d5b6d37e1e0791c3b0af7035f3dc99c42dd4

	exit(EXIT_SUCCESS);
}
