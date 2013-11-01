#include<stdio.h>
#include<stdlib.h>
#include<netinet/in.h>
#include<string.h>
#include<errno.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netdb.h>
#include<unistd.h>
#include<pthread.h>
#define portnumber 3333

void *create(void *fd){
	int nbytes;
	char buffer[1024];
	int *fdtmp = (int*) fd;
	int new_fd = *fdtmp;
	while(1){
		if( (nbytes = read(new_fd,buffer,1024)) == -1){
			fprintf(stderr,"read error: %s\n",strerror(errno));
			exit(EXIT_FAILURE);
		}
	
		buffer[nbytes] = '\0';
		printf("Server received from (%d) %s \n",new_fd,buffer);

		if(strncmp(buffer,"end",3) == 0){
			break;
		}
	}
	close(new_fd);

	return NULL;
}

int main(int argc, char **argv){

	int sin_size;
	int nbytes;
	int sockfd, new_fd;
	struct sockaddr_in server_addr;
	struct sockaddr_in client_addr;
	pthread_t pthread;

	if( ( sockfd = socket(AF_INET,SOCK_STREAM,0) ) == -1){
		fprintf(stderr,"create socket error; %s\n",strerror(errno));
		exit(EXIT_FAILURE);
	}

	bzero(&server_addr,sizeof(struct sockaddr_in));

	server_addr.sin_family = AF_INET;
	server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
	server_addr.sin_port = htons(portnumber);

	if( bind(sockfd,(struct sockaddr *)(&server_addr),sizeof(struct sockaddr)) == -1){
		fprintf(stderr,"Bind error: %s\n",strerror(errno));
		exit(EXIT_FAILURE);
	}

	if( listen(sockfd,5) == -1){
		fprintf(stderr,"listen error: %s\n",strerror(errno));
		exit(EXIT_FAILURE);
	}

	printf("listening...\n");
	while(1){

		sin_size = sizeof(struct sockaddr_in);

		if( (new_fd = accept(sockfd,(struct sockaddr*)(&client_addr),&sin_size)) == -1){
			fprintf(stderr,"accept error: %s\n",strerror(errno));
			exit(EXIT_FAILURE);
		}
		
		fprintf(stdout ,"Server get connection from %s\n",inet_ntoa(client_addr.sin_addr));
		
		if(pthread_create(&pthread,NULL,create,&new_fd) == -1){
			fprintf(stderr,"create thread failed\n");
			close(new_fd);
			exit(1);
		}

	}

	close(sockfd);

	exit(0);
}
