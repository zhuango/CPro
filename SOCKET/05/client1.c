#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<netinet/in.h>
#include<sys/socket.h>
#include<strings.h>

int main(int argc, char *argv[])
{
	int sockfd, i;
	struct sockaddr_in serveraddr;

	if(argc != 2){
		printf("Usage: %s <IPaddress>\n", argv[0]);
		exit(127);
	}
	if((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0){
		perror("socket");
		exit(EXIT_FAILURE);
	}
	bzero(&serveraddr, 0);
	serveraddr.sin_family = AF_INET;
	serveraddr.sin_port = htons(9877);
<<<<<<< HEAD
=======
	
>>>>>>> b377d5b6d37e1e0791c3b0af7035f3dc99c42dd4
	if(inet_pton(AF_INET, argv[1], &serveraddr.sin_addr) < 0){
		perror("inet_pton");
		exit(EXIT_FAILURE);
	}

	if(connect(sockfd, (struct sockaddr*)&serveraddr, sizeof(serveraddr)) < 0){
		perror("connect");
		exit(EXIT_FAILURE);
	}
<<<<<<< HEAD
=======

>>>>>>> b377d5b6d37e1e0791c3b0af7035f3dc99c42dd4
	str_cli(stdin, sockfd);

	if(close(sockfd) < 0){
		perror("close");
		exit(EXIT_FAILURE);
	}
}
