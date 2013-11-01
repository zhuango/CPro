#include<stdio.h>
#include<stdlib.h>
#include<netinet/in.h>
#include<sys/socket.h>
#include<netdb.h>
#include<arpa/inet.h>
#include<strings.h>

int main(int argc, char **argv)
{
	struct sockaddr_in addr;
	int listenfd;

	if(argc != 2){
		printf("Usage: %s <IPaddress>\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	/* Create new socket */
	if((listenfd = socket(AF_INET, SOCK_STREAM, 0)) < 0){
		perror("socket");
		exit(EXIT_FAILURE);
	}
	
	/* Clear the struct sockaddr_in */
	bzero(&addr, sizeof(addr));
	addr.sin_family = AF_INET;
	addr.sin_port = htons(9999);
	if(inet_pton(AF_INET, argv[1], &addr.sin_addr) == -1){
		perror("inet_pton");
		exit(EXIT_FAILURE);
	}
	int on = 1;
	/* Set the SO_REUSEADDR */
	if(setsockopt(listenfd, SOL_SOCKET, SO_REUSEADDR, &on, sizeof(on)) == -1){
		perror("setsockpot");
		exit(EXIT_FAILURE);
	}
	
	/* Bind */
	if(bind(listenfd, (struct sockaddr*)&addr, sizeof(addr)) < 0){
		perror("bind");
		exit(EXIT_FAILURE);
	}
	/*Listen  */
	if(listen(listenfd, 5) < 0){
		perror("listen");
		exit(EXIT_FAILURE);
	}
	
	/* Pause to wait aother server */
	pause();

	exit(EXIT_SUCCESS);
}
