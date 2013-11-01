#include<unistd.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<string.h>

void print_line(int n);

int main(void)
{
	int fd;

	print_line(1);
	print_line(2);
	print_line(3);

	if( (fd = open("junk.out",O_WRONLY | O_CREAT  ,0666)) < 0){
		perror("open");
		exit(EXIT_FAILURE);
	}

	if( (dup2(fd,STDOUT_FILENO)) < 0){
		perror("dup2");
		exit(EXIT_FAILURE);
	}

	print_line(4);
	print_line(5);
	print_line(6);

	close(fd);
	close(STDOUT_FILENO);

	exit(EXIT_SUCCESS);
}

void print_line(int n)
{
	char buf[80];

	snprintf(buf,sizeof(buf),"Line #%d\n",n);
	write(STDOUT_FILENO,buf,strlen(buf));
}
