#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>

int main(void)
{
	int c;
	while((c = getchar()) != EOF){
		if(isupper(c)){
			c = tolower(c);
		}
		if(putchar(c) == EOF){
			perror("putchar");
			exit(EXIT_FAILURE);
		}
		if(c == '\n'){
			fflush(stdout);
		}
	}
	exit(EXIT_SUCCESS);
}
