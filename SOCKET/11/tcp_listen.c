#include<stdio.h>
#include<stdlib.h>
#include<netinet/in.h>
#include<sys/socket.h>
#include<netdb.h>
#include<strings.h>

int tcp_listen(const char *host, const char *serv, socklen_t *addrlen)
{
	int listenfd, n;
	const int on = 1;
	struct addrinfo hints, *res, *ressave;

	/* Set the struct addrinfo */
	bzero(&hints, sizeof(struct addrinfo));
	hints.ai_flags = AI_PASSIVE;/* Be Opened */
	hints.ai_family = AF_UNSPEC;/* suprise me */
	hints.ai_socktype = SOCK_STREAM;/* TCP or other char_stream protocol */

	/* Get addrindo */
	if((n = getaddrinfo(host, serv, &hints, &res)) != 0){
		fprintf(stderr, "getaddrinfo error: %s %s: %s\n", host, serv, gai_strerror(n));
		exit(EXIT_FAILURE);
	}

	ressave = res;/* Save addrinfo list */

	do{
		listenfd = socket(res->ai_family, res->ai_socktype, res->ai_protocol);/* Create new socket */
		if(listenfd == 0)
			continue;
		/* Bind local address */
		if(bind(listenfd, res->ai_addr, res->ai_addrlen) == 0)
			break;/* Bind OK, go to listen */
		/* Fail */
		if(close(listenfd) != 0){
			perror("close");
			exit(EXIT_FAILURE);
		}
	}while((res = res->ai_next) != NULL);

	/* No one good addrinfo */
	if(res == NULL){
		printf("tcp_listen error for %s %s\n", host, serv);
		exit(EXIT_FAILURE);
	}
	/* Listen */
	if(listen(listenfd, 5) != 0){
		perror("listen");
		exit(EXIT_FAILURE);
	}

	if(addrlen)/* Have this arg */
		*addrlen = res->ai_addrlen;

	freeaddrinfo(ressave);
	
	return listenfd;
}

