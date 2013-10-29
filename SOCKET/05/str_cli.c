#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<signal.h>
#include"../03/readline2.c"
#include"../03/rdwrn.c"
#define MAXLINE 1024
void sig_pipe(int);

void str_cli(FILE *fp, int sockfd)
{
	char sendline[MAXLINE], recvline[MAXLINE];
	if(signal(SIGPIPE, sig_pipe) < 0){
		perror("signal");
		exit(EXIT_FAILURE);
	}
	while(fgets(sendline, MAXLINE, fp) != NULL){
		if(writen(sockfd, sendline, strlen(sendline)) < 0){
			perror("writen");
			exit(EXIT_FAILURE);
		}

		if(readline(sockfd, recvline, MAXLINE) == 0){
			printf("str_lic: server terminated prematurely\n");
			exit(EXIT_FAILURE);
		}

		fputs(recvline, stdout);
	}
}

void sig_pipe(int num)
{
	perror("SIGPIPE");
	printf("You bicth!\n");
	exit(EXIT_FAILURE);
}
