#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<stdlib.h>

int main(void)
{
	int fd;
	int new_fd;
	if((fd = open("test",O_WRONLY)) == -1){
		perror("open");
		exit(EXIT_FAILURE);
	}
	new_fd = fcntl(fd, F_DUPFD,3);

	if(write(new_fd, "HelloWorld\n", 11) == -1){
		perror("write");
		exit(EXIT_FAILURE);
	}

	return 0;
}
