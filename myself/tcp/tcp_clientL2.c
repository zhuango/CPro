#include<stdio.h>
#include<stdlib.h>
#include<errno.h>
#include<string.h>
#include<sys/types.h>
#include<netinet/in.h>
#include<netdb.h>
#include<sys/socket.h>

#define portnumber 3333

int main(int argc,char **argv){
	int sockfd;
	char buffer[1024];
	struct sockaddr_in server_addr;
	struct hostent *host;

	if( argc != 2){
		fprintf(stderr,"Usage:%s hostname:\a\n",argv[0]);
		exit(1);
	}

	if( (host = gethostbyname(argv[1]) ) == NULL){
		fprintf(stderr,"get host failed\b");
		exit(1);
	}

	if( (sockfd = socket(AF_INET,SOCK_STREAM,0)) == -1){
		fprintf(stderr,"create socket error:%s\n",strerror(errno));
		exit(1);
	}

	bzero(&server_addr,sizeof(struct sockaddr_in));

	server_addr.sin_family = AF_INET;
	server_addr.sin_port = htons(portnumber);
	server_addr.sin_addr = *((struct in_addr*)host->h_addr);

	if( connect(sockfd,(struct sockaddr*)(&server_addr),sizeof(struct sockaddr)) == -1){
		fprintf(stderr,"connect error:%s\n",strerror(errno));
		exit(1);
	}


	while(1){
		printf("Please input char : ");
		fgets(buffer,1024,stdin);
		write(sockfd,buffer,strlen(buffer));

		if(strncmp(buffer,"end",3) == 0){
			break;
		}
	}
	close(sockfd);
	exit(0);
}
