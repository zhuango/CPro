#include<sys/stat.h>
#include<sys/types.h>
#include<stdio.h>
#include<stdlib.h>

int main(void)
{
	struct stat info;
	int e;

	if((e = stat("more.c",&info)) == -1){
		perror("stat error");
		exit(EXIT_FAILURE);
	}
	printf("/dev/passwd/ size : %d\n",info.st_size);

	exit(EXIT_SUCCESS);
}
