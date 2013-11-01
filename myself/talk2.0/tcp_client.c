#include<stdlib.h>
#include<stdio.h>
#include<errno.h>
#include<string.h>
#include<sys/types.h>
#include<netdb.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<fcntl.h>

#define portnumber 3333 //poetnumber
#define portnumber2 2224
#define WORDS 1024


char buffer[1024];
void *pth_fn(void *);

void *pth_accept(void *arg){
	int sockfd ;
	int new_fd;
	struct sockaddr_in server_addr;
	struct sockaddr_in client_addr;
	int sin_size;
	int nbytes;
	pthread_t tid;

	if( (sockfd = socket(AF_INET,SOCK_STREAM,0)) == -1){
		fprintf(stderr,"Socket error\n");
		exit(EXIT_FAILURE);
	}

	bzero(&server_addr,sizeof(struct sockaddr_in));
	server_addr.sin_family = AF_INET;
	server_addr.sin_addr.s_addr = htonl(INADDR_ANY);

	server_addr.sin_port = htons(portnumber2);

	if( bind(sockfd , (struct sockaddr *)(&server_addr) , sizeof(struct sockaddr)) == -1){
		fprintf(stderr,"Bind error:%s\n\a",strerror(errno));
		exit(EXIT_FAILURE);
	}

	printf("Listening ......\n");

	if( listen(sockfd,5) == -1){
		fprintf(stderr,"Listen error:%s\n\a",strerror(errno));
		exit(EXIT_FAILURE);
	}

	sin_size = sizeof(struct sockaddr_in);
	if( (new_fd = accept(sockfd,(struct sockaddr*)(&client_addr),&sin_size)) == -1){
		fprintf(stderr,"(child)Accept error %s\n",strerror(errno));
		exit(EXIT_FAILURE);
	}
	if( (pthread_create(&tid,NULL,pth_fn,&new_fd)) == -1){
		fprintf(stderr,"pthread create error\n");
		exit(EXIT_FAILURE);
	}
	while(1);
}

void *pth_fn(void *sockfd){
	int size;
	int *psockfd = (int *) sockfd;
	while(1){

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

	int size;
	int sockfd;
	struct sockaddr_in server_addr;
	struct hostent *host;
	pthread_t tid[2];

	if(argc != 2){
		fprintf(stderr,"Usage : %s hostname\a\n",argv[0]);
		exit(EXIT_FAILURE);
	}

	printf("________%s___________\n",argv[1]);
	if( (host = gethostbyname(argv[1]) ) == NULL){
		fprintf(stderr,"Gethostname error\n");
		exit(EXIT_FAILURE);
	}

	if( (sockfd = socket(AF_INET,SOCK_STREAM,0) ) == -1){
		fprintf(stderr,"Socket Error: \n");
		exit(EXIT_FAILURE);
	}
//	if(0>fcntl(sockfd,F_SETFL,fcntl(sockfd,F_GETFL,0)|/*O_NDELAY*/O_NONBLOCK)){ 
// 		printf("fcntl failed\n"); 
//		return 1; 
//	} 

	bzero(&server_addr , sizeof(server_addr));
	server_addr.sin_family = AF_INET;
	server_addr.sin_port = htons(portnumber);

	server_addr.sin_addr = *((struct in_addr *) host->h_addr);

	if(connect(sockfd,(struct sockaddr*)(&server_addr),sizeof(struct sockaddr)) == -1){
		fprintf(stderr,"Connect Error: %s\a\n",strerror(errno));
		exit(EXIT_FAILURE);
	}

	if( (pthread_create(&tid[0],NULL,pth_accept,&sockfd)) == -1){
		fprintf(stderr,"pthread create error\n");
		exit(EXIT_FAILURE);
	}

	while(1){
		fgets(buffer,1024,stdin);
		write(sockfd,buffer,strlen(buffer));
		if(buffer[0] == '@')
			break;
		memset(buffer,0,WORDS);
	}
	close(sockfd);
	exit(EXIT_SUCCESS);
}
