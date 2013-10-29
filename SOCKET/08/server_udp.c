#include<stdio.h>
#include<stdlib.h>
#include<strings.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<errno.h>
int main(void)
{
	int		sockfd;
	struct sockaddr_in 	serveraddr, clientaddr;

	if((sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0){
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
	dg_echo(sockfd, (struct sockaddr*)&clientaddr, sizeof(clientaddr));
}

