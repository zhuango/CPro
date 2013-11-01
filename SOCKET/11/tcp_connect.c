#include<stdio.h>
#include<stdlib.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<netdb.h>
#include<strings.h>

int tcp_connect(const char *host, const char *serv)
{
	int sockfd, n;
	struct addrinfo hints, *res, *ressave;

	/* Set the addrinfo info you want */
	bzero(&hints, sizeof(struct addrinfo));
	hints.ai_family = AF_UNSPEC;/* AF_INET */
	hints.ai_socktype = SOCK_STREAM;/* TCP or other char_stream protocol */

	/* Get the info of "host" "serv" */
	if((n = getaddrinfo(host, serv, &hints, &res)) != 0){
		fprintf(stderr,"getaddrinfo error: %s %s: %s ",host, serv, gai_strerror(n));
		exit(EXIT_FAILURE);
	}

	ressave = res;/* Save the addrinfo list */

	do{
		/* Create a new socket */
		if((sockfd = socket(res->ai_family, res->ai_socktype, res->ai_protocol)) < 0)
			continue;/* Bad addrinfo */
		/* Socket created */
		if(connect(sockfd, res->ai_addr, res->ai_addrlen) == 0)
			break;/* Success */
		if(close(sockfd) < 0){/* Fail for connecting */
			perror("close");
			exit(EXIT_FAILURE);
		}

	}while((res = res->ai_next) != NULL);/* Next addrinfo struct */

	if(res == NULL){/* No one is good addrinfo */
		printf("tcp_connect error for %s %s\n", host, serv);
		exit(EXIT_FAILURE);
	}

	freeaddrinfo(ressave);/* Free addrinfo list */

	return sockfd;/* retuen socket */
}

int Tcp_connect(const char *host, const char *serv)
{
	return(tcp_connect(host, serv));
}
