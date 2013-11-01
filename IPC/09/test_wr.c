#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
void file_lock(int);
void file_unlock(int);

int main(void)
{
	int fd;

	if((fd = open("Og", O_RDONLY | O_CREAT, 0644)) < 0){
		perror("open");
		exit(EXIT_FAILURE);
	}

	file_lock(fd);
	printf("get the read lock\n");
	sleep(10);
	file_unlock(fd);

	if(close(fd) < 0){
		perror("close");
		exit(EXIT_FAILURE);
	}

	exit(EXIT_SUCCESS);
}

void file_lock(int fd)
{
	struct flock lock;

	lock.l_type = F_RDLCK;
	lock.l_whence = SEEK_SET;
	lock.l_start = 0;
	lock.l_len = 0;

	if(fcntl(fd, F_SETLKW, &lock) < 0){
		perror("fcntl");
		exit(EXIT_FAILURE);
	}
}

void file_unlock(int fd)
{
	struct flock lock;

	lock.l_type = F_UNLCK;
	lock.l_whence = SEEK_SET;
	lock.l_start = 0;
	lock.l_len = 0;

	if(fcntl(fd, F_SETLK, &lock) < 0){
		perror("fcntl");
		exit(EXIT_FAILURE);
	}
}
