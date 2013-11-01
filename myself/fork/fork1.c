#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<unistd.h>
#include<sys/wait.h>
#include<errno.h>

int main(void){
	pid_t pid;

	if((pid = fork()) == -1){
		fprintf(stderr,"create process failed!\n");
	}else if(pid == 0){
		printf("Child: %d \n",getpid());
	}else if( pid ){
		printf("father: %d \n",getpid());
	}

	return 0;
}
