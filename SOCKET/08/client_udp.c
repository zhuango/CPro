#include<stdio.h>
#include<stdlib.h>
#include<strings.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<errno.h>

int main(int argc, char **argv)
{
	int sockfd;
	struct sockaddr_in serveraddr;

	if(argc != 2){
		printf("Usage: %s <IPaddress>\n", argc);
		exit(EXIT_FAILURE);
	}

	if((sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0){
		perror("socket");
		exit(EXIT_FAILURE);
	}
	bzero(&serveraddr, sizeof(serveraddr));
	serveraddr.sin_family = AF_INET;
	serveraddr.sin_port = htons(9877);
	if(inet_pton(AF_INET, argv[1], &serveraddr.sin_addr) < 0){
		perror("inet_pton");
		exit(EXIT_FAILURE);
	}

	dg_cli(stdin, sockfd, (struct sockaddr*)&serveraddr, sizeof(serveraddr));

	exit(EXIT_SUCCESS);
}
