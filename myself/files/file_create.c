#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>

void create_file(char *filename){
	if(creat(filename, 0666) < 0){
		printf("create file %s failure!\n",filename);
		exit(EXIT_FAILURE);
	}else{
		printf("create file %s success!\b",filename);
	}
}

int main(int argc ,char **argv){
	if(argc < 2){
		printf("you haven't input the filename ,please try again!\n");
		exit(EXIT_FAILURE);
	}

	create_file(argv[1]);
	exit(EXIT_FAILURE);
}
