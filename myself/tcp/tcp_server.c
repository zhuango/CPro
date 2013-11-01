#include<stdlib.h>
#include<stdio.h>
#include<errno.h>
#include<string.h>
#include<netdb.h>
#include<sys/types.h>
#include<netinet/in.h>
#include<sys/socket.h>

#define portnumber 3333

int main(int argc,char **argv){

	int sockfd,new_fd;
	struct sockaddr_in server_addr;//address struct for server
	struct sockaddr_in client_addr;//address struct for client
	int sin_size;
	int nbytes;
	char buffer[1024];

	if( ( sockfd = socket(AF_INET,SOCK_STREAM,0)) == -1){//create socket
		fprintf(stderr,"Socket error: %s\n\a",strerror(errno));
		exit(1);
	}

	bzero(&server_addr,sizeof(struct sockaddr_in));//clean to 0
	server_addr.sin_family = AF_INET;////设置 协议族 
	server_addr.sin_addr.s_addr = htonl(INADDR_ANY);//设置网址

	server_addr.sin_port = htons(portnumber);//设置端口

	if( bind(sockfd,(struct sockaddr *)(&server_addr),sizeof(struct sockaddr)) == -1){//IP地址和端口号 与 套接字 的绑定
		fprintf(stderr,"Bind error:%s\n\a",strerror(errno));
		exit(1);
	}

	if( listen(sockfd,5) == -1){//设置允许最大连接数
		fprintf(stderr,"Listen error:%s\n\a",strerror(errno));
		exit(1);
	}

	while(1){
		sin_size = sizeof(struct sockaddr_in);
		if( (new_fd = accept(sockfd,(struct sockaddr*)(&client_addr),&sin_size)) == -1){//等待客户端请求
			fprintf(stderr,"Accpet error:%s\n\a",strerror(errno));
			exit(1);
		}
		fprintf(stderr,"Server get connection from %s\n",inet_ntoa(client_addr.sin_addr));//输出客户端网址
		if( ( nbytes = read(new_fd,buffer,1024)) == -1){//read from new_fd ，put the words into buffer
			fprintf(stderr,"Read Error:%s\n",strerror(errno));
			exit(1);
		}
		buffer[nbytes] = '\0';//set the end of string
		printf("Server received %s\n",buffer);//print the words from client

		close(new_fd);//shut down the net link
	}
	close(sockfd);//shut down the socket
	exit(0);
}
