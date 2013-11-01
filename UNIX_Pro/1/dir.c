#include<stdio.h>
#include<stdlib.h>
#include<dirent.h>

void err_quit(char *);

int main(int argc,char **argv)
{
	DIR *dp;
	struct dirent *dirp;

	if(argc != 2){
		err_quit("usage: ls directory_name");
	}
	if((dp = opendir(argv[1])) == NULL){
		err_quit("can't open");
	}
	while((dirp = readdir(dp)) != NULL)
		printf("%s\n", dirp->d_name);

	closedir(dp);
	exit(EXIT_SUCCESS);
}

void err_quit(char *msg)
{
	perror(msg);
	exit(EXIT_FAILURE);
}
