#include<stdio.h>
#include<stdlib.h>
#include<netinet/in.h>
#include<sys/socket.h>
#include<strings.h>
#include<signal.h>

#define PORT	9877

void sig_int(int);/* catch the SIGINT */
void sig_child(int);/* catch the SIGCHLD */

int main(void)
{
	int listenfd, connfd;/* listen socket, connection socket */
	int err;
	socklen_t clientn;/* return error */
	struct sockaddr_in serveraddr, *clientaddr;/* server and client Address struct  */
	pid_t pid;

	listenfd = socket(AF_INET, SOCK_STREAM, 0);/* create the socket */
	if(listenfd < 0){
		perror("socket");
		exit(EXIT_FAILURE);
	}

	/* set the server local Address struct */
	bzero(&serveraddr, sizeof(serveraddr));
	serveraddr.sin_family = AF_INET;
	serveraddr.sin_addr.s_addr = htonl(INADDR_ANY);
	serveraddr.sin_port = htons(PORT);

	/* bind the socket */
	if(bind(listenfd, (struct sockaddr*)&serveraddr, sizeof(serveraddr)) < 0){
		perror("bind");
		exit(EXIT_FAILURE);
	}
	/* listening */
	if(listen(listenfd, 5) < 0){
		perror("listenfd");
		exit(EXIT_FAILURE);
	}

	if(signal(SIGINT, sig_int) < 0){
		perror("signal");
		exit(EXIT_FAILURE);
	}
	if(signal(SIGCHLD, sig_child) < 0){
		perror("signal");
		exit(EXIT_FAILURE);
	}
	
	while(1){
		clientaddr = malloc(sizeof(struct sockaddr));/* crete a new client address */
		if(clientaddr == NULL){
			perror("malloc");
			exit(EXIT_FAILURE);
		}
		clientn = sizeof(*clientaddr);/* client address struct size */

		/* Accept the client connection*/
		if((connfd = accept(listenfd, (struct sockaddr*)&clientaddr, &clientn)) < 0){
			perror("accept");
			exit(EXIT_FAILURE);
		}

		/* create a new process to deal a client */
		if((pid = fork()) < 0){
			perror("fork");
			exit(EXIT_FAILURE);
		}else if(pid == 0){
			if(close(listenfd) < 0){
				perror("close");
				exit(EXIT_FAILURE);
			}
			file_deal(connfd, (struct sockaddr*)clientaddr, clientn);
			exit(EXIT_SUCCESS);
		}
		if(close(connfd) < 0){
			perror("close");
			exit(EXIT_FAILURE);
		}
	}

}

void sig_int(int num)
{
	printf("fielT server Stop\n");
	exit(EXIT_SUCCESS);
}

void sig_child(int num)
{
	pid_t pid;
	int stat;

	while((pid = waitpid(-1, &stat, WNOHANG)) < 0){
		printf("child %d terminated\n", pid);
	}
	return ;
}
