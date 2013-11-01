#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>

int glob = 6;
char buf[] = "a write to stdout\n";

int main(void)
{
	int var;
	pid_t pid;

	var = 88;

	if(write(STDOUT_FILENO, buf, sizeof(buf)-1) < sizeof(buf)-1){
		perror("write ");
		exit(EXIT_FAILURE);
	}
	printf("before fork");
	if((pid = fork()) < 0){
		perror("fork");
		exit(EXIT_FAILURE);
	}else if(pid == 0){
		var++;
		glob++;
	}else{
		sleep(2);
	}

	printf("pid = %d, glob = %d, var = %d\n",getpid(),glob,var);
	exit(0);
}
