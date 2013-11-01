#include<sys/types.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define N 12

int main(void){
	pid_t pid;
	int fd[2];
	char buffer[N];


	memset(buffer,0,10);

	if( pipe(fd) == -1){
		fprintf(stderr,"create pipe failed!\n");
		exit(EXIT_FAILURE);
	}

	if( (pid = fork() ) == -1){
		fprintf(stderr,"create process failed!\n");
		exit(EXIT_FAILURE);
	}else if(pid == 0){
		close(fd[1]);

		sleep(1);
		if(read(fd[0],buffer,N) == -1){
			fprintf(stderr,"read error!\n");
			exit(EXIT_FAILURE);
		}
		close(fd[0]);
		printf("child read from father : %s\n",buffer);

	}else if(pid > 0){
		close(fd[0]);

		if(write(fd[1],"Hello ",6) == -1){
			printf("write error!\n");
			exit(EXIT_FAILURE);
		}
		if(write(fd[1],"child!",6) == -1){
			printf("write error!\n");
			exit(EXIT_FAILURE);
		}
		close(fd[1]);
		waitpid(pid,NULL,0);
	}

	return 0;
}
