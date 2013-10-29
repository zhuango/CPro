#include<stdio.h>
#include<stdlib.h>
#include<netinet/in.h>
#include<string.h>

#define MAXLINE 1024

dg_cli(FILE *fp, int sockfd,  struct sockaddr * serveraddr, socklen_t servern)
{
	char buf[MAXLINE];
	struct sockaddr *server;
	int n, socklen;;
	server = malloc(sizeof(struct sockaddr));
	if(server == NULL){
		printf("malloc error\n");
		exit(EXIT_FAILURE);
	}
	while(fgets(buf, MAXLINE, fp) != NULL){
		if(sendto(sockfd, buf, strlen(buf), 0, serveraddr, servern) < 0){
			perror("sendto");
			exit(EXIT_FAILURE);
		}
		socklen = servern;
		if((n = recvfrom(sockfd, buf, MAXLINE, 0, server, &socklen)) < 0){
			perror("recvmesg");
			exit(EXIT_FAILURE);
		}else if(socklen != servern || memcmp(serveraddr, server, socklen) != 0){
			printf("dsf\n");
			continue;
		}

		buf[n] = 0;
		fputs(buf, stdout);
	}
}
