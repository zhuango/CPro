#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>
#include<netinet/in.h>
#include<sys/socket.h>

#define NAME_MAX 512
#define MAXLINE 1024

void file_deal(int sockfd, struct sockaddr * clientaddr, socklen_t clientn)
{
	char filename[NAME_MAX];
	char file[MAXLINE];
	int fd;
	int n;

	
	/* read file name from client */
	if((n = readline(sockfd, filename, NAME_MAX)) < 0){
		printf("readline");
		exit(EXIT_FAILURE);
	}
	/* open the file for reading */
	filename[n - 1] = 0;
	printf("file: %s\n", filename);
	if((fd = open(filename, O_RDONLY, 0)) < 0){
		perror("open");
		exit(EXIT_FAILURE);
	}

	/* read file and send to client */
	while(1){
		if((n = read(fd, file, MAXLINE)) < 0){
			perror("read");
			exit(EXIT_FAILURE);
		}
		
		if(n == 0) break;
		/* write to client */
		file[n] = 0;
		if(write(sockfd, file, n) < 0){
			perror("write");
			exit(EXIT_FAILURE);
		}
	}
}
