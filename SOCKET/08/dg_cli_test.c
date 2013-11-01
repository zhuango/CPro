#include<stdio.h>
#include<stdlib.h>
#include<sys/socket.h>

#define NUM		2000
#define SIZE 	1400

void dg_cli(FILE *fp, int sockfd, struct sockaddr* serveraddr, socklen_t servern){
	int i;
	char sendline[SIZE];
	for(i = 0; i < NUM; i++){
		if(sendto(sockfd, sendline, SIZE, 0, serveraddr, servern) < 0){
			perror("sendto");
			exit(EXIT_FAILURE);
		}
	}
}
