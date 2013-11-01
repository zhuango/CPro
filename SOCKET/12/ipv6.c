#include<stdio.h>
#include<stdlib.h>
#include<netinet/in.h>
#include<sys/socket.h>
#include<strings.h>
#include<arpa/inet.h>

int main(int argc, char **argv)
{
	int listenfd;
	struct sockaddr_in6 addr;

	if(argc != 2){
		printf("Usage: %s <IPaddress>\n");
		exit(EXIT_FAILURE);
	}
	
	if((listenfd = socket(AF_INET6, SOCK_STREAM, 0)) < 0){
		perror("listenfd");
		exit(EXIT_FAILURE);
	}

	bzero(&addr, sizeof(addr));
	addr.sin6_family = AF_INET6;
	addr.sin6_port = htons(9999);
//	addr.sin6_addr = in6addr_any;
	if(inet_pton(AF_INET6, argv[1], &addr.sin6_addr) < 0){
		perror("inet_pton");
		exit(EXIT_FAILURE);
	}
	
	/* Set the SO_REUSEADDR */
	int on = 1;
	if(setsockopt(listenfd, SOL_SOCKET, SO_REUSEADDR, &on, sizeof(on)) == -1){
		perror("setsockpot");
		exit(EXIT_FAILURE);
	}

	if(bind(listenfd, (struct sockaddr*)&addr, sizeof(addr)) < 0){
		perror("bind");
		exit(EXIT_FAILURE);
	}

	if(listen(listenfd, 5) < 0){
		perror("listenfd");
		exit(EXIT_FAILURE);
	}

	pause();
	
	exit(EXIT_SUCCESS);
}
