#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<errno.h>
#include<string.h>


int main(void){
	int pipe_fd[2];
	pid_t child;
	char buf[100];
	int r_num;

	memset(buf,0,sizeof(buf));

	if(pipe(pipe_fd) < 0){
		printf("pipe create error\n");
		return -1;
	}

	if( ( child = fork() ) < 0){
		printf("create child pid Error: %s",strerror(errno));
		exit(EXIT_FAILURE);
	}else if(child == 0){
		printf("\n");
		close(pipe_fd[0]);
		if( ( r_num = write(pipe_fd[1] ,"I like",6) ) < 0){
			printf("write error\n");
			exit(EXIT_FAILURE);
		}
		if( ( r_num = write(pipe_fd[1] ,"linux",5) ) <0){
			printf("write error\n");
			exit(EXIT_FAILURE);
		}
		close(pipe_fd[1]);
		waitpid(child,NULL,0);
		exit(0);
	}else {
		close(pipe_fd[1]);
		sleep(1);
		if( ( r_num = read(pipe_fd[0],buf,100) ) >0 ){
			printf("%d number read from the is: %s\n",r_num,buf);
		}
		close(pipe_fd[0]);
		exit(0);
	}
}

