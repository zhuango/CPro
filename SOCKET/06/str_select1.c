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
	int maxfd, stdeof = 0;
	fd_set rset;
	char sendline[MAXLINE], recvline[MAXLINE];
	int n;

	FD_ZERO(&rset);/* clear the direc */
	for(;;){
		if(stdeof == 0)/* write end is open or not */
			FD_SET(fileno(fp), &rset);
		FD_SET(sockfd, &rset);/* wait the sockfd */
		maxfd = max(fileno(fp), sockfd) + 1;/* max fd wait */

		if(select(maxfd, &rset, NULL, NULL, NULL) < 0){/* wait */
			perror("select");
			exit(EXIT_FAILURE);
		}
		if(FD_ISSET(sockfd, &rset)){/* sockfd is ready */
			if((n = read(sockfd, recvline, MAXLINE)) == 0){/* read info form server*/
				if(stdeof == 1)/* write end is opened already */
					return ;
				else{
					printf("str_lic: server terminated prematurely\n");
					exit(EXIT_FAILURE);
				}
			}
			if(write(fileno(stdout), recvline, n) < 0){/* print back*/
				perror("write");
				exit(EXIT_FAILURE);
			}
		}
		
		if(FD_ISSET(fileno(fp), &rset)){/* fp is ready */
			if((n = read(fileno(fp), sendline, MAXLINE)) == 0){/* input */
				stdeof = 1;/* write done */
				if(shutdown(sockfd, 1) < 0){/* shutdown the write end */
					perror("shutdown");
					exit(EXIT_FAILURE);
				}
				FD_CLR(fileno(fp), &rset);/* do not set the fp again */
				continue;/* go on for the reading */
			}
			if(writen(sockfd, sendline, n) < 0){/* send message */
				perror("writen");
				exit(EXIT_FAILURE);
			}
		}
	}
}
