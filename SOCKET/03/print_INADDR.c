#include<stdio.h>
#include<stdlib.h>
#include<netinet/in.h>
#include<arpa/inet.h>

int main(void)
{
	unsigned int loopback = INADDR_LOOPBACK;
	struct sockaddr_in addr;
	printf("%x\n", INADDR_LOOPBACK);
	
	inet_pton(AF_INET, "127.0.0.2", &addr.sin_addr);

	printf("%x\n", addr.sin_addr);
}
