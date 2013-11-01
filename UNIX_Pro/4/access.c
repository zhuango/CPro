#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>

int main(int argc, char **argv)
{

	/* input error */
	if(argc != 2){
		puts("Usage: access FILENAME");
		exit(EXIT_FAILURE);
	}

	/* exist? */
	if(access(argv[1], F_OK) < 0){
		perror("access");
	}else
		printf("file exist\n");

	/* can be read? */
	if(access(argv[1], R_OK) < 0){
		perror("access");
	}else
		printf("This file can be read\n");

	/* can be write? */
	if(access(argv[1], W_OK) < 0){
		perror("access");
	}else
		printf("This file can be write\n");

	/* can be execute? */
	if(access(argv[1], X_OK) < 0){
		perror("aeecss");
	}else
		printf("This file can execute!\n");

	if(open(argv[1], O_RDONLY) < 0){
		perror("read");
		exit(EXIT_FAILURE);
	}else
		printf("open OK!\n");
	
	exit(EXIT_SUCCESS);
}
