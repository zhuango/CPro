#include<stdio.h>
#include<stdlib.h>
#include<netinet/in.h>
#include<strings.h>
#include<netdb.h>

struct addrinfo *host_serv(const char *host, const char *serv,
		int family, int socktype)
{
	int n;
	struct addrinfo hints, *res;

	/* Set the struct addrinfo you want */
	bzero(&hints, sizeof(struct addrinfo));
	hints.ai_flags = AI_CANONNAME;/* Full name */
	hints.ai_family = family;/* Set the AF_xxxx */
	hints.ai_socktype = socktype;/* Set the socket type */

	if((n = getaddrinfo(host, serv, &hints, &res)) != 0)/* Get the "host" "serv" addrinfos */
		return NULL;/* Fail */

	return (res);
}

