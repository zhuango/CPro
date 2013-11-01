#include<stdio.h>
#include<stdlib.h>
#include<netinet/in.h>
#include<sys/socket.h>
#include<netdb.h>
#include<strings.h>
#include"sock_ntop_host.c"
#include"tcp_connect.c"
#define MAXLINE 1024


int main(int argc, char **argv)
{
	int sockfd, n;
	struct sockaddr_storage ss;
	char recvline[MAXLINE + 1];
	socklen_t len;

	if(argc != 3){
		printf("Usage: %s <hostname> <port>\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	sockfd = tcp_connect(argv[1], argv[2]);

	if(getpeername(sockfd, (struct sockaddr *)&ss, &len) != 0){
		perror("getpeername");
		exit(EXIT_FAILURE);
	}

	printf("connect to %s\n", sock_ntop_host((struct sockaddr *)&ss, len));

	while((n = read(sockfd, recvline, MAXLINE)) > 0){
		recvline[n] = 0;
		fputs(recvline, stdout);
	}

	exit(EXIT_FAILURE);
}
