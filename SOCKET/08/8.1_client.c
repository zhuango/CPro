#include<stdio.h>
#include<stdlib.h>
#include<netinet/in.h>
#include<strings.h>
#include<sys/socket.h>

int main(int argc, char *argv[])
{
	int sockfd, tcpfd;
	struct sockaddr_in serveraddr;

	if(argc != 2){
		printf("Usage: %s <IPAddress>\n", argv[0]);
		exit(EXIT_FAILURE);
	}
/*
	if((sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0){
		perror("socket");
		exit(EXIT_FAILURE);
	}
*/
	if((tcpfd = socket(AF_INET, SOCK_STREAM, 0)) < 0){
		perror("socket");
		exit(EXIT_FAILURE);
	}

	bzero(&serveraddr, sizeof(serveraddr));
	serveraddr.sin_family = AF_INET;
	serveraddr.sin_port = htons(9877);

	if(inet_pton(AF_INET, argv[1], &serveraddr.sin_addr) < 0){
		perror("inet_ntop");
		exit(EXIT_FAILURE);
	}
/*
	if(sendto(sockfd, "Og", 2, 0, (struct sockaddrr*)&serveraddr, sizeof(serveraddr)) < 0){
		perror("sendto");
		exit(EXIT_FAILURE);
	}
	if(sendto(sockfd, "Liu", 3, 0, (struct sockaddrr*)&serveraddr, sizeof(serveraddr)) < 0){
		perror("sendto");
		exit(EXIT_FAILURE);
	}
*/
	if(connect(tcpfd, (struct sockaddr*)&serveraddr, sizeof(serveraddr)) < 0){
		perror("connect");
		exit(EXIT_FAILURE);
	}
	if(write(tcpfd, "Og", 3) < 0){
		perror("write");
		exit(EXIT_FAILURE);
	}
	if(write(tcpfd, "Ogl", 3) < 0){
		perror("write");
		exit(EXIT_FAILURE);
	}
	exit(EXIT_FAILURE);
}
