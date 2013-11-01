#include<stdlib.h>
#include<stdio.h>
#include<errno.h>
#include<string.h>
#include<sys/types.h>
#include<netdb.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<fcntl.h>

#define portnumber 3333 //portnumber use to connect the server
#define portnumber2 2224//use to accept client
#define WORDS 1024


char buffer[1024];
void *pth_fn(void *);

void *pth_accept(void *arg){
	int sockfd ;//socket for "server"
	int new_fd;//user accept the client
	struct sockaddr_in server_addr;//the network address of server
	struct sockaddr_in client_addr;//the network address of client
	int sin_size;//the size of network address
	pthread_t tid;//use to create pthread to run the message receiving

	/*create socket*/
	if( (sockfd = socket(AF_INET,SOCK_STREAM,0)) == -1){
		fprintf(stderr,"Socket error\n");
		exit(EXIT_FAILURE);
	}

	/*set the network type , address , portnumber*/
	bzero(&server_addr,sizeof(struct sockaddr_in));
	server_addr.sin_family = AF_INET;
	server_addr.sin_addr.s_addr = htonl(INADDR_ANY);

	server_addr.sin_port = htons(portnumber2);

	/*bind the socket to the network address*/
	if( bind(sockfd , (struct sockaddr *)(&server_addr) , sizeof(struct sockaddr)) == -1){
		fprintf(stderr,"Bind error:%s\n\a",strerror(errno));
		exit(EXIT_FAILURE);
	}

	printf("Listening ......\n");

	/*listen*/
	if( listen(sockfd,5) == -1){
		fprintf(stderr,"Listen error:%s\n\a",strerror(errno));
		exit(EXIT_FAILURE);
	}

	sin_size = sizeof(struct sockaddr_in);

	/*wait for the client */
	if( (new_fd = accept(sockfd,(struct sockaddr*)(&client_addr),&sin_size)) == -1){
		fprintf(stderr,"(child)Accept error %s\n",strerror(errno));
		exit(EXIT_FAILURE);
	}
	/*accept the client ,then create pthread to run the message receiving*/
	if( (pthread_create(&tid,NULL,pth_fn,&new_fd)) == -1){
		fprintf(stderr,"pthread create error\n");
		exit(EXIT_FAILURE);
	}
	while(1);//give the time to run the pthread
}

void *pth_fn(void *sockfd){
	int size;//size of receive message
	int *psockfd = (int *) sockfd;//get the socket
	while(1){
		/*receiving message */
		size = recv(*psockfd,buffer,WORDS,0);
		if(buffer[0] == '@'){
			printf("User %d is out of line!!!\n",*psockfd);
			break;
		}
		if(size > 0 ){
			printf("message from server: %s\n",buffer);
			memset(buffer,0,WORDS);
		}
	}

}
int main(int argc , char **argv){

	int sockfd;//socket for server
	struct sockaddr_in server_addr;//network address of server
	struct hostent *host;//network address of client
	pthread_t tid;//thread to run the "server" part

	/*be true the client address have been input*/
	if(argc != 2){
		fprintf(stderr,"Usage : %s hostname\a\n",argv[0]);
		exit(EXIT_FAILURE);
	}
	/*get the network address of client*/
	if( (host = gethostbyname(argv[1]) ) == NULL){
		fprintf(stderr,"Gethostname error\n");
		exit(EXIT_FAILURE);
	}
	/*create socket*/
	if( (sockfd = socket(AF_INET,SOCK_STREAM,0) ) == -1){
		fprintf(stderr,"Socket Error: \n");
		exit(EXIT_FAILURE);
	}
	bzero(&server_addr , sizeof(server_addr));
	/*set the network address of server*/
	server_addr.sin_family = AF_INET;
	server_addr.sin_port = htons(portnumber);
	server_addr.sin_addr = *((struct in_addr *) host->h_addr);
	/*wait for connecting the server*/
	if(connect(sockfd,(struct sockaddr*)(&server_addr),sizeof(struct sockaddr)) == -1){
		fprintf(stderr,"Connect Error: %s\a\n",strerror(errno));
		exit(EXIT_FAILURE);
	}
	/*if connecton successed then create pthread to run the "server" part to accept server connection*/
	if( (pthread_create(&tid,NULL,pth_accept,&sockfd)) == -1){
		fprintf(stderr,"pthread create error\n");
		exit(EXIT_FAILURE);
	}
	/*send message to server*/
	while(1){
		fgets(buffer,1024,stdin);
		write(sockfd,buffer,strlen(buffer));
		if(buffer[0] == '@')
			break;
		memset(buffer,0,WORDS);
	}
	/*close the socket*/
	close(sockfd);
	exit(EXIT_SUCCESS);
}
