#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>


int Fcntl(int fd, int cmd, struct flock *arg)
{
	if(fcntl(fd, cmd, arg) < 0){
		perror("fcntl");
		exit(EXIT_FAILURE);
	}
}


void my_lock(int fd)
{
	struct flock lock;

	lock.l_type = F_WRLCK;
	lock.l_whence = SEEK_SET;
	lock.l_start = 0;
	lock.l_len = 0;

	Fcntl(fd, F_SETLKW, &lock);
	return ;
}

void my_unlock(int fd)
{
	struct flock lock;
	
	lock.l_type = F_UNLCK;
	lock.l_whence = SEEK_SET;
	lock.l_start = 0;
	lock.l_len = 0;

	Fcntl(fd, F_SETLK, &lock);
	return ;
}
