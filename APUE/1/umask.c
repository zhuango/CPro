#include<sys/stat.h>
#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>

#define RWRWRW (S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH)

int main(void)
{
	umask(0);
	if(creat("foo",RWRWRW) < 0){
		perror("creat error");
		exit(EXIT_FAILURE);
	}

	umask(S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH);

	if(creat("bar",RWRWRW) < 0){
		perror("creat error 2");
		exit(EXIT_FAILURE);
	}

	exit(EXIT_SUCCESS);
}

