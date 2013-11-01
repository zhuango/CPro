#include<stdio.h>
#include<stdlib.h>
#include<strings.h>
#include<signal.h>
#include<errno.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<poll.h>
#define INFTIM -1
#define MAXLINE 1024
#define OPEN_MAX 1024
int main(void)
{
	int i, maxi, listenfd, connfd, sockfd;
	int nready;
	ssize_t n;
	char buf[MAXLINE];
	socklen_t clientn;
	struct sockaddr_in serveraddr, clientaddr;
	struct pollfd	client[OPEN_MAX];

	if((listenfd = socket(AF_INET, SOCK_STREAM, 0)) < 0){
		perror("socket");
		exit(EXIT_FAILURE);
	}
	bzero(&serveraddr, sizeof(serveraddr));
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

	client[0].fd = listenfd;
	client[0].events = POLLRDNORM;
	for(i = 1; i < OPEN_MAX; i++)
		client[i].fd = -1;
	maxi = 0;

	for(;;){
		if((nready = poll(client, maxi+1, INFTIM)) < 0){
			perror("poll");
			exit(EXIT_FAILURE);
		}

		if(client[0].revents & POLLRDNORM){
			clientn = sizeof(clientaddr);
			if((connfd = accept(listenfd, (struct sockaddr*)&clientaddr, &clientn)) < 0){
				perror("accept");
				exit(EXIT_FAILURE);
			}

			for(i = 1; i < OPEN_MAX; i++)
				if(client[i].fd  == -1){
					client[i].fd = connfd;
					break;
				}
			if(i == OPEN_MAX){
				printf("too many clients\n");
				exit(EXIT_FAILURE);
			}
			client[i].events = POLLRDNORM;
			if(i > maxi)
				maxi = i;
			if(--nready <= 0)
				continue;
		}

		for(i = 1; i <= maxi; i++){
			if((sockfd = client[i].fd) == -1)
				continue;
			if(client[i].revents & (POLLRDNORM | POLLERR)){
				if((n = read(sockfd, buf, MAXLINE)) < 0){
					if(errno == ECONNRESET){
						if(close(sockfd) < 0){
							perror("close");
							exit(EXIT_FAILURE);
						}
						client[i].fd = -1;
					}else{
						perror("read error");
						exit(EXIT_FAILURE);
					}
				}else if(n == 0){
					if(close(sockfd) < 0){
						perror("close");
						exit(EXIT_FAILURE);
					}
					client[i].fd = -1;
				}else
					if(writen(sockfd, buf, n) < 0){
						perror("write");
						exit(EXIT_FAILURE);
					}
				if(--nready <= 0)
					break;
			}
		}
	}
}
