#include<stdio.h>
#include<stdlib.h>

#define DELAY 2

int main(int argc, char **argv)
{
	int newpid;
	int i;
	void child_code(int);
	void parent_code(int);

	if(argc != 2){
		printf("Usage: waitdemo_l number_of_fork\n");
		exit(0);
	}

	for(i = 0; i < atoi(argv[1]); i++){
		if((newpid = fork()) == -1){
			perror("fork");
			exit(0);
		}else if(newpid == 0)
			child_code(DELAY);
		else 
			parent_code(newpid);
	}

	return 0;
}

void child_code(int delay)
{
	printf("child %d here, I will sleep for %d seconds\n",getpid(), delay);
	sleep(delay);
	exit(0);
}

void parent_code(int childpid)
{
	int wait_rc;
	wait_rc = wait(NULL);
	printf("father %d here, waiting for the child %d \n", childpid, wait_rc);
}
