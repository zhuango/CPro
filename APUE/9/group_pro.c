#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main(void)
{
	pid_t pid,pid2;

	printf("parent ID is :%d\n", getpid());
	if((pid = fork()) < 0){/* the first child */
		perror("fork1");
		exit(EXIT_FAILURE);
	}else if(pid == 0){
		printf("child 1 ID is :%d\n", getpid());
		printf("child1's parent ID is :%d\n", getppid());
		/* print the process group ID */
		printf("process group ID of child 1:%d\n", getpgrp());
		exit(EXIT_SUCCESS);
	}
	if((pid2 = fork()) < 0){/* the second child */
		perror("fork1");
		exit(EXIT_FAILURE);
	}else if(pid2 == 0){
		printf("child 2 ID is :%d\n", getpid());
		printf("child 2's parent ID is :%d\n", getppid());
		/* print the process group ID */
		printf("process group ID of child 2:%d\n", getpgrp());
		exit(EXIT_SUCCESS);
	}
	if((pid2 = fork()) < 0){/* the third child */
		perror("fork1");
		exit(EXIT_FAILURE);
	}else if(pid2 == 0){
		printf("child 3 ID is :%d\n", getpid());
		printf("child 3's parent ID is :%d\n", getppid());
		/* print the process group ID */
		printf("process group ID of child 2:%d\n", getpgrp());
		exit(EXIT_SUCCESS);
	}


	return 0;
}
