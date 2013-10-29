#include<stdio.h>
#include<stdlib.h>
#include<strings.h>
#include<string.h>
#include<fcntl.h>
#include<netinet/in.h>
#include<sys/socket.h>

#define PORT	9877
#define NAME_MAX  512
#define MAXLINE 1024

int main(int argc, char **argv)
{
	int sockfd;/* connect  to serevr */
	struct sockaddr_in serveraddr;/* server address */
	char filename[NAME_MAX], file[MAXLINE];/* filename and file  */
	int n, fd;/* read number */

	if(argc != 2){
		printf("Usage: %s <IPaddress>\n", argv[0]);
		exit(EXIT_FAILURE);
	}
	/* create socket */
	if((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0){
		perror("socket");
		exit(EXIT_FAILURE);
	}
	/* set the address struct */
	bzero(&serveraddr, sizeof(serveraddr));
	serveraddr.sin_family = AF_INET;
	serveraddr.sin_port = htons(PORT);
	if(inet_pton(AF_INET, argv[1], &serveraddr.sin_addr.s_addr) == -1){
		perror("inet_pton");
		exit(EXIT_FAILURE);
	}

	/* connect to server */
	if(connect(sockfd, (struct sockaddr*)&serveraddr, sizeof(serveraddr)) < 0){
		perror("connect");
		exit(EXIT_FAILURE);
	}
	/* input the file name */
	printf("file name: ");
	if(fgets(filename, NAME_MAX, stdin) == NULL){
		perror("fgets");
		exit(EXIT_FAILURE);
	}
	/* write to server */
	if(write(sockfd, filename, strlen(filename)) < 0){
		perror("write");
		exit(EXIT_FAILURE);
	}
	filename[strlen(filename) - 1] = 0;
	if((fd = open(filename, O_WRONLY | O_CREAT | O_EXCL, 0644)) < 0){
		perror("open");
		exit(EXIT_FAILURE);
	}
	while(1){
		if((n = read(sockfd, file, MAXLINE)) < 0){
			perror("read");
			exit(EXIT_FAILURE);
		}
		if(n == 0) break;

		file[n] = 0;
		if(write(fd, file, n) < 0){
			perror("write");
			exit(EXIT_FAILURE);
		}
	}

	exit(EXIT_FAILURE);
}
