#include<stdio.h>
#include<stdlib.h>
#include<sys/socket.h>
#include<signal.h>
void echo_count(int num);
#define MAXLINE 1024
int count = 0;
void dg_echo(int sockfd, struct sockaddr* clientaddr, socklen_t clientn)
{
	int 	n;
	socklen_t len;
	char mesg[MAXLINE];

	if(signal(SIGINT, echo_count) < 0){
		perror("signal");
		exit(EXIT_FAILURE);
	}
	for(;;){
		len = clientn;
		if((n = recvfrom(sockfd, mesg, MAXLINE, 0, clientaddr, &len)) < 0){
			perror("recvfrom");
			exit(EXIT_FAILURE);
		}

//		if(sendto(sockfd, mesg, n, 0, clientaddr, len) < 0){
//			perror("sendto");
//			exit(EXIT_FAILURE);
//		}
		count ++;
	}
}

void echo_count(int num)
{
	printf("\nrecv : %d\n", count);
	exit(EXIT_SUCCESS);
}
