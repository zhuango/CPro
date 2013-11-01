#include<stdio.h>
#include<sys/types.h>
#include<stdlib.h>
#include<sys/wait.h>
#include<unistd.h>
#include<errno.h>
#include<math.h>

int main(void){
	pid_t child;

	if( ( child = vfork()) <0){
		printf("Error : %s \n",strerror(errno));
		exit(1);
	}else
		if( child == 0){
			sleep(1);
			printf("I am the child: %d\n",getpid());
			exit(0);
		}else{
			printf(" I am the father : %d I hava a child : %d\n",getpid(),child);
			exit(0);
		}
	return 0;
}
