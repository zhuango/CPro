#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<string.h>
#define BUFFER 1024

int main(int argc,char **argv){
	int from_fd;
	int to_fd;
	char buf[BUFFER];
	int nread;
	long file_len,file;
	if(argc != 3){
		printf("Usage:%s fromfilr tofile\n",argv[0]);
		exit(EXIT_FAILURE);
	}

	if( ( from_fd = open(argv[1],O_RDONLY,0 ) ) < 0){
		printf("open file %s Error\n",argv[1]);
		exit(EXIT_FAILURE);
	}

	if( ( to_fd = open(argv[2],O_RDWR | O_CREAT,0755)) <0 ){
			printf("open file %s Error\n",argv[2]);
			exit(EXIT_FAILURE);
	}

	file_len  = lseek(from_fd,0,SEEK_END);
	file = file_len;
	lseek(from_fd,0,SEEK_SET);
	
	while( file != lseek(from_fd, 0 ,SEEK_CUR) ) {
		if( (nread = read(from_fd,buf,BUFFER) ) < 0){
			printf("read error");
		}else if (BUFFER > file_len){
			write(to_fd,buf,file_len);
			printf("write %d from %s\n",nread,argv[1]);
		}else{
			write(to_fd,buf,BUFFER);
			file_len = file_len - BUFFER;
			printf("write %d from %s\n",nread,argv[1]);
		}

		bzero(buf,BUFFER);
	}

	close(from_fd);
	close(to_fd);

	return 0;
}
