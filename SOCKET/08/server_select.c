#include<stdio.h>
#include<stdlib.h>
#include<strings.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<errno.h>
#include<signal.h>

#define MAXLINE 1024
/* max fd */
int max(int a, int b)
{
	if(a < b)
		return b;
	else 
		return a;
}
/* deal the child end signal */
void sig_child(int num)
{
	pid_t pid;
	int statue;
	while((pid = waitpid(-1, &statue, WNOHANG)) < 0){
		printf("%d end\n", pid);
	}
}

int main(void)
{
	int		sockfd, listenfd, pid, clientfd;/* 1. UDP socket 2. TCP socket 3. number if new process 4.TCP connfd */
	int		n, len, no = 1;/* open the socket opinion */
	struct sockaddr_in 	serveraddr, clientaddr;/* server and client addr struct */
	fd_set 	rset;/* fd set */
	int 	maxfd; /* select max fd */
	char	mesg[MAXLINE];
	/* TCP socket and bind */
	if((listenfd = socket(AF_INET, SOCK_STREAM, 0)) < 0){
		perror("socket");
		exit(EXIT_FAILURE);
	}
	bzero(&serveraddr, sizeof(serveraddr));
	serveraddr.sin_family = AF_INET;
	serveraddr.sin_addr.s_addr = htonl(INADDR_ANY);
	serveraddr.sin_port = htons(9877);

	if(setsockopt(listenfd, SOL_SOCKET, SO_REUSEADDR, &no, sizeof(no)) < 0){/* address reuse */
		perror("setsockopt");
		exit(EXIT_FAILURE);
	}
	if(bind(listenfd, (struct sockaddr*)&serveraddr, sizeof(serveraddr)) < 0){
		perror("bind");
		exit(EXIT_FAILURE);
	}
	if(listen(listenfd, 5) < 0){
		perror("listen");
		exit(EXIT_FAILURE);
	}

	/* UDP socket and bind */
	if((sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0){
		perror("socket");
		exit(EXIT_FAILURE);
	}
	bzero(&serveraddr, sizeof(serveraddr));
	serveraddr.sin_family = AF_INET;
	serveraddr.sin_addr.s_addr = htonl(INADDR_ANY);
	serveraddr.sin_port = htons(9877);
	
	if(bind(sockfd, (struct sockaddr*)&serveraddr, sizeof(serveraddr)) < 0){
		perror("bind");
		exit(EXIT_FAILURE);
	}
	/* child precess ending signal */	
	if(signal(SIGCHLD, sig_child) < 0){
		perror("signal");
		exit(EXIT_FAILURE);
	}
	/* Select */
	FD_ZERO(&rset);
	maxfd = max(listenfd, sockfd) + 1;
	for(;;){
		FD_SET(listenfd, &rset);
		FD_SET(sockfd, &rset);
		if(select(maxfd, &rset, NULL, NULL, NULL) < 0){/* wait for reading ready */
			if(errno == EINTR)
				continue;
			else{
				perror("select");
				exit(EXIT_FAILURE);
			}
		}
		/* TCP is ready */
		if(FD_ISSET(listenfd, &rset)){
			len = sizeof(clientaddr);
			if((clientfd = accept(listenfd, (struct sockaddr*)&clientaddr, &len)) < 0){
				perror("accept");
				exit(EXIT_FAILURE);
			}
			if((pid = fork()) < 0){
				perror("sork");
				exit(EXIT_FAILURE);
			}else if(pid == 0){
				if(close(listenfd) < 0){
					perror("close");
					exit(EXIT_FAILURE);
				}
				str_echo(clientfd);
				exit(0);
			}
			if(close(clientfd) < 0){
				perror("close");
				exit(EXIT_FAILURE);
			}
		}
		/* UDP is ready */
		if(FD_ISSET(sockfd, &rset)){
			len = sizeof(clientaddr);
			if((n = recvfrom(sockfd, mesg, MAXLINE, 0, (struct sockaddr*)&clientaddr, &len)) < 0){
			   perror("recvfrom");
			   exit(EXIT_FAILURE);
			}
			if(sendto(sockfd, mesg, n, 0, (struct sockaddr*)&clientaddr, len) < 0){
				perror("sockfd");
				exit(EXIT_FAILURE);
			}
		}
	}
}

