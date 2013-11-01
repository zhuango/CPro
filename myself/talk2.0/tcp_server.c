#include<stdlib.h>
#include<stdio.h>
#include<errno.h>
#include<string.h>
#include<netdb.h>
#include<sys/types.h>
#include<netinet/in.h>
#include<sys/socket.h>
#include<pthread.h>
#include<sys/wait.h>

#define poernumber 3333
#define portnumber2 2224
#define WORDS 1024


char buffer[WORDS];
int new_fd[5];
void *thr_fd1(void*);
struct th_ma{
	int sockfd;
	pthread_t tid;
};

int portAdd = 0;
void *thr_connect(void *arg){
	int sockfd;
	struct sockaddr_in server_addr;
	struct hostent *host;
	pthread_t tid;
	char *argv = (char*)arg;

	if( (host = gethostbyname(argv)) == NULL){
		fprintf(stderr,"Gethostname error\n");
		exit(EXIT_FAILURE);
	}

	if( (sockfd = socket(AF_INET,SOCK_STREAM,0)) == -1){
		fprintf(stderr,"Socket Error: \n");
		exit(EXIT_FAILURE);
	}

	bzero(&server_addr, sizeof(server_addr));
	server_addr.sin_family = AF_INET;
	server_addr.sin_port = htons(portnumber2 + portAdd);
	portAdd++;

	server_addr.sin_addr = *((struct in_addr *)host->h_addr);

	if(connect(sockfd,(struct sockaddr*)(&server_addr),sizeof(struct sockaddr)) == -1){
		fprintf(stderr,"(child)Connect Error %s\n",strerror(errno));
		exit(EXIT_FAILURE);
	}

	if ( (pthread_create(&tid,NULL,thr_fd1,&sockfd)) == -1){
		fprintf(stderr,"pthread create error\n");
		exit(EXIT_FAILURE);
	}
	while(1);


}

void *thr_fd1(void *arg){
	char bufferS[WORDS];
	int *parg = (int *)arg;

	while(1){
		memset(bufferS,0,WORDS);

		fgets(bufferS,WORDS,stdin);
		send(*parg,bufferS,strlen(bufferS),0);
		if(bufferS[0] == '@' )
			break;
	}
	close(*parg);

}
void *thr_fn(void *arg){
	int nbytes,j;
	struct th_ma *pth = (struct th_ma*) arg;
	int parg = pth->sockfd;

	printf("new_fd = %d\n",parg);
	while((nbytes = read(parg, buffer,WORDS)) > 0){
		if(buffer[0] == '@'){
			pthread_cancel(pth->tid);
			break;
		}
		printf("Message from client(%d): %s\n",parg,buffer);
		//for(j=0;j<nbytes;j++)
		//	buffer[j] = toupper(buffer[j]);
		write(parg , buffer,nbytes);
		memset(buffer,0,WORDS);
	}

	close(parg);
	printf("User %d was out of line\n",parg);
	return 0;
}
int main(int argc , char **argv){

	pthread_t tid[5];
	struct th_ma Thread[5];
	int sockfd ;
	struct sockaddr_in server_addr;
	struct sockaddr_in client_addr[5];
	int sin_size;
	int nbytes;
	int i = 0,n = 0;

	if( (sockfd = socket(AF_INET,SOCK_STREAM,0)) == -1){
		fprintf(stderr,"Socket error: %s\n\a",strerror(errno));
		exit(EXIT_FAILURE);
	}

	bzero(&server_addr , sizeof(struct sockaddr_in));
	server_addr.sin_family = AF_INET;
	server_addr.sin_addr.s_addr = htonl(INADDR_ANY);

	server_addr.sin_port = htons(poernumber);

	if( bind(sockfd,(struct sockaddr *)(&server_addr) , sizeof(struct sockaddr)) == -1){
		fprintf(stderr,"Bind error:%s\n\a",strerror(errno));
		exit(EXIT_FAILURE);
	}

	printf("Listening ......\n");
	if( listen(sockfd,5) == -1){
		fprintf(stderr,"Listen error: %s\n\a",strerror(errno));
		exit(EXIT_FAILURE);
	}


	while(1){
		sin_size = sizeof(struct sockaddr_in);
		if( (new_fd[i] = accept(sockfd,(struct sockaddr*)(&client_addr[i]),&sin_size)) == -1){
			fprintf(stderr,"Accept error: %s\n\a",strerror(errno));
			exit(EXIT_FAILURE);
		}

		printf("Server get connextion from %s\n",inet_ntoa(client_addr[i].sin_addr));
//		printf("Server get connection from %s\n",inet_ntoa(client_addr[i].sin_addr));
		
		Thread[i].sockfd = new_fd[i];
		if( (pthread_create(&tid[n],NULL,thr_connect,argv[i+1])) == -1){
			fprintf(stderr,"pthread create error\n");
			exit(EXIT_FAILURE);
		}
		
		Thread[i].tid = tid[n];
		if( (pthread_create(&tid[n+1],NULL,thr_fn,&Thread[i])) == -1){
			perror("pthread_create error\n");
			close(sockfd);
			close(new_fd[i]);
			return 1;
		}
		n = n+2;
		i++;
	}

	close(sockfd);
	exit(EXIT_SUCCESS);
}
