#include<stdio.h>
#include<stdlib.h>
#include<errno.h>
#include<string.h>
#include"../03/rdwrn.c"
#include"../03/readline2.c"
#define MAXLINE 1024
void str_echo(int connfd)
{
	ssize_t n;
	long arg1, arg2;
	char buf[MAXLINE];
again:
	while((n = readline(connfd, buf, MAXLINE)) > 0){
		if(sscanf(buf, "%ld %ld", &arg1, &arg2) == 2){
			snprintf(buf, sizeof(buf), "%ld\n", arg1 + arg2);
		}else {
			snprintf(buf, sizeof(buf), "input error\n");
		}
		n = strlen(buf);
		if(writen(connfd, buf, n) < 0){
			perror("write");
			exit(EXIT_FAILURE);
		}
	}
	if(n < 0 && errno == EINTR)
		goto again;
		else if(n < 0){
			perror("read");
			exit(EXIT_FAILURE);
		}
}
