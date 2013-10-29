#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>

#define FIFO "/tmp/myfifo"
int main(void){
	int nread;
	int fd;
	char buf[100];

	memset(buf,0,sizeof(buf));

	if( ( fd = open(FIFO,O_RDONLY | O_NONBLOCK,0) ) == -1){
		printf("poen FIFO failure\n");
		exit(1);
	}

	while(1){
		memset(buf,0,sizeof(buf));
		if( ( nread = read(fd,buf,100) ) < 0){
			perror("no fata yet\n");
		}

		printf("read %s from FIFO\n",buf);
		sleep(1);
	}

	close(fd);
	pause();
	unlink(FIFO);
}
