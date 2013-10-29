#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<errno.h>

#define FIFO_SERVER "/tmp/myfifo"

int main(int argc, char **argv){
	int fd;
	char buf[100];
	int nwrite;

	if( (mkfifo(FIFO_SERVER, O_CREAT | O_EXCL | O_RDWR) < 0) && (errno != EEXIST)){
		printf("cannot create fifoserver\n");
	}

	if ( ( fd = open(FIFO_SERVER,O_RDWR | O_NONBLOCK,0) ) < 0){
		perror("open");
		exit(1);
	}

	if( argc < 2) {
		printf("Please send something!\n");
		exit(-1);
	}

	strcpy(buf,argv[1]);

	if ( ( nwrite = write(fd,buf,100) ) == -1){
		if(errno == EAGAIN)
			printf("the FIFO has not been read yet ,Please try later\n");
	}else{
		printf("write %s to FIFO\n",buf);
	}

	close(fd);

	return 0;
}
