#include<stdio.h>
#include<stdlib.h>
#include<signal.h>

#define DELAY 5
int count = 0;

int main(int argc, char **argv)
{
	int newpid;
	int task_count;
	int i;

	void child_code(), del_signal();


	if(argc != 2){
		printf("Usage: waitdemo2 num_fork\n");
		exit(0);
	}

	signal(SIGCHLD, del_signal);

	for(task_count = 0; task_count < atoi(argv[1]); task_count++){
		
		if((newpid = fork()) == -1)
			perror("fork");
		else if(newpid == 0)
			child_code(DELAY);

	}
	while(count != atoi(argv[1])){
		sleep(1);
		printf("waiting ...\n");
	}

	return 0;
}

void child_code(int delay)
{
	printf("here is child %d\n",getpid());
	sleep(delay);
	printf(" child %d done!\n",getpid());
	exit(17);
}

void del_signal()
{
	
	int wait_rv;
	int child_status;
	int high_8, low_7, bit_7;
    wait_rv = wait(&child_status);

    printf("Wait retuened : %d\n", wait_rv);
	high_8 = child_status >> 8;
	low_7  = child_status & 0x7f;
	bit_7  = child_status & 0x80;
	count++;

	printf("status: exit = %d, sig = %d, core = %d\n",high_8, low_7, bit_7);
}

