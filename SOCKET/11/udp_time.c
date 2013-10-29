#include<stdio.h>
#include<sys/socket.h>
#include<stdlib.h>
#include<netinet/in.h>
#include<strings.h>
#include<string.h>
#define MAXLINE 1024
#include"sock_ntop_host.c"
#include"udp_client.c"

int main(int argc, char **argv)
{
	int sockfd;
	int n, len;
	char recvline[MAXLINE];
	struct sockaddr *serveraddr;

	if(argc != 3){
		printf("Usage:%s <hostname> <servername>\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	sockfd = udp_client(argv[1], argv[2], &serveraddr, &len);

	printf("Sending to %s\n", sock_ntop_host(serveraddr, len));

	if(sendto(sockfd, "", 1, 0, serveraddr, len) < 0){
		perror("sendto");
		exit(EXIT_FAILURE);
	}

	if((n = recvfrom(sockfd, recvline, MAXLINE, 0, NULL, NULL)) < 0){
		perror("recvfrom");
		exit(EXIT_FAILURE);
	}

	recvline[n] = '\0';

	fputs(recvline, stdout);

	exit(EXIT_SUCCESS);
}
