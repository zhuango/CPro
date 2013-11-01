#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<arpa/inet.h>
#include<netinet/in.h>
#include<sys/socket.h>
#define MAXLINE 1024
#define IPV6_MASK 0xffff0000
int inet_pton_loose(int family, const char *strptr, void *addrptr);

int main(int argc, char *argv[])
{
	struct sockaddr_in6 addr;
	char buf[MAXLINE];

	if(argc != 2){
		printf("Usage: %s <IPAddress>\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	if(inet_pton_loose(AF_INET6, argv[1], &addr.sin6_addr) != 1){
		perror("inet_pton_loose");
		exit(EXIT_FAILURE);
	}
	if(inet_ntop(AF_INET6, (void*)&addr.sin6_addr, buf, sizeof(buf)) == NULL){
		perror("inet_ntop");
		exit(EXIT_FAILURE);
	}
	printf("Address: %s\n", buf);

	exit(EXIT_FAILURE);
}

int inet_pton_loose(int family, const char *strptr, void *addrptr)
{
	unsigned int mask[4] = {0, 0, 0, 0};
	switch(family){
		case AF_INET:/*IPv4*/
			if(inet_pton(family, strptr, addrptr) != 1){/*inet_pton*/
				if(inet_aton(strptr, addrptr) != 1){/*inet_aton*/
					perror("inet_aton");
					exit(EXIT_FAILURE);
				}
			}
			break;

		case AF_INET6:/*IPv6*/
			if(inet_pton(family, strptr, addrptr) != 1){/*inet_pton*/
				if(inet_aton(strptr, addrptr) != 1){/*inet_aton*/
					perror("inet_aton");
					exit(EXIT_FAILURE);
				}
/*				for(i = 0; i < 32; i++){
					unsigned int n;
					if((*(int *)addrptr) & (1 << i))
						n = 1;
					else	n = 0;
					
					*(mask + 3) = *(mask + 3) | (n << (i));
				}
*/				*(mask + 3) |= (*(int *)addrptr);
				*(mask + 2) |= IPV6_MASK ;
				memcpy(addrptr, &mask, sizeof(mask));
			}
			break;
	}

	return 1;
}
