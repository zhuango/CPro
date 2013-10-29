#include<stdio.h>
#include<stdlib.h>
#include<signal.h>
#include<unistd.h>
#include<termios.h>

void err_quit(char *msg);
void err_reset(char *msg, struct termios *flags);
static void sig_caught(int signum);

int main(void)
{
	struct termios new_flags, old_flags;
	int i, fd;
	char c;

	if(signal(SIGINT, sig_caught) == SIG_ERR){
		err_quit("failed to set up SIGINT handler");
	}

	if(signal(SIGQUIT, sig_caught) == SIG_ERR){
		err_quit("Failed to set up SIGQUIT handler");
	}

	if(signal(SIGTERM, sig_caught) == SIG_ERR){
		err_quit("Failed to set up SIGQUIT handler");
	}

	fd = fileno(stdin);

	tcgetattr(fd, &old_flags);

	new_flags = old_flags;
	new_flags.c_lflag &= ~(ECHO | ICANON | ISIG);
	new_flags.c_iflag &= ~(BRKINT | ICRNL);
	new_flags.c_oflag &= ~OPOST;
	new_flags.c_cc[VTIME] = 0;
	new_flags.c_cc[VMIN] = 1;
	if(tcsetattr(fd, TCSAFLUSH, &new_flags) < 0)
		err_reset("Failed to change attributes", &old_flags);

	puts("In RAW mode , Press DELETE key to exit");
	while((i = read(fd, &c, 1)) == 1){
		if((c &= 255) == 0177){
			break;
		}
		printf("%o\n",c);
	}

	tcsetattr(fd, TCSANOW, &old_flags);
}

void sig_caught(int signum)
{
	printf("signal caught: %d\n",signum);
}

void err_quit(char *msg){
	fprintf(stderr,"%s\n",msg);
	exit(EXIT_FAILURE);
}

void err_reset(char *msg, struct termios *flags)
{
	fprintf(stderr,"%s\n",msg);
	tcsetattr(fileno(stdin), TCSANOW, flags);
	exit(EXIT_FAILURE);
}
