#include<stdio.h>
#include<stdlib.h>
#include<sys/socket.h>
#define MAXLINE 1024
void dg_echo(int sockfd, struct sockaddr* clientaddr, socklen_t clientn)
{
	int 	n;
	socklen_t len;
	char mesg[MAXLINE];

	for(;;){
		len = clientn;
		if((n = recvfrom(sockfd, mesg, MAXLINE, 0, clientaddr, &len)) < 0){
			perror("recvfrom");
			exit(EXIT_FAILURE);
		}

		if(sendto(sockfd, mesg, n, 0, clientaddr, len) < 0){
			perror("sendto");
			exit(EXIT_FAILURE);
		}
	}
}
