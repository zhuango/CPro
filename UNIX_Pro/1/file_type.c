#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/stat.h>

int main(int argc,char *argv[])
{
	int i;//counter
	struct stat buf;//create the struct of information files
	char *ptr;//get the type of file into here

	for(i = 1;i < argc;i++){//get the file names from the terminal
		printf("%s: ",argv[i]);
		if(lstat(argv[i],&buf) < 0){//get the infomation of files
			perror("lastat error");
			continue;
		}

		/*know the type of files*/
		if(S_ISREG(buf.st_mode))
			ptr = "regular";
		else if(S_ISDIR(buf.st_mode))
			ptr = "directory";
		else if(S_ISCHR(buf.st_mode))
			ptr = "character spectial";
		else if(S_ISBLK(buf.st_mode))
			ptr = "block spectial";
		else if(S_ISFIFO(buf.st_mode))
			ptr = "fifo";
		else if(S_ISLNK(buf.st_mode))
			ptr = "symbolic link";
		else if(S_ISSOCK(buf.st_mode))
			ptr = "socket";
		else 
			ptr = "**unknow mode **";

		printf("%s\n",ptr);//output the type of files
	}

	exit(EXIT_SUCCESS);//exit
}
