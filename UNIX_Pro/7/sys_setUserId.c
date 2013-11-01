#include<stdio.h>
#include<stdlib.h>
int main(int argc, char **argv)
{
	int status;

	if(argc < 2){
		perror("command-line argement requied");
		exit(EXIT_FAILURE);
	}

	if((status = system(argv[1])) < 0){
		perror("system() error");
		exit(EXIT_FAILURE);
	}

	printf("status is %d\n",status);
	exit(EXIT_SUCCESS);
}
