#include<stdio.h>
#include<stdlib.h>
#include<utime.h>
#include<fcntl.h>
#include<unistd.h>

int main(int argc,char **argv)
{
	int i,fd;
	struct stat statbuf;
	struct utimbuf timebuf;

	for(i = 1;i < argc ;i++){
	
		if(stat(argv[i],&statbuf) < 0){
			perror("stat error");
			continue;
		}

		if((fd = open(argv[i],O_RDWR | O_TRUNC)) < 0){
			perror("open error");
			continue;
		}

		close(fd);
		timebuf.actime = statbuf.st_atime;
		timebuf.modtime = statbuf.st_mtime;

		if(utime(argv[i],&timebuf) < 0){
			perror("utime error");
			continue;
		}
	}

	exit(EXIT_SUCCESS);
}
