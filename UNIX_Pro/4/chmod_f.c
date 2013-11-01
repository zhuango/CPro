#include<stdio.h>
#include<stdlib.h>
#include<sys/stat.h>

int main()
{
	struct stat		statbuf;

//	if(creat("foo", S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH) < 0){
//		perror("creat");
//		exit(EXIT_FAILURE);
//	}
	if(stat("foo",&statbuf) < 0){
		perror("stat");
		exit(EXIT_FAILURE);
	}

	if(chmod("foo",S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH) < 0){
		perror("chmod");
		exit(EXIT_FAILURE);
	}

	return 0;
}
