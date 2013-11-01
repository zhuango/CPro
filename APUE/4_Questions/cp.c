#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/stat.h>

/*use to & the Permission bits*/
#define WRX  (S_IRUSR | S_IWUSR | S_IXUSR | S_IRGRP | S_IWGRP | S_IXGRP | S_IROTH | S_IWOTH | S_IXOTH)

int main(int argc, char *argv[])
{
	int fd,fd_copy;//fd for the oldfile,fd_copy for the copy
	char chr;//read char from oldfile
	struct stat statbuf;//information of oldfile(use the Permission bits)

	if(argc != 3){
		printf("Usage:%s filename copyname\n",argv[0]);
		exit(EXIT_FAILURE);
	}

	/*open the file I want to copy*/
	if((fd = open(argv[1],O_RDONLY)) < 0){
		perror("open");
		exit(EXIT_FAILURE);
	}

	/*get the information of the file I want to copy*/
	fstat(fd,&statbuf);

	/*create the copy (and the Permission, if exist ,then exit*/
	if((fd_copy = open(argv[2],O_WRONLY | O_CREAT | O_EXCL,(statbuf.st_mode & WRX))) < 0){
		printf("file %s is exeist\n", argv[2]);
		exit(EXIT_FAILURE);
	}
	/*write the chars to copy*/
	while(read(fd,&chr,1) != 0){

		/*forget the hole*/
		if(chr != '\0'){
			if(write(fd_copy,&chr,1) < 0){
				perror("write error");
				exit(EXIT_FAILURE)
			};
	}

	/*exit*/
	exit(EXIT_SUCCESS);
}
