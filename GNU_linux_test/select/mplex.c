#include<fcntl.h>
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>

#define BUFSZ 80

void err_quit(char *msg);

int main(void){

	int fds[2];
	char buf[BUFSZ];

	int i,rc,maxfd;

	fd_set watchset;
	fd_set inset;

	if( (fds[0] = open("pipe1",O_RDONLY | O_NONBLOCK)) < 0)
		err_quit("Open pipe1");
	if( (fds[1] = open("pipe2",O_RDONLY | O_NONBLOCK)) < 0)
		err_quit("Open pipe2");

	FD_ZERO(&watchset);
	FD_SET(fds[0],&watchset);
	FD_SET(fds[1],&watchset);

	maxfd = fds[0] > fds[1] ? fds[0] : fds[1];

	while(FD_ISSET(fds[0],&watchset) || FD_ISSET(fds[1],&watchset)){

		inset = watchset;
		if(select(maxfd + 1,&inset,NULL,NULL,NULL) < 0)
			err_quit("select");
		
		for(i = 0;i < 2;i++){
			if(FD_ISSET(fds[i],&inset)){
				rc = read(fds[i],buf,BUFSZ-1);
				if(rc > 0){
					buf[rc] = '\0';
					printf("read : %s\n",buf);
				}else if(rc == 0){
					close(fds[i]);
					FD_CLR(fds[i],&inset);
				}else
					err_quit("read");
			}
		}
	}
	exit(EXIT_SUCCESS);
}

void err_quit(char * msg){
	perror(msg);
	exit(EXIT_FAILURE);
}
