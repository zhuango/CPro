#include<stdio.h>
#include<stdlib.h>
#include<sys/wait.h>

#define MAXLINE 1024
int main(void)
{
	char line[MAXLINE];
	FILE *fpin;
	if((fpin = popen("a.out", "r")) == NULL){
		perror("popen");
		exit(EXIT_FAILURE);
	}
	for(;;){
		fputs("prompt> ", stdout);
		fflush(stdout);
		if(fgets(line, MAXLINE, fpin) == NULL){
			perror("fgets");
			exit(EXIT_FAILURE);
		}
		if(fputs(line, stdout) == EOF){
			perror("fputs");
			exit(EXIT_FAILURE);
		}
	}
	pclose(fpin);
	exit(EXIT_SUCCESS);
}
