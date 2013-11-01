#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<stdio.h>
#include<stdlib.h>

int main(void)
{
	char ftmp[] = "tmpXXXXXX";
	char buf[10];
	struct stat statbuf;
	int i,infd,outfd;

	if( (infd = open("devices.txt",O_RDONLY)) < 0){
		perror("open devices.txt");
		exit(EXIT_FAILURE);
	}
	if ( (outfd = mkstemp(ftmp)) < 0){
		perror("mkstmp");
		exit(EXIT_FAILURE);
	}
	printf("output file is %s\n",ftmp);

	lseek(infd,100,SEEK_SET);

	for(i = 0;i < 10;++i){
		read(infd,buf,10);
		write(outfd,buf,10);
		lseek(infd,90,SEEK_CUR);
	}
	fstat(outfd,&statbuf);
	printf("before ftruncate , %s is %ld bytes\n",ftmp,statbuf.st_size);
	ftruncate(outfd,statbuf.st_size / 2);
	fsync(outfd);
	fstat(outfd,&statbuf);
	printf("after ftruncate, %s is %ld bytes\n",ftmp,statbuf.st_size);
	close(infd);
	close(outfd);
	exit(EXIT_FAILURE);
}
