#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<strings.h>

#define BUFFER 1024

int main(int argc,char **argv){
	FILE *from_fd;
	FILE *to_fd;
	long file_len = 0;
	char buffer[BUFFER];
	char *ptr;

	if(argc != 3){
		printf("Usage: %s fromfile tofile \n",argv[0]);
		exit(1);
	}

	if( ( from_fd = fopen(argv[1],"rd") ) == NULL){
		printf("Open %s Error\n",argv[1]);
		exit(1);
	}

	if( ( to_fd = fopen(argv[2],"wb") ) == NULL ){
		printf("open %s Erro !\n",argv[2]);
		exit(1);
	}

	fseek(from_fd,0,SEEK_END);
	file_len = ftell(from_fd);
	fseek(from_fd,0,SEEK_SET);
	printf("from file size : %d\n",file_len);



	while( (!feof(from_fd))){

		fread(buffer,BUFFER,1,from_fd);

		if(BUFFER >= file_len){
			fwrite(buffer,file_len,1,to_fd);
		}else{
			fwrite(buffer,BUFFER,1,to_fd);
			file_len = file_len - BUFFER;
		}

		bzero(buffer,BUFFER);
	}

	fclose(from_fd);
	fclose(to_fd);
	exit(0);
}