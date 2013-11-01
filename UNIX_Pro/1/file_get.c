#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>

void err_quit(char *);

int main(void)
{
	int c;

	while((c = getc(stdin)) != EOF)
		if(putc(c,stdout) == EOF)
			err_quit("output error");
	if(ferror(stdin))
		err_quit("input error");
	
	exit(EXIT_SUCCESS);
}

void err_quit(char *msg)
{
	perror(msg);
	exit(EXIT_FAILURE);
}
