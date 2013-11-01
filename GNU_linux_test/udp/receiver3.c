#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<netdb.h>
#include<errno.h>
#include<fcntl.h>

int port = 6789;

int main(void)
{
	int sin_len;
	char message[256];
	int socket_descriptor;
	struct sockaddr_in sin;
	int bind_rc, close_rc;
	ssize_t recv_rc;
	long save_file_flags;

	printf("Waiting for fata from sender\n");

	bzero(&sin,sizeof(sin));
	sin.sin_family = AF_INET;
	sin.sin_addr.s_addr = htonl(INADDR_ANY);
	sin.sin_port = htons(port);
	sin_len = sizeof(sin);

	socket_descriptor = socket(AF_INET,SOCK_DGRAM,0);
	if(socket_descriptor == -1){
		perror("socket create");
		exit(EXIT_FAILURE);
	}
	
	bind_rc = bind(socket_descriptor,(struct sockaddr*)&sin,
			sizeof(sin));
	if(bind_rc == -1){
		perror("bind call failed");
		exit(EXIT_FAILURE);
	}

	save_file_flags = fcntl(socket_descriptor , F_GETFL);
	printf("file falgs are %d\n",save_file_flags);
	save_file_flags |= O_NONBLOCK;
	if(fcntl(socket_descriptor,F_SETFL,save_file_flags) == -1){
		perror("trying ti set input socket to non_blocking");
		exit(EXIT_FAILURE);
	}

	printf("file flags are now %ld\n",save_file_flags);

	while(1){

		sleep(1);
		recv_rc = recvfrom(socket_descriptor,message,
				sizeof(message),0,(struct sockaddr*)&sin,&sin_len);
		if(recv_rc == -1 && errno != EAGAIN){
			fprintf(stderr,"errno %d",errno);
			perror("recvfrom call failed");
			exit(EXIT_FAILURE);
		}else if(recv_rc == 0 || errno == EAGAIN){
			printf("no data yet\n");
			errno = 0;
			continue;
		}

		errno = 0;
		printf("Response from server: %s\n",message);

		if(strncmp(message,"stop",4) == 0){
			printf("Sender has told me to end the connecton\n");
			break;
		}
	}

	close_rc = close(socket_descriptor);
	if(close_rc == -1){
		perror("close call failed");
		exit(EXIT_FAILURE);
	}

	exit(EXIT_SUCCESS);
}

