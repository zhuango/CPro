#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<sys/times.h>

int main(void)
{
	FILE *fd;
	int n,i;
	struct timeval start, end;
	gettimeofday(&start, NULL);

	fd = fopen("C_write", "w+");

	for(i = 0; i < 1000000; i++){
		fprintf(fd, "sfawfdsaqww\n");
	}
	gettimeofday(&end,NULL);
	printf("%d.%d s\n", end.tv_sec - start.tv_sec, end.tv_usec - start.tv_usec);
	exit(EXIT_FAILURE);
}
