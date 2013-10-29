#include<netinet/in.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<fcntl.h>
#include<errno.h>

#define SERV_PORT 9877
#define LISTENQ 1024
#define MAXLINE 1024

void Write(int sockfd, char *buf, int n)
{
	if(write(sockfd, buf, n) < 0){
		perror("write");
		exit(EXIT_FAILURE);
	}
}
void str_echo(int sockfd)
{
	ssize_t n;
	char buf[MAXLINE];

again:
	/* read from client */
	while((n = read(sockfd, buf, MAXLINE)) > 0)
	/* write to the client */
		Write(sockfd, buf, n);

	/* there is a error? OK go again */
	if(n < 0 && errno == EINTR)
		goto again;
	else if(n < 0){/* error of read */
		perror("str_echo : read error");
		exit(EXIT_FAILURE);
	}
}

void Bind(int listenfd, struct sockaddr *servaddr, int size_servaddr)
{
	if(bind(listenfd, servaddr, size_servaddr) < 0){
		perror("bind");
		exit(EXIT_FAILURE);
	}
}

void Listen(int listenfd, int MAX_conn_num)
{
	if(listen(listenfd, MAX_conn_num) < 0){
		perror("listen");
		exit(EXIT_FAILURE);
	}
}

int Accept(int listenfd, struct sockaddr* cliaddr, int size_cliaddr)
{
	int n;
	if((n = accept(listenfd, cliaddr, size_cliaddr)) < 0){
		perror("accept");
		exit(EXIT_FAILURE);
	}

	return n;
}

int Fork()
{
	int new_pid;
	if((new_pid = fork()) < 0){
		perror("fork");
		exit(EXIT_FAILURE);
	}else if(new_pid == 0){
		return new_pid;
	}

	return new_pid;
}

void Close(int listenfd)
{
	if(close(listenfd) < 0){
		perror("close");
		exit(EXIT_FAILURE);
	}
}

int Socket(int family, int type, int portconl)
{
	int n;
	if((n = socket(family, type, portconl)) < 0){
		perror("socket");
		exit(EXIT_FAILURE);
	}
	return n;
}
int main(int argc, char **argv)
{
	int listenfd, connfd;/* listenfd for the server, connfd for client */
	pid_t childpid;		/* the new process */
	socklen_t clilen;	/* address length */
	struct sockaddr_in cliaddr, servaddr;/* cliaddr for the client address,servaddr for the server */

	/* create the socket for server */
	listenfd = Socket(AF_INET, SOCK_STREAM, 0);

	/* clear and set the address struct */
	bzero(&servaddr, sizeof(servaddr));
	servaddr.sin_family = AF_INET;	/* set the family */
	servaddr.sin_addr.s_addr = htonl(INADDR_ANY);/* set the addr */
	servaddr.sin_port = htons(SERV_PORT);		/*set the port*/

	/* bind the address and the sockfd */
	Bind(listenfd, (struct sockaddr *)&servaddr, sizeof(servaddr));

	/* listening the client request and set the most big number of clinet connection */
	Listen(listenfd, LISTENQ);

	/* deal the client request */
	for(;;){
		/* length of cliaddr */
		clilen = sizeof(cliaddr);
		/* accept the client request anf get the client address into the struct named cliaddr,sizeof the struct is clilen*/
		connfd = Accept(listenfd, (struct sockaddr *)&cliaddr, &clilen);

		/* create the clild process to deal the request */
		if((childpid = Fork()) == 0){
			/* shutdown the connection */
			Close(listenfd);
			/* read from sockfd named connfd */
			str_echo(connfd);
			exit(EXIT_SUCCESS);/* exit */
		}
		/* shutdown the server */
		Close(listenfd);
	}
}
