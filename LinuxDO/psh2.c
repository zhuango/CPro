#include<stdio.h>
#include<stdlib.h>
#include<signal.h>
#include<string.h>
#include<malloc.h>

#define MAXARGS	20
#define ARGLEN	100

void execute(char *arglist[]);
char *makestring(char *);

int main(void)
{
	char *arglist[MAXARGS+1];	/* the command arg */
	int numargs;				/* count args of the command */
	char argbuf[ARGLEN];		/* the buffer of the command */
	char *markstring();			/* one of the arg of the command */

	numargs = 0;				/* count the arg, clear to 0*/

	/* the GUI of the command */
	while(numargs < MAXARGS)
	{
		printf("Arg[%d]? ", numargs);							/* print the head */
		if(fgets(argbuf, ARGLEN, stdin) && argbuf[0] != '\n')	/* get the command */
			arglist[numargs ++] = makestring(argbuf);			/* get one arg of the command */
		else{
			if(numargs > 0){
				arglist[numargs] = NULL;
				execute(arglist);								/* execute the command */
				numargs = 0;
			}
		}
	}

	return 0;
}

/* the function executing the command */
void execute (char *arglist[])
{
	int pid, exitstatus;

	pid = fork();		/* create a new process*/
	
	switch(pid)
	{
		case -1:
			perror("fork");
			exit(EXIT_FAILURE);
		case 0:			/* child process */
			execvp(arglist[0],arglist);
			perror("execvp");
			exit(EXIT_FAILURE);
		default:		/* parent process */
			while(wait(&exitstatus) != pid)/* wait the child to exit */
				;

			/* print info the child exit */
			printf("child exited with status %d, %d\n",exitstatus>>8, exitstatus & 0377);
	}
}

char *makestring(char *buf)
{
	char *p;
	buf[strlen(buf) - 1] = '\0';		/* make the end */
	p = malloc(strlen(buf) + 1);		/* get the space for the command */
	if(p == NULL){
		fprintf(stderr, "no memory\n");	/* get the spcae error */
		exit(EXIT_FAILURE);
	}
	
	strcpy(p,buf);						/* copy the string to the new string, and return */
	return p;
}

