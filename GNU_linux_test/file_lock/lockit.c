#include<unistd.h>
#include<sys/file.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<stdio.h>
#include<stdlib.h>

void setlock(int fd,int type);

int main(int argc, char **argv)
{
	int fd;

	fd = open(argv[1],O_RDWR | O_CREAT,0666);
	if( fd < 0 ){
		perror("open");
		exit(EXIT_FAILURE);
	}
	setlock(fd,F_RDLCK);
	printf("PID %d unlocked %s\n",getpid(),argv[1]);
	getchar();

	setlock(fd,F_UNLCK);
	printf("PID %d unlocked %s\n",getpid(),argv[1]);
	getchar();

	setlock(fd,F_WRLCK);
	printf("PID %d write locked %s\n",getpid(),argv[1]);
	getchar();
	close(fd);

	exit(EXIT_FAILURE);
}

void setlock(int fd,int type)
{
	struct flock lock;
	char msg[80];

	lock.l_whence = SEEK_SET;
	lock.l_start = 0;
	lock.l_len = 1;

	while(1){

		lock.l_type = type;

		if( (fcntl(fd,F_SETLK,&lock)) == 0)
				return ;
		fcntl(fd,F_GETLK,&lock);

		if( lock.l_type != F_UNLCK){
			switch(lock.l_type){
				case(F_RDLCK):
					sprintf(msg,"read lock already set by %d\n",lock.l_pid);
					break;
				case(F_WRLCK):
					sprintf(msg,"write lock alraedy set by %d\n",lock.l_pid);
					break;
			}
			puts(msg);
			getchar();
		}
	}
}
