#include<string.h>
#include<strings.h>
#include<stdio.h>
#include<stdlib.h>

#define BUFFER_SIZE 1024

int main(int argc, char **argv)
{
	FILE *from_fd;
	FILE *to_fd;

	long file_len = 0;
	char buffer[BUFFER_SIZE];
	char *ptr;

	if(argc != 3){
		printf("Usage : %s fromfile to file \n",argv[0]);
		exit(1);
	}

	if( ( from_fd = fopen(argv[1],"rb") ) == NULL){
		printf("Open %s Error\n",argv[1]);
		exit(1);
	}

	if( ( to_fd = fopen(argv[2],"wb" ) ) == NULL){
		printf("Open %s Error\n",argv[2]);
		exit(1);
	}

	fseek(from_fd,0L,SEEK_END);//the end
	file_len = ftell(from_fd);//the length of file
	fseek(from_fd,0L,SEEK_SET);//the start

	printf("from file size is = %d\n",file_len);//ouput the length of file

	while( !feof(from_fd) ){
		fread(buffer,BUFFER_SIZE,1,from_fd);

		if(BUFFER_SIZE >= file_len){
			fwrite(buffer,file_len,1,to_fd);
		}else{
			fwrite(buffer,BUFFER_SIZE,1,to_fd);
			file_len = file_len-BUFFER_SIZE;
		}
		bzero(buffer,BUFFER_SIZE);
	}

	fclose(from_fd);
	fclose(to_fd);
	exit(0);
}

