/********************************************
 * test for jmp_signal to solve the JingZheng
 * get you 10 seconds to input strings
 * if you inout the stirngs in 10 seconds, then clear the alarm
 * else you will jamp back to run the read fucntion
 *
 * */

#include<stdio.h>
#include<setjmp.h>
#include<signal.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>

/* MAXLINE to get the string */
#define MAXLINE 1024

static void		sig_alrm(int);/* the function of the signal ISGLARM */
static jmp_buf	env_alrm;	  /* setjmp fucntion use this to flag the jmaping position */

int main(void)
{
	int 	n;
	char	line[MAXLINE];

	/* set the function of ISGALRM */
	if(signal(SIGALRM, sig_alrm) == SIG_ERR){
		perror("signal SIGALRM");
		exit(EXIT_FAILURE);
	}

	/* set the jamp into env_alrm */
	if(setjmp(env_alrm) != 0){
		perror("setjmp");
		exit(EXIT_FAILURE);
	}

	printf("Begin read after 10 seconds ...\n");
	alarm(10);/* alarm 10 seconds */

	/* read string from termianl */
	if((n = read(STDIN_FILENO, line, MAXLINE)) < 0){
		perror("read");
		exit(EXIT_FAILURE);
	}
	alarm(0);/* clear alarm */
 
	exit(EXIT_SUCCESS);
}

static void sig_alrm(int signo)
{
	longjmp (env_alrm, 1);/* jamp back  */
}
