#include<stdio.h>
#include<stdlib.h>
#include<strings.h>
#include<sys/socket.h>
#include<netinet/in.h>

int main(void)
{
	int listenfd, connfd;
	struct sockaddr_in serveraddr, clientaddr;
	socklen_t clientn;
	pid_t pid;

	if((listenfd = socket(AF_INET, SOCK_STREAM, 0)) < 0){
		perror("socket");
		exit(EXIT_FAILURE);
	}

	bzero(&serveraddr, 0);
	serveraddr.sin_family = AF_INET;
	serveraddr.sin_addr.s_addr = htonl(INADDR_ANY);
	serveraddr.sin_port = htons(9877);

	if(bind(listenfd, (struct sockaddr*)&serveraddr, sizeof(serveraddr)) < 0){
		perror("bind");
		exit(EXIT_FAILURE);
	}

	if(listen(listenfd, 5) < 0){
		perror("listen");
		exit(EXIT_FAILURE);
	}
	for(;;){
		clientn = sizeof(clientaddr);
		if((connfd = accept(listenfd, (struct sockaddr*)&clientaddr, &clientn)) < 0){
			perror("accept");
			exit(EXIT_FAILURE);
		}
		if((pid = fork()) < 0){
			perror("fork");
			exit(EXIT_FAILURE);
		}else if(pid == 0){
			if(close(listenfd) < 0){
				perror("close");
				exit(EXIT_FAILURE);
			}
			str_echo(connfd);
			exit(EXIT_SUCCESS);
		}
		if(close(connfd) < 0){
			perror("close");
			exit(EXIT_FAILURE);
		}
	}
}
