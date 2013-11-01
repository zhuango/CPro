#include<stdio.h>
#include<stdlib.h>
#include<errno.h>
#include<fcntl.h>
#include<unistd.h>

char buff[500000];
void set_fl(int , int);
void clr_fl(int , int);
int main(void)
{
	int ntowrite, nwrite;
	char *ptr;

	ntowrite = read(STDIN_FILENO, buff, sizeof(buff));
	fprintf(stderr, "read %d bytes\n", ntowrite);

	set_fl(STDOUT_FILENO, O_NONBLOCK);

	ptr = buff;
	while(ntowrite > 0){
		errno = 0;
		nwrite = write(STDOUT_FILENO, ptr, ntowrite);
		fprintf(stderr, "nwrite = %d, errno = %d\n", nwrite, errno);

		if(nwrite > 0){
			ptr += nwrite;
			ntowrite -= nwrite;
		}
	}

	clr_fl(STDOUT_FILENO, O_NONBLOCK);

	exit(EXIT_SUCCESS);
}

void set_fl(int fd, int flag)
{
	int val;
	if((val = fcntl(fd, F_GETFL, 0)) < 0){
		perror("fcntl");
		exit(EXIT_FAILURE);
	}
	val |= flag;

	if(fcntl(fd, F_SETFL, val) < 0){
		perror("fcntl set_fl");
		exit(EXIT_FAILURE);
	}
}
void clr_fl(int fd, int flag)
{
	int val;
	if((val = fcntl(fd, F_GETFL, 0)) < 0){
		perror("fcntl");
		exit(EXIT_FAILURE);
	}

	val &= (~flag);

	if(fcntl(fd, F_SETFL, val) < 0){
		perror("clr_fl");
		exit(EXIT_FAILURE);
	}
}
