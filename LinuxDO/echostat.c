/*
 *echostat.c
 *
 */
#include<stdlib.h>
#include<stdio.h>
#include<termios.h>

int main(void)
{
	struct termios info;/*a value of struct termios to get the info of the terminal*/
	int rv;

	rv = tcgetattr(0, &info);/*get the dvirer of terminal info, put them into into info*/
	if(rv == -1){/*Is there a error???*/
		perror("tcgetattr");
		exit(EXIT_FAILURE);
	}

	if(info.c_lflag & ECHO)/*Was the echo bit set???*/
		printf("echo is on, since its bit is 1 \n");
	else
		printf("echo is OFF, since its bit is 0\n");

	return 0;
}
