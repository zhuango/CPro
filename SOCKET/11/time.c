#include<stdio.h>
#include<stdlib.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<netdb.h>
#include<string.h>

#define MAXLINE 1024
#include "tcp_listen.c"
#include "sock_ntop.c"

int tcp_listen(const char *, const char *, socklen_t *);
char *sock_ntop(const struct sockaddr *, socklen_t );

int main(int argc, char **argv)
{
	int listenfd, connfd;
	struct sockaddr_storage clientaddr;
	time_t ticks;
	socklen_t len;
	char buff[MAXLINE];

	if(argc == 2)
		listenfd = tcp_listen(NULL, argv[1], NULL);
	else if(argc == 3)
		listenfd = tcp_listen(argv[1], argv[2], NULL);
	else{
		printf("Usage: %s <service or port>\n", argv[0]);
		exit(EXIT_FAILURE);
	}


	for(;;){
		len = sizeof(clientaddr);
		if((connfd = accept(listenfd, (struct sockaddr*)&clientaddr, &len)) < 0){
			perror("accept");
			exit(EXIT_FAILURE);
		}
		printf("connection from %s\n", sock_ntop((struct sockaddr*)&clientaddr, len));
		ticks = time(NULL);
		snprintf(buff, sizeof(buff), "%.24s\r\n", ctime(&ticks));
		if(write(connfd, buff, strlen(buff)) < 0){
			perror("write");
			exit(EXIT_FAILURE);
		}
		printf("++++++++++++++++++++++++\n");
		if(close(connfd) < 0){
			perror("close");
			exit(EXIT_FAILURE);
		}
	}
}
