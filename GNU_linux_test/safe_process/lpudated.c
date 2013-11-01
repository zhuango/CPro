#include<sys/types.h>
#include<sys/stat.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<fcntl.h>
#include<errno.h>
#include<unistd.h>
#include<time.h>
#include<syslog.h>

int main(void)
{
	pid_t pid,sid;
	time_t timebuf;
	int fd,len;

	pid = fork();

	if(pid < 0){
		perror("fork");
		exit(EXIT_FAILURE);
	}

	/*father gone*/
	if(pid > 0){
		exit(EXIT_SUCCESS);
	}

	if( (sid = setsid()) < 0){
		perror("setsid");
		exit(EXIT_FAILURE);
	}

	if( (chdir("/")) < 0){
		perror("chdir");
		exit(EXIT_FAILURE);
	}

	umask(0);

	close(STDIN_FILENO);
	close(STDOUT_FILENO);
	close(STDERR_FILENO);

	len = strlen(ctime(&timebuf));
	while(1){
		char *buf = malloc(sizeof(char) * (len+1));

		if(buf == NULL){
			perror("malloc");
			exit(EXIT_FAILURE);
		}

		if( (fd = open("/var/log/lpudated.log",O_CREAT | O_WRONLY | O_APPEND, 0666)) < 0){
			perror("open");
			exit(EXIT_FAILURE);
		}
		time(&timebuf);
		strncpy(buf,ctime(&timebuf),len + 1);
		write(fd,buf,len + 1);
		close(fd);
		sleep(60);
	}
	exit(EXIT_SUCCESS);
}
