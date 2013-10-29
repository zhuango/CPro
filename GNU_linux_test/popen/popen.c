#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<limits.h>

#define BUFSZ PIPE_BUF

void err_quit(char *msg);

int main(void)
{
	FILE *fp;
	char *cmdstring = "cat popen.c";
	char buf[BUFSZ];

	if( (fp = popen(cmdstring,"r")) == NULL)
		err_quit("popen");

	while( ( fgets(buf,BUFSZ,fp)) != NULL)
		printf("%s",buf);

	pclose(fp);
	exit(EXIT_SUCCESS);
}

void err_quit(char *msg)
{
	perror(msg);
	exit(EXIT_FAILURE);
}
