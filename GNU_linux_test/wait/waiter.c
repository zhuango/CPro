#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<stdio.h>
#include<stdlib.h>

int main(void)
{
	pid_t child;
	int status;

	if( (child = fork()) == -1){
		perror("fork");
		exit(EXIT_FAILURE);
	}else if( child == 0){
		puts("in child");
		printf("\t child pid = %d\n",getpid());
		printf("\t child ppid = %d\n",getppid());
		sleep(2);
		exit(EXIT_SUCCESS);
	}else{
		//waitpid(child,&status,0);
		puts("in parent");
		printf("\tparent pid = %d\n",getpid());
		printf("\tparent ppid = %d\n",getppid());
		waitpid(child,&status,0);
		printf("\tchild exited with %d\n",status);
	}

	exit(EXIT_SUCCESS);
}
