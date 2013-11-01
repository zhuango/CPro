#include<stdio.h>
#include<stdlib.h>
#include<strings.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<signal.h>
#include<errno.h>

void sig_chld(int signo);

int main(void)
{
	int listenfd, connfd;/* listen socket, connection socket */
	struct sockaddr_in serveraddr, clientaddr;/* server and client address struct */
	socklen_t clientn;/* length of client address struct */
	pid_t pid;/* new process pid */

	if((listenfd = socket(AF_INET, SOCK_STREAM, 0)) < 0){/* create a listen socket */
		perror("socket");
		exit(EXIT_FAILURE);
	}

	bzero(&serveraddr, 0);/* clear the server address struct */
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

	for(;;){
		clientn = sizeof(clientaddr);
		if((connfd = accept(listenfd, (struct sockaddr*)&clientaddr, &clientn)) < 0){
			if(errno == EINTR){/* the SIGCHLD signal come */
				continue;
			}
			perror("accept");
			exit(EXIT_FAILURE);
		}
		if((pid = fork()) < 0){/* new process to connect client */
			perror("fork");
			exit(EXIT_FAILURE);
		}else if(pid == 0){/* child */
			if(close(listenfd) < 0)/* child close the listenfd */{
				perror("close");
				exit(EXIT_FAILURE);
			}
			str_echo(connfd);/* send the string to server */
			exit(EXIT_SUCCESS);
		}
		if(close(connfd) < 0){/* father close the connection , be ready for the next client */
			perror("close");
			exit(EXIT_FAILURE);
		}
	}
}

void sig_chld(int signo)
{
	pid_t pid;
	int stat;

	while((pid = waitpid(-1, &stat, WNOHANG)) < 0){;/* get the child info */
		printf("child %d terminated\n", pid);
	}
	return ;
}
