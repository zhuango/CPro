#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>

int main(int argc,char *argv[])
{
	int val;

	if(argc != 2){
		printf("Usage: %s <descriptor#>\n",argv[0]);
		exit(EXIT_FAILURE);
	}

	if((val = fcntl(atoi(argv[1]), F_GETFL, 0)) < 0){
		perror("fcntl error");
		exit(EXIT_FAILURE);
	}

	switch(val & O_ACCMODE){
		case O_RDONLY:
			printf("read only");
			break;
		case O_WRONLY:
			printf("write only");
			break;
		case O_RDWR:
			printf("read and write");
			break;
		default:
			printf("unknow file mode");
			break;
	}

	if(val & O_APPEND)
		printf(", append");
	if(val & O_NONBLOCK)
		printf(", nonblock");
#if defined(O_SYNC)
	if(val & O_SYNC)
		printf(", synchronous writes");
#endif

#if !defined(_POSIX_C_SOURCE) && defined(O_FSYNC)
	if(val & O_FSYNC)
		printf(", synchronous writes");
#endif
	putchar('\n');

	exit(EXIT_SUCCESS);
}
