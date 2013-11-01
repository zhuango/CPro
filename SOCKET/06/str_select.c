#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"../03/readline2.c"
#include"../03/rdwrn.c"
#include<sys/select.h>
#include<sys/time.h>
#define MAXLINE 1024
int max(int a, int b)
{
	if(a > b)
		return a;
	else return b;
}
void str_cli(FILE *fp, int sockfd)
{
	int maxfd;
	fd_set rset;
	char sendline[MAXLINE], recvline[MAXLINE];

	FD_ZERO(&rset);/* clear the direc */
	for(;;){
		FD_SET(fileno(fp), &rset);/* set the fp and sockfd*/
		FD_SET(sockfd, &rset);
		maxfd = max(fileno(fp), sockfd) + 1;/* max number select should wait */

		if(select(maxfd, &rset, NULL, NULL, NULL) < 0){/* wait for the fd */
			perror("select");
			exit(EXIT_FAILURE);
		}
		if(FD_ISSET(sockfd, &rset)){/* sockfd is ready */
			if(readline(sockfd, recvline, MAXLINE) == 0){/* read from server */
				printf("str_lic: server terminated prematurely\n");
				exit(EXIT_FAILURE);
			}
			fputs(recvline, stdout);
		}
		
		if(FD_ISSET(fileno(fp), &rset)){/* fp is ready */
			if(fgets(sendline, MAXLINE, fp) == NULL)/* input */
				return ;
			if(writen(sockfd, sendline, strlen(sendline)) < 0){/* send what you input */
				perror("writen");
				exit(EXIT_FAILURE);
			}
		}
	}
}
