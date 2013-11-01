#include<netinet/in.h>/* for the sockaddr_in ,AF_INET ,SOCK_STREAM*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAXLINE 4096

int main(int argc, char *argv[])
{
	int sockfd, n;
	char recvline[MAXLINE + 1];
	struct sockaddr_in servaddr;

	if(argc != 2){
		puts("Usage: a.out <IPaddress>");
		exit(EXIT_FAILURE);
	}

	/* create a socket */
	if((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0){
		perror("socket");
		exit(EXIT_FAILURE);
	}

	/* clear the socket address struct */
	bzero(&servaddr, sizeof(servaddr));
	servaddr.sin_family = AF_INET;/* set the family */
	servaddr.sin_port = htons(9999);/* set the port number */

	/* set the command line arg to the suitable like */
	if(inet_pton(AF_INET, argv[1], &servaddr.sin_addr) <= 0){
		perror("inet_pton error");
		exit(EXIT_FAILURE);
	}

	/* connect the server, the server address is in the struct that named servaddr */
	if(connect(sockfd, (struct sockaddr *) &servaddr, sizeof(servaddr)) < 0){
		perror("connect");
		exit(EXIT_FAILURE);
	}

	/* read the info from sockfd that bind to the server */
	while((n = read(sockfd, recvline, MAXLINE)) > 0){
		recvline[n] = 0;/*set the end of a string*/
		if(fputs(recvline, stdout) == EOF){/* print the time */
			perror("fouts");
			exit(EXIT_FAILURE);
		}

		/* error of read */
		if(n < 0){
			perror("read");
			exit(EXIT_FAILURE);
		}
		if(write(sockfd, "LJ\n", 3) < 0){
			perror("write");
			exit(EXIT_FAILURE);
		}
	}

	exit(EXIT_SUCCESS);
}
