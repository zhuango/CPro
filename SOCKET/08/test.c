#include<stdio.h>
#include<stdlib.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<strings.h>

int main(void)
{
	int sockfd;
	struct sockaddr_in server;
	
	if((sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0){
		perror("socket");
		exit(EXIT_FAILURE);
	}
	bzero(&server, sizeof(server));
	server.sin_family = AF_INET;
	server.sin_port = htons(44317);
	if(inet_pton(AF_INET, "127.0.0.1", &server.sin_addr) < 0){
		perror("inet_pton");
		exit(EXIT_FAILURE);
	}

	if(sendto(sockfd, "FUCK!", 5, 0, (struct sockaddr*)&server, sizeof(server)) < 0){
		perror("sendto");
		exit(EXIT_FAILURE);
	}

	exit(EXIT_SUCCESS);
}
