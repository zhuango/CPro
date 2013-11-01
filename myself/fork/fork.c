#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<stdlib.h>
#include<errno.h>
#include<math.h>
#include<stdio.h>

int main(void)
{
	pid_t child;

	if( ( child = fork() ) == -1){
		printf("Fork Errot : %s \n",strerror(errno));
		exit(1);
	}else{
		if(child == 0){
			printf("I am the child : %d \n",getpid());
			exit(0);
		}else{
			printf("I am the father : %d I have a child : %d \n",getpid() , child);
			exit(EXIT_FAILURE);
		}
	}

	return 0;
}
