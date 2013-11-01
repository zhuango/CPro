#include<stdio.h>
#include<sys/wait.h>
#include<stdlib.h>

int main(void)
{
	int status;

	if((status = system("date")) < 0){
		perror("system() error");
		exit(EXIT_FAILURE);
	}

	printf("exit status %d\n",status);
	if((status = system("nosuchcommand")) < 0){
		perror("system() error");
		exit(EXIT_FAILURE);
	}
	printf("exit status %d\n",status);
	if((status = system("who; exit 44")) < 0){
		perror("system() error");
		exit(EXIT_FAILURE);
	}
	printf("exit status %d\n",status);

	exit(EXIT_SUCCESS);
}
