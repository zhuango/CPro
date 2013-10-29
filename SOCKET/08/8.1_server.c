#include<stdio.h>
#include<stdlib.h>
#include<netinet/in.h>
#include<sys/socket.h>
#include<strings.h>

#define MAXLINE 1024

int max(int a, int b)
{
	if(a > b)
		return a;
	else
		return b;
}
int main(void)
{
	int 	sockfd, tcpfd, len, n, maxfd, connfd, no = 1;
	fd_set 	rset;
	struct sockaddr_in 	serveraddr, clientaddr;
	char mesg[MAXLINE];
	/* UDP */
/*	if((sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0){
		perror("socket");
		exit(EXIT_FAILURE);
	}

	bzero(&serveraddr, sizeof(serveraddr));
	serveraddr.sin_family = AF_INET;
	serveraddr.sin_addr.s_addr = htonl(INADDR_ANY);
	serveraddr.sin_port = htons(9877);
	
	if(bind(sockfd, (struct sockaddr*)&serveraddr, sizeof(serveraddr)) < 0){
		perror("bind");
		exit(EXIT_FAILURE);
	}
*/
	/* TCP */
//	if(setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &no, sizeof(no)) < 0){
//		perror("setsockopt");
//		exit(EXIT_FAILURE);
//	}

	if((tcpfd = socket(AF_INET, SOCK_STREAM, 0)) < 0){
		perror("socket");
		exit(EXIT_FAILURE);
	}

	bzero(&serveraddr, sizeof(serveraddr));
	serveraddr.sin_family = AF_INET;
	serveraddr.sin_addr.s_addr = htonl(INADDR_ANY);
	serveraddr.sin_port = htons(9877);
	if(bind(tcpfd, (struct sockaddr*)&serveraddr, sizeof(serveraddr)) < 0){
		perror("bind");
		exit(EXIT_FAILURE);
	}
	if(listen(tcpfd, 5) < 0){
		perror("listenfd");
		exit(EXIT_FAILURE);
	}

/*	FD_ZERO(&rset);
	maxfd = max(tcpfd, sockfd) + 1;
	FD_SET(sockfd, &rset);
	FD_SET(tcpfd, &rset);
	if(select(maxfd, &rset, NULL, NULL, NULL) < 0){
		perror("select");
		exit(EXIT_FAILURE);
	}
*/

/*	if(FD_ISSET(sockfd, &rset)){
		len = sizeof(clientaddr);
		sleep(5);
		printf("recving...\n");
	
		if((n = recvfrom(sockfd, mesg, MAXLINE, 0, (struct sockaddr*)&clientaddr, &len)) < 0){
			perror("recvfrom");
			exit(EXIT_FAILURE);
		}
	}
*/
//	if(FD_ISSET(tcpfd, &rset)){
		len = sizeof(clientaddr);
		if((connfd = accept(tcpfd, (struct sockaddr*)&clientaddr, &len)) < 0){
			perror("accept");
			exit(EXIT_FAILURE);
		}
		sleep(10);
		if((n = read(connfd, mesg, MAXLINE)) < 0){
			perror("read");
			exit(EXIT_FAILURE);
		}
//	}

	mesg[n] = 0;
	printf("%s\n", mesg);
	

	exit(EXIT_FAILURE);
}
