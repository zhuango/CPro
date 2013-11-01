#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<limits.h>

#define BUFSZ PIPE_BUF

void err_quit(char *msg);

int main(int argc, char **argv)
{
	int fd[2];
	int fdin;
	char buf[BUFSZ];

	int pid,len;
	if( (pipe(fd)) < 0)
		err_quit("pipe");

	if( (pid = fork()) < 0){
		err_quit("fork");
		exit(EXIT_FAILURE);
	}

	if( pid == 0){
		close(fd[1]);
		while((len = read(fd[0],buf,BUFSZ)) > 0){
			write(STDOUT_FILENO,buf,len);
		}
			printf("+++++++++++++++++++\n");
		close(fd[0]);
	}else{
		close(fd[0]);

		if( (fdin = open(argv[1],O_RDONLY)) < 0){
			perror("open");
			write(fd[1],"123\n",4);
		}else{
			while(( len = read(fdin,buf,BUFSZ)) > 0)
				write(fd[1],buf,len);
				close(fdin);
		}
		sleep(1);	
		close(fd[1]);
	}
	waitpid(pid,NULL,0);
	exit(EXIT_FAILURE);
}

void err_quit(char *msg)
{
	perror("msg");
	exit(EXIT_FAILURE);
}

