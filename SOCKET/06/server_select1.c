#include<stdio.h>
#include<stdlib.h>
#include<strings.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<signal.h>
#include<errno.h>
#define MAXLINE 1024

void sig_chld(int signo);

int main(void)
{
	int i, maxi, maxfd, nready, client[FD_SETSIZE];
	fd_set rset, allset;
	ssize_t n;
	int listenfd, connfd, sockfd;/* listen socket, connection socket */
	struct sockaddr_in serveraddr, clientaddr;/* server and client address struct */
	socklen_t clientn;/* length of client address struct */
	pid_t pid;/* new process pid */
	char buf[MAXLINE];

	if((listenfd = socket(AF_INET, SOCK_STREAM, 0)) < 0){/* create a listen socket */
		perror("socket");
		exit(EXIT_FAILURE);
	}

	bzero(&serveraddr, sizeof(serveraddr));/* clear the server address struct */
	/* set the protrcl IPaddress port number */
	serveraddr.sin_family = AF_INET;
	serveraddr.sin_addr.s_addr = htonl(INADDR_ANY);
	serveraddr.sin_port = htons(9877);

	/* bind the socket and IPaddress */
	if(bind(listenfd, (struct sockaddr*)&serveraddr, sizeof(serveraddr)) < 0){
		perror("bind");
		exit(EXIT_FAILURE);
	}

	if(listen(listenfd, 5) < 0){/* listen socket */
		perror("listen");
		exit(EXIT_FAILURE);
	}
	if(signal(SIGCHLD, sig_chld) == SIG_ERR){/* set the SIGCHLD signal */
		perror("signal");
		exit(EXIT_FAILURE);
	}
	for(i = 0; i < FD_SETSIZE; i++)
		client[i] = -1;
	maxi = -1;
	maxfd = listenfd;
	FD_ZERO(&allset);
	FD_SET(listenfd, &allset);
	for(;;){
		rset = allset;/* reset the fd set */
		/* wait for the IO */
		if((nready = select(maxfd + 1, &rset, NULL, NULL, NULL)) < 0){
			perror("select");
			exit(EXIT_FAILURE);
		}
		if(FD_ISSET(listenfd, &rset)){/* connection is ready */
			clientn = sizeof(clientaddr);
			if((connfd = accept(listenfd, (struct sockaddr*)&clientaddr, &clientn)) < 0){/* connect to client */
				if(errno == EINTR){/* the SIGCHLD signal come */
					continue;
				}
				perror("accept");
				exit(EXIT_FAILURE);
			}

			for(i = 0; i < FD_SETSIZE; i++)
				if(client[i] < 0){
					client[i] = connfd;
					break;
				}
			if(i == FD_SETSIZE){
				printf("full client sockfd\n");
				exit(EXIT_FAILURE);
			}
			FD_SET(connfd, &allset);
			if(i > maxi)
				maxi = i;
			if(connfd > maxfd)
				maxfd = connfd;
			if(--nready <= 0)
				continue;
		}
	
		for(i = 0; i <= maxi; i++){
			if((sockfd = client[i]) == -1)
				continue;
			if(FD_ISSET(sockfd, &rset)){
				if((n = read(sockfd, buf, MAXLINE)) < 0){
					perror("read");
					exit(EXIT_FAILURE);
				}else if(n == 0){
					if(close(sockfd) < 0){
						perror("sockfd");
						exit(EXIT_FAILURE);
					}
					FD_CLR(sockfd, &allset);
					client[i] = -1;
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
void sig_chld(int signo)
{
	pid_t pid;
	int stat;

	while((pid = waitpid(-1, &stat, WNOHANG)) > 0){;/* get the child info */
//		printf("child %d terminated\n", pid);
	}
	return ;
}
