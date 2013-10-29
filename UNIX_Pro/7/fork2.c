#include<stdio.h>
#include<sys/types.h>
#include<stdlib.h>
#include<sys/wait.h>

int main(void)
{
	pid_t pid;

	if((pid = fork()) < 0){
		perror("fork error");
		exit(EXIT_FAILURE);
	}else if(pid == 0){
//		if((pid = fork()) < 0){
//			perror("fork2 error");
//			exit(EXIT_FAILURE);
//		}else if(pid > 0){
//			exit(EXIT_SUCCESS);
//		}

		sleep(2);
		printf("second child , parent pid = %d\n",getppid());
		exit(EXIT_FAILURE);
	}

//	if(waitpid(pid, NULL, WNOHANG) != pid){//don't ZuSe
	if(waitpid(pid, NULL, 0) != pid){//be ZuSe
	perror("waitpid error");
		exit(EXIT_FAILURE);
	}

	printf("I'm %d\n",getpid());


	exit(EXIT_FAILURE);
}
