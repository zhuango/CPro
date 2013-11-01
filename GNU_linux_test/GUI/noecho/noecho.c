#include<stdio.h>
#include<stdlib.h>
#include<termios.h>

#define PASS_LEN 8

void err_quit(char *msg, struct termios flags);

int main(void)
{
	struct termios old_flags,new_flags;
	char password[PASS_LEN  + 1];
	int retval;

	tcgetattr(fileno(stdin),&old_flags);
	new_flags = old_flags;

	new_flags.c_lflag &= (~ECHO);
	new_flags.c_lflag |= ECHONL;

	/*TCSAFLUSH mean when the message has send to terminl */
	retval = tcsetattr(fileno(stdin), /*TCSAFLUSH*/TCSANOW, &new_flags);
	if(retval != 0)
		err_quit("Failed to set sttributes ",old_flags);

	/*check the change is happend???*/
	tcgetattr(fileno(stdin),&new_flags);

	if(new_flags.c_lflag & ECHO){
		err_quit("Failed to turn off ECHO",old_flags);
	}

	if(!new_flags.c_lflag & ECHONL){
		err_quit("Failed to turn on ECHONL",old_flags);
	}

	printf("Enter password: ");
	fgets(password,PASS_LEN + 1,stdin);
	printf("You typed : %s\n",password);

	tcsetattr(fileno(stdin),TCSANOW,&old_flags);

	exit(EXIT_FAILURE);
}

void err_quit(char *msg, struct termios flags)
{
	fprintf(stderr,"%s\n",msg);
	tcsetattr(fileno(stdin), TCSANOW,&flags);
	exit(EXIT_FAILURE);
}
