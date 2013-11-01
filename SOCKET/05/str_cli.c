#include<stdio.h>
#include<stdlib.h>
#include<string.h>
<<<<<<< HEAD
#include"../03/readline2.c"
#include"../03/rdwrn.c"
#define MAXLINE 1024
void str_cli(FILE *fp, int sockfd)
{
	char sendline[MAXLINE], recvline[MAXLINE];

=======
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
>>>>>>> b377d5b6d37e1e0791c3b0af7035f3dc99c42dd4
	while(fgets(sendline, MAXLINE, fp) != NULL){
		if(writen(sockfd, sendline, strlen(sendline)) < 0){
			perror("writen");
			exit(EXIT_FAILURE);
		}
<<<<<<< HEAD
=======

>>>>>>> b377d5b6d37e1e0791c3b0af7035f3dc99c42dd4
		if(readline(sockfd, recvline, MAXLINE) == 0){
			printf("str_lic: server terminated prematurely\n");
			exit(EXIT_FAILURE);
		}

		fputs(recvline, stdout);
	}
}
<<<<<<< HEAD
=======

void sig_pipe(int num)
{
	perror("SIGPIPE");
	printf("You bicth!\n");
	exit(EXIT_FAILURE);
}
>>>>>>> b377d5b6d37e1e0791c3b0af7035f3dc99c42dd4
