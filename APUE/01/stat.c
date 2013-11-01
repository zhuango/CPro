#include<stdio.h>
#include<sys/stat.h>
#include<stdlib.h>

int main(int argc, char *argv[])
{
	int i;
	struct stat buf;
	char *ptr;

	if(argc < 2){
		printf("Usage: %s filename\n",argv[0]);
		exit(EXIT_FAILURE);
	}
	for(i = 1; i < argc; i++){

		printf("%s: ",argv[i]);
		if(lstat(argv[i],&buf) < 0){
			perror("lstat");
			exit(EXIT_FAILURE);
		}
		if(S_ISREG(buf.st_mode))
			ptr = "regular";
		else if(S_ISDIR(buf.st_mode))
			ptr = "directory";
		else if(S_ISCHR(buf.st_mode))
			ptr = "character special";
		else if(S_ISBLK(buf.st_mode))
			ptr = "block special";
		else if(S_ISFIFO(buf.st_mode))
			ptr = "fifo";
		else if(S_ISLNK(buf.st_mode))
			ptr = "link";
		else if(S_ISSOCK(buf.st_mode))
			ptr = "socket";

		printf("%s\n",ptr);
	}

	return 0;
}
