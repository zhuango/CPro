#include<stdio.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<netdb.h>
#include<string.h>
#include<stdlib.h>

char *host_name = "127.0.0.1";
int port = 8000;

void main(int argc,char **argv)
{
	char buf[8192];
	char message[256];

	int socket_descriptor;
	struct sockaddr_in pin;
	struct hostent *server_host_name;

	char *str = "A default test string";

	if( argc < 2){
		printf("Usage: 'test \" Any test string\"\n");
		printf("We will send a default test dtring.\n");
	}else{
		str = argv[1];
	}

	if ((server_host_name = gethostbyname(host_name)) == 0){
		perror("Error resolving local host\n");
		exit(EXIT_FAILURE);
	}

	bzero(&pin,sizeof(pin));
	pin.sin_family = AF_INET;
	pin.sin_addr.s_addr = ((struct in_addr *)(server_host_name->h_addr))->s_addr;
	pin.sin_port = htons(port);

	if( (socket_descriptor = socket(AF_INET,SOCK_STREAM, 0)) == -1){
		perror("Error connecting to socket\n");
		exit(EXIT_FAILURE);
	}

	if(connect(socket_descriptor, (void*)&pin, sizeof(pin)) == -1){
		perror("Error connecting to socket\n");
		exit(EXIT_FAILURE);
	}
	printf("sending message %s to server ...\n",str);

	if( send(socket_descriptor,str,strlen(str) , 0) == -1){
		perror("Error in send");
		exit(EXIT_FAILURE);
	}
	printf("..sent message.. wait for response...\n");

	if(recv(socket_descriptor,buf,8192,0) == -1){
		perror("Error in receiving response from server\n");
		exit(EXIT_FAILURE);
	}

	printf("Response from server:\n\n%s\n",buf);
	close(socket_descriptor);
}
