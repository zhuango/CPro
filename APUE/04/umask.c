#include<sys/stat.h>
#include<stdio.h>
#include<stdlib.h>

#define WRWRWR	(S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH)

int main(int argc, char **argv)
{
	if(creat("Liu", WRWRWR) < 0){
		perror("create");
		exit(EXIT_FAILURE);
	}
	umask(S_IRGRP | S_IWGRP | S_IWOTH | S_IROTH);
	if(creat("ZHang", WRWRWR) < 0){
		perror("creat2");
		exit(EXIT_FAILURE);
	}

	return 0;
}
