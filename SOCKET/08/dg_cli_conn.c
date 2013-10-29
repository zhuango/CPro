#include<stdio.h>
#include<stdlib.h>
#include<netinet/in.h>
#include<string.h>

#define MAXLINE 1024

dg_cli(FILE *fp, int sockfd,  struct sockaddr * serveraddr, socklen_t servern)
{
	char buf[MAXLINE], recv[MAXLINE + 1];
//	struct sockaddr *server;
	int n, socklen;;
//	server = malloc(sizeof(struct sockaddr));
//	if(server == NULL){
//		printf("malloc error\n");
//		exit(EXIT_FAILURE);
//	}
	if(connect(sockfd, (struct sockaddr*)serveraddr, servern) < 0){
		perror("connect");
		exit(EXIT_FAILURE);
	}
	while(fgets(buf, MAXLINE, fp) != NULL){
//		if(sendto(sockfd, buf, strlen(buf), 0, serveraddr, servern) < 0){
//			perror("sendto");
//			exit(EXIT_FAILURE);
//		}
		if(write(sockfd, buf, strlen(buf)) < 0){
			perror("write");
			exit(EXIT_FAILURE);
		}
//		socklen = servern;
//		if((n = recvfrom(sockfd, buf, MAXLINE, 0, server, &socklen)) < 0){
//			perror("recvmesg");
//			exit(EXIT_FAILURE);
//		}else if(socklen != servern || memcmp(serveraddr, server, socklen) != 0){
//			printf("dsf\n");
//			continue;
//		}
		if((n = read(sockfd, recv, MAXLINE)) < 0){
			perror("read");
			exit(EXIT_FAILURE);
		}

		recv[n] = 0;
		fputs(recv, stdout);
	}
}
