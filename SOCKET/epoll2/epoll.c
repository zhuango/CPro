#include<stdio.h>
#include<stdlib.h>
#include<sys/epoll.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<errno.h>
#include<string.h>
#include<arpa/inet.h>

#define SERV_PORT 9877
#define MAXLINE 1024
#define LISTENQ 512

typedef struct sockaddr SA;

int main(void)
{
	int listenfd, connfd, epfd, sockfd;
	int nfds,i,  n;
	socklen_t clientn;
	char buf[MAXLINE];

	struct sockaddr_in server;
	struct sockaddr_in client;

	if((listenfd = socket(AF_INET, SOCK_STREAM, 0)) < 0){
		perror("socket");
		exit(EXIT_FAILURE);
	}
	/* Init the address struct */
	bzero(&server, sizeof(server));
	server.sin_family = AF_INET;
	server.sin_port = htons(SERV_PORT);
	server.sin_addr.s_addr = htonl(INADDR_ANY);
	/* Bind the listenfd */
	if(bind(listenfd, (SA*)&server, sizeof(server)) != 0){
		perror("bind");
		exit(EXIT_FAILURE);
	}
	/* Listen */
	if(listen(listenfd, LISTENQ) != 0){
		perror("listen");
		exit(EXIT_FAILURE);
	}

	/* Create a epoll set */
	epfd = epoll_create(256);

	/* Event struct init */
	struct epoll_event ev, events[256];

	/* Watch out the listenfd read operator and use the ET mode  */
	ev.data.fd = listenfd;
	ev.events = EPOLLIN | EPOLLET;

	epoll_ctl(epfd, EPOLL_CTL_ADD, listenfd, &ev);



	while(1){
		/* max events number is 20, wait for 500 milliseconds. */
		nfds = epoll_wait(epfd, events, 20, 500);
		for(i = 0; i < nfds; i++){
			if(events[i].data.fd == listenfd){
				clientn = sizeof(client);
				connfd = accept(listenfd, (SA*)&client, &clientn);
				ev.data.fd = connfd;
				ev.events = EPOLLIN | EPOLLET;
				
				epoll_ctl(epfd, EPOLL_CTL_ADD, connfd, &ev);
			/* Receive data */
			}else if(events[i].events & EPOLLIN){
				/* Get the socket for reading data */
				sockfd = events[i].data.fd;
				if(sockfd < 0)/* Error socket */
					continue;

				n = read(sockfd, buf, MAXLINE);
				if(n < 0){
					/* Socket close */
					if(errno = ECONNRESET){
						close(sockfd);
						events[i].data.fd = -1;
					}else peror("read error");

				}else if(n == 0){/*Read data over */
					close(sockfd);
					events[i].data.fd = -1;
				}else{/* receive over and change mode of the socket */
					ev.data.fd = sockfd;
					ev.events = EPOLLOUT | EPOLLET;

					epoll_ctl(epfd, EPOLL_CTL_MOD, sockfd, &ev);
				}
			/* Has data to write */
			}else if(events[i].events & EPOLLOUT){
				sockfd = events[i].data.fd;
				write(sockfd, buf, n);
				/* Write over and change mode of socket */
				ev.data.fd = sockfd;
				ev.events = EPOLLIN | EPOLLET;

				epoll_ctl(epfd, EPOLL_CTL_MOD, sockfd, &ev);
			}
		}
	}

	exit(EXIT_SUCCESS);
}
