#include<netinet/in.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAXLINE 4096

int main(int argc, char *argv[])
{
	int listenfd, connfd;
	struct sockaddr_in serveraddr, clientaddr;
	char now[MAXLINE];
	time_t ticks;
	int n;
	int length_of_clientaddr;

	if((listenfd = socket(AF_INET, SOCK_STREAM, 0)) < 0){
		perror("socket");
		exit(EXIT_FAILURE);
	}
	bzero(&serveraddr, sizeof(serveraddr));
	serveraddr.sin_family = AF_INET;
	serveraddr.sin_addr.s_addr = htonl(INADDR_ANY);
	serveraddr.sin_port = htons(4443);
	
	if(bind(listenfd, (struct sockaddr*)&serveraddr, sizeof(serveraddr)) < 0){
		perror("bind");
		exit(EXIT_FAILURE);
	}
	if(listen(listenfd, 5) < 0){
		perror("listen");
		exit(EXIT_FAILURE);
	}

	while(1){
		length_of_clientaddr = sizeof(struct sockaddr);
		if((connfd = accept(listenfd, (struct sockaddr*)&clientaddr, &length_of_clientaddr)) < 0){
			perror("accept");
			exit(EXIT_FAILURE);
		}
		printf("connection form: %s; port: %d\n",
				inet_ntop(AF_INET, &clientaddr.sin_addr, now, sizeof(now)),
				ntohs(clientaddr.sin_port));
		if(write(connfd, "Fuck You!\n", 11) < 0){
			perror("write");
			exit(EXIT_FAILURE);
		}

		if((n = read(connfd, now, MAXLINE)) < 0){
			perror("read");
			exit(EXIT_FAILURE);
		}
		now[n] = 0;
		printf("%s", now);

		if(close(connfd) < 0){
			perror("close");
			exit(EXIT_FAILURE);
		}
	}
}
