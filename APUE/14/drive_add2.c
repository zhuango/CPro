#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<signal.h>
#define MAXLINE 1024

static void sig_pipe(int);

int main(void)
{
	int n, fd1[2], fd2[2];
	pid_t pid;
	char line[MAXLINE];

	if(signal(SIGPIPE, sig_pipe) == SIG_ERR){
		perror("signale");
		exit(EXIT_FAILURE);
	}
	if(pipe(fd1) < 0 || pipe(fd2) < 0){
		perror("pipe");
		exit(EXIT_FAILURE);
	}
	if((pid = fork()) < 0){
		perror("fork");
		exit(EXIT_FAILURE);
	}else if(pid > 0){/* Parent */
		close(fd1[0]);
		close(fd2[1]);
		while(fgets(line, MAXLINE, stdin) != NULL){
			n = strlen(line);
			if(write(fd1[1], line, n) != n){
				perror("write");
				exit(EXIT_FAILURE);
			}
			if((n = read(fd2[0], line, MAXLINE)) < 0){
					perror("read");
					exit(EXIT_FAILURE);
			}
			if(n == 0){
				printf("Fuck\n");
				break;
			}
			line[n] = 0;
			if(fputs(line, stdout) < 0){
				perror("fputs");
				exit(EXIT_FAILURE);
			}
		}
		if(ferror(stdin)){
			perror("ferror");
			exit(EXIT_FAILURE);
		}
		exit(EXIT_SUCCESS);
	}else{
		close(fd1[1]);
		close(fd2[0]);
		if(fd1[0] != STDIN_FILENO){
			if(dup2(fd1[0], STDIN_FILENO) != STDIN_FILENO){
				perror("dup2");
				exit(EXIT_FAILURE);
			}
			close(fd1[0]);
		}
		if(fd2[1] != STDOUT_FILENO){
			if(dup2(fd2[1], STDOUT_FILENO) != STDOUT_FILENO){
				perror("dup2");
				exit(EXIT_FAILURE);
			}
			close(fd2[1]);
		}
		if(execl("./add2", "add2", (char*)0) < 0){
			perror("execl");
			exit(EXIT_FAILURE);
		}
	}
	exit(EXIT_SUCCESS);
}
/* signo */
static void sig_pipe(int signo)
{
	printf("SIGPIPE caught\n");
	exit(EXIT_SUCCESS);
}

