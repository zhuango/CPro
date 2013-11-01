#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAXLINE 1024
void *Fgets(char *buff, int maxline, FILE *sin)
{
	if(fgets(buff, maxline, sin) < 0){
		perror("fgets");
		exit(EXIT_FAILURE);
	}
}
void Fputs(char *buff, FILE *sout)
{
	if(fputs(buff, sout) < 0){
		perror("fputs");
		exit(EXIT_FAILURE);
	}
}
FILE *Popen(const char *command, const char *type)
{
	FILE *fp;
	if((fp = popen(command, type)) == NULL){
		perror("popen");
		exit(EXIT_FAILURE);
	}
	return (fp);
}
void Pclose(FILE *fp)
{
	if(pclose(fp) < 0){
		perror("pclose");
		exit(EXIT_FAILURE);
	}
}

int main(int argc, char *argv[])
{
	size_t 	n;
	char 	buff[MAXLINE], command[MAXLINE];
	FILE 	*fp;

	Fgets(buff, MAXLINE, stdin);/* get the filename */
	n = strlen(buff);/* filename length */
	if(buff[n-1] == '\n'){/* Cut the '\n' */
		n--;/* length reduce 1 */
	}
	snprintf(command, sizeof(command), "cat %s", buff);/* print the commanf to value command */
	fp = Popen(command, "r");/* create a new process
				and create pipe type is read, the new process's stdout is pointer to pipe's write*/

	//while(Fgets(buff, MAXLINE, fp) != NULL){/* get info from pipe */
//		Fputs(buff, stdout);/* print to stdout */
//	}
	Pclose(fp);/* close IO and wait for the child process */

	exit(EXIT_FAILURE);
}
