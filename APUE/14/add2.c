#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>

#define MAXLINE 1024
int main(void)
{
	int n, int1, int2;
	char line[MAXLINE];

	while((n = read(STDIN_FILENO, line, MAXLINE)) > 0){
		line[n] = 0;
		if(sscanf(line, "%d,%d", &int1, &int2) == 2){
			sprintf(line, "%d\n", int1 + int2);
			n = strlen(line);
			if(write(STDOUT_FILENO, line, n) != n){
				perror("write");
				exit(EXIT_FAILURE);
			}
		}else {
			if(write(STDOUT_FILENO, "invald args\n", 13) != 13){
				perror("write");
				exit(EXIT_FAILURE);
			}
		}
	}
	exit(EXIT_SUCCESS);
}
