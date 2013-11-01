#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<errno.h>
#include<math.h>

int main(void){
	pid_t child;

	if( (child = fork()) == -1){
		printf("create pid Error: %s \n",strerror(errno));
		exit(EXIT_FAILURE);
	}else if(child == 0){
		printf("I am the child : %d\n",getpid());
		sleep(1);
		printf("child again!\n");
		exit(0);
	}else {
		//wait(NULL);
		printf("I am the father : %d\n",getpid());
		return 0;
	}
}
