#include<sys/types.h>
#include<sys/stat.h>
#include<errno.h>
#include<fcntl.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define FIFO "/tmp/myfifo"

int main(int argc, char **argv){
	char buf_r[100];
	int fd;
	int nread;

	printf("Preparing for reading bytes...\n");
	memset(buf_r,0 ,sizeof(buf_r));

	fd = open(FIFO,O_RDONLY | O_NONBLOCK,0);

	if(fd == -1){
		perror("open");
		exit(1);
	}
	while(1){

		memset(buf_r,0,sizeof(buf_r));

		if( (nread = read(fd,buf_r,100)) == -1){
			if(errno == EAGAIN)
				printf("no fata yet\n");
		}
		printf("read %s from FIFO\n",buf_r);
		sleep(1);
	}

	close(fd);
	pause();
	unlink(FIFO);
}
