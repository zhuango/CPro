#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<errno.h>
#include<fcntl.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define FIFO "/tmp/myfifo"

int main(int argc , char **argv){
	int fd;
	char buffer[100];

	memset(buffer,0,100);

	if( (mkfifo(FIFO, O_CREAT | O_EXCL | O_RDWR) < 0) && (errno != EEXIST)){
		fprintf(stderr,"create FIFO error!\n");
		exit(EXIT_FAILURE);
	}

	if( (fd = open(FIFO,O_RDWR,0)) < 0){
		fprintf(stderr,"open FIFO error!\n");
		exit(EXIT_FAILURE);
	}

	if( argc == 1){
		fprintf(stderr,"Please input something!\n");
		exit(EXIT_FAILURE);
	}
	strcpy(buffer,argv[1]);

	if( write(fd,buffer,100) < 0){
		fprintf(stderr,"write error\n");
		exit(EXIT_FAILURE);
	}
	close(FIFO);

	return 0;
}
