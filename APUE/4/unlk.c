#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>

int main(int argc, char **argv)
{
	if(open("tmpfile",O_RDWR) < 0){
		perror("open");
		exit(EXIT_FAILURE);
	}

	if(unlink("tmpfile") < 0){
		perror("unlink");
		exit(EXIT_FAILURE);
	}
	printf("file unlinked\n");
	sleep(15);
	printf("done\n");

	return 0;
}
