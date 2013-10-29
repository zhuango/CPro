#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>

int main(int argc, char **argv){
//	if(argc < 2){
//		perror("you haven't input hte filename ,please try again!\n");
//		exit(EXIT_FAILURE);
//	}
	if(execl("/bin/ls","ls",NULL) < 0){
		perror("execl error\n");
	}

	return 0;
}
