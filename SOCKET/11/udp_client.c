#include<stdio.h>
#include<stdlib.h>
#include<netinet/in.h>
#include<sys/socket.h>
#include<netdb.h>
#include<strings.h>
#include<string.h>

int udp_client(const char *host, const char *serv,
		struct sockaddr **saptr, socklen_t *lenp)
{
	int sockfd, n;
	struct addrinfo		hints, *res, *ressave;

	/* Clest the struct addrinfo */
	bzero(&hints, sizeof(struct addrinfo));
	hints.ai_family = AF_UNSPEC;
	hints.ai_socktype = SOCK_DGRAM;

	/* Get addrinfo of you want */
	if((n = getaddrinfo(host, serv, &hints, &res)) != 0){
		fprintf(stderr, "udp_client error : %s %s: %s\n",
				host, serv, gai_strerror(n));
		exit(EXIT_FAILURE);
	}

	ressave = res;/* Save the list head */

	do{
		/* Create new socket */
		sockfd = socket(res->ai_family, res->ai_socktype, res->ai_protocol);
		if(sockfd >= 0)/* Create successfully */
			break;
	}while((res = res->ai_next) != NULL);

	/* Create socket error */
	if(res == NULL){
		printf("tcp_client error :res == NULL\n");
		exit(EXIT_FAILURE);
	}
	/* Retuen the server info */
	*saptr = malloc(res->ai_addrlen);/* address struct */
	memcpy(*saptr, res->ai_addr, res->ai_addrlen);
	/* Get the group that number in , set "file" */
	*lenp = res->ai_addrlen;

	freeaddrinfo(ressave);

	return sockfd;
}

