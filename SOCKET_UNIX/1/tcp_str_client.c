#include<stdio.h>
#include<stdlib.h>
#include<netinet/in.h>
#include<fcntl.h>
#include<string.h>

#define CLI_PORT 9877
#define MAXLINE 1024

void str_cli(FILE *fp, int sockfd)
{
	char sendline[MAXLINE], recvline[MAXLINE];

	while(fgets(sendline, MAXLINE, fp) != NULL){
		write(sockfd, sendline, strlen(sendline));

		if(readline(sockfd, recvline, MAXLINE) == 0){
			perror("str_cli: server terminated prematurely");
			exit(EXIT_FAILURE);
		}
		fputs(recvline, stdout);
	}
}

int main(int argc, char **argv)
{
	int sockfd;
	struct sockaddr_in servaddr;


	if((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0){
		perror("socket");
		exit(EXIT_FAILURE);
	}

	bzero(&servaddr, sizeof(servaddr));
	servaddr.sin_family = AF_INET;
	servaddr.sin_port = htons(CLI_PORT);
	if(inet_pton(AF_INET, argv[1], &servaddr.sin_addr) < 0){
		perror("inet_pton");
		exit(EXIT_FAILURE);
	}

	if(connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0){
		perror("connect");
		exit(EXIT_FAILURE);
	}

	str_cli(stdin, sockfd);

	exit(EXIT_SUCCESS);
}

