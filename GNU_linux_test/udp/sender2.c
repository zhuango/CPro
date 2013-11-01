#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<netdb.h>
#include<errno.h>

int port = 6789;

int main(void)
{
	int socket_descriptor;
	int iter = 0;
	ssize_t sendto_rc;
	int close_rc;
	char buf[80];
	struct sockaddr_in address;
	struct hostent *hostbyname;

	hostbyname = gethostbyname("127.0.0.1");
	if(hostbyname == NULL){
		perror("gethostbyname");
		exit(EXIT_FAILURE);
	}

	bzero(&address,sizeof(address));
	address.sin_family = AF_INET;
	memcpy(&address.sin_addr.s_addr,hostbyname->h_addr,sizeof(address.sin_addr.s_addr));
	address.sin_port = htons(port);

	socket_descriptor = socket(AF_INET,SOCK_DGRAM,0);
	if(socket_descriptor == -1){
		perror("socket call failed");
		exit(errno);
	}

	for(iter = 0;iter <= 20;iter++){
		sprintf(buf,"data packer with ID %d\n",iter);
		sendto_rc = sendto(socket_descriptor,
				buf,sizeof(buf),
				0,(struct sockaddr *)&address,sizeof(address));
		if(sendto_rc == -1){
			perror("sendto call failed");
			exit(errno);
		}
	}

	sprintf(buf,"stop\n");
	sendto_rc = sendto(socket_descriptor,
			buf,sizeof(buf),
			0,(struct sockaddr*) &address,sizeof(address));
	if(sendto_rc == -1){
		perror("sendto STOP call failed");	
		exit(EXIT_FAILURE);
	}
	close_rc = close(socket_descriptor);
	if(close_rc == -1){
		perror("close call failed");
		exit(errno);
	}

	printf("Messages Sent, Terminating\n");
	exit(0);
}
