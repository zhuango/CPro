#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<string.h>
#include<unistd.h>
#define MAXLINE 1024

void Fgets(char *, int, FILE*);

void client(int readfd, int writefd)
{
	size_t 	len;
	ssize_t n;
	char buff[MAXLINE];
	printf("Please input a pathname\n");
	Fgets(buff, MAXLINE, stdin);/* Input pathname */
	len = strlen(buff);
	if(buff[len - 1] == '\n')/* Eat the '\n' */
		len--;/* Reduce length of filename */
	Write(writefd, buff, len);/* write to server(child) */

	while((n = Read(readfd, buff, MAXLINE)) > 0)/* Read from server(chile) */
		Write(STDOUT_FILENO, buff, n);
}

void Fgets(char *buff, int maxline, FILE *Stdin)
{
	if(fgets(buff, maxline, Stdin) < 0){
		perror("fgets");
		exit(EXIT_FAILURE);
	}
}
