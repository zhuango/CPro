#include<unistd.h>
#include<sys/file.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void lock_set(int fd,int type);

int main(void){
	int fd,nwrite,nread,len;
	char *buff = "Hello\n";
	char buf_r[100];
	buf_r[100] = '\0';
	len = strlen(buff);
	fd = open("hello",O_RDWR | O_CREAT,0666);
	if(fd < 0){
		perror("open");
		exit(EXIT_FAILURE);
	}
	lock_set(fd,F_WRLCK);//F_WRLCK is lock of write
	if( (nwrite = write(fd,buff,len)) == len){
		printf("write success\n");
	}

	getchar();
	lock_set(fd,F_UNLCK);//unlock file
	getchar();
	lock_set(fd,F_RDLCK);//lock file as read
	lseek(fd,0,SEEK_SET);//put the porintor to the start of file

	if( (nread = read(fd,buf_r,len)) == len){
		printf("read L %s\n",buf_r);
	}

	getchar();
	lock_set(fd,F_UNLCK);//unlock file
	getchar();
	close(fd);//close the file
	exit(0);
}

void lock_set(int fd,int type){
	struct flock lock;//set lock arg
	lock.l_whence = SEEK_SET;
	lock.l_start = 0;
	lock.l_len = 0;

	while(1){
		lock.l_type = type;

		//set lock for file 
		if( (fcntl(fd,F_SETLK,&lock)) == 0){
			if(lock.l_type == F_RDLCK)
				printf("read lock set by %d\n",getpid());
			else if(lock.l_type == F_WRLCK)
				printf("write lock set by %d\n",getpid());
			else if(lock.l_type == F_UNLCK)
				printf("release lock by %d\n",getpid());
			return ;
		}

		//if the file could be locked ? yes ,then lock the file.
		fcntl(fd,F_GETLK,&lock);
		//if counldn't lock the file ,then what's the reason
		if(lock.l_type != F_UNLCK){
			if(lock.l_type == F_RDLCK)//have read lock yet
				printf("read lock already set by %d\n",lock.l_pid);
			else if(lock.l_type == F_WRLCK)//have write lock yet
				printf("write lock already set by %d\n",lock.l_pid);
			getchar();
		}
	}
}
