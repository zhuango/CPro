#include<stdio.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<netdb.h>
#include<stdlib.h>
#include<string.h>

char *host_name = "127.0.0.1";
int port = 8000;

int main(void){
	char buf[8192];
	char message[256];
	int sd;
	struct sockaddr_in pin;
	struct hostent *nlp_host;

	if((nlp_host = gethostbyname(host_name)) == 0){
		printf("Error resolving local host\n");
		exit(EXIT_FAILURE);
	}

	bzero(&pin,sizeof(pin));
	pin.sin_family = AF_INET;
	pin.sin_addr.s_addr = htonl(INADDR_ANY);
	pin.sin_addr.s_addr = ((struct in_addr *) (nlp_host->h_addr))->s_addr;
	pin.sin_port = htons(port);

	if((sd = socket(AF_INET, SOCK_STREAM,0)) == -1){
		printf("Error opening socket\n");
		exit(EXIT_FAILURE);
	}

	if(connect(sd,(void*)&pin,sizeof(pin)) == -1){
		printf("Error opening socket\n");
		exit(EXIT_FAILURE);
	}
	sprintf(message,"GET /index.html HTTP/1.1\n");
	printf("Sending message %s to web_server ... \n",message);
	if(send(sd,message,strlen(message), 0) == -1){
		printf("Error in send\n");
		exit(EXIT_FAILURE);
	}

	printf("..sent message .. wait for response...\n");
	if(recv(sd,buf,8192,0) == -1){
		printf("Error in receiving response from NLPserver\n");
		exit(EXIT_FAILURE);
	}

	printf("\nResponse from NLPserver: \n\n%s\n",buf);
	close(sd);
}
