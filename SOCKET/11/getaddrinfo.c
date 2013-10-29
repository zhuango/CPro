#include<stdio.h>
#include<stdlib.h>
#include<netdb.h>
#include<errno.h>
#include<strings.h>

int main(int argc, char **argv)
{
	struct addrinfo info, *ret, *index;

	if(argc != 3){
		printf("Usage: %s <Hostname> <IPaddress>\n", argv[0]);
		exit(EXIT_FAILURE);
	}
	bzero(&info, sizeof(info));
	info.ai_flags = AI_CANONNAME;
	info.ai_family = AF_INET;
	//info.ai_protocol = IPPROTO_TCP;

	if(getaddrinfo(argv[1], argv[2], &info, &ret) != 0){
		fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(h_errno));
		exit(EXIT_FAILURE);
	}

	index = ret;
	while(ret != NULL){
		printf("AF_xxxx: %d\n", ret->ai_family);
		printf("SOCK_xxxx: %d\n", ret->ai_socktype);
		printf("Type of pro: %d\n", ret->ai_protocol);
		printf("Sizeof sockaddr: %d\n", ret->ai_addrlen);
		printf("HostName: %s\n", ret->ai_canonname);
		
		struct sockaddr_in *sin = (struct sockaddr_in*)ret->ai_addr;
		printf("AF_xxxx(from ai_addr): %d\n", ret->ai_addr->sa_family);
		printf("Port Number: %d\n", ntohs(sin->sin_port));
		printf("Data : %s\n", ret->ai_addr->sa_data);

		ret = ret->ai_next;
	}
	freeaddrinfo(index);
	exit(EXIT_SUCCESS);
}
