#include<sys/types.h>
#include<sys/stat.h>
#include<errno.h>
#include<fcntl.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define FIFO "/tmp/myfifo"

int main(void){
	int fd;
	char buffer[100];

	memset(buffer,0,100);

	if( (fd = open(FIFO,O_RDONLY | O_NONBLOCK,0)) < 0){
		fprintf(stderr,"open error!\n");
		exit(EXIT_FAILURE);
	}

	while(1){
		memset(buffer,0,100);
		if( read(fd,buffer,100) < 0){
			fprintf(stderr,"nothing!\n");
		}else {
			printf("read from server : %s \n",buffer);
		}
		sleep(1);
	}
	close(fd);
	pause();
	unlink(FIFO);
	return 0;
}
