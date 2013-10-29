#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>

int main(int argc, char *argv[])
{
	if(argc != 2){
		printf("Usage: %s <pathname>\n",argv[0]);
		exit(EXIT_FAILURE);
	}
	if(access(argv[1],R_OK) < 0){
		perror("access error ");
		exit(EXIT_FAILURE);
	}else
		printf("read access OK\n");
	if(open(argv[1],O_RDONLY) < 0){
		perror("open error");
		exit(EXIT_FAILURE);
	}else
		printf("open for reading\n");

	exit(0);
}
