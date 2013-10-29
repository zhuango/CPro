#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>

int main(void)
{
	int fd;
	int fd_copy;
	char file[10] = "/dev/fd/";
	
	if((fd = open("test",O_RDONLY | O_CREAT,0755)) < 0){
		perror("open error");
		exit(EXIT_FAILURE);
	}

	printf("file: %d\n",fd);
	file[8] = fd+48;
	strcat(file,"\0");
	printf("%s\n",file);

	if(close(fd) < 0){
		perror("close");
		exit(EXIT_FAILURE);
	}

	if((fd_copy = open(file,O_RDONLY)) < 0){
		perror("open /dev/fd/ error");
		exit(EXIT_FAILURE);
	}
	printf("file_copy : %d\n",fd_copy);
	exit(EXIT_FAILURE);
}
