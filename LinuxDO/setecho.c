#include<stdio.h>
#include<termios.h>
#include<stdlib.h>

#define oops(s,x) { perror(s);exit(x);}

int main(int argc, char **argv)
{
	struct termios info;
	if(argc == 1)/*get the arg from terminal*/
		exit(0);
	if(tcgetattr(0, &info) == -1)/*get the info of terminal*/
		oops("tcgetattr",1);

	if(argv[1][0] == 'y')/*if the first char of the second arg is 'y'*/
		info.c_lflag |= ECHO;
	else
		info.c_lflag &= ~ECHO;

	if(tcsetattr(0, TCSANOW, &info) == -1)
		oops("tcsetattr",2);
}
