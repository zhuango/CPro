#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>

void create_file(char *filename){
	if(creat(filename,0666) < 0){
		printf("shawanyi\n");
		exit(EXIT_FAILURE);
	}else{
		printf("create file %s success!\n",filename);
	}
}

int main(int argc , char *argv[]){
	int i=0;
	if(argc < 2){
		printf("you haven't input filename!\n");
		exit(EXIT_FAILURE);
	}

	for(i=1;i<argc;i++){
		create_file(argv[i]);
	}

	return 0;
}
