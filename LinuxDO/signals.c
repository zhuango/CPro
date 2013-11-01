#include<stdio.h>
#include<signal.h>

#define INPUTLEN 100

int main(int argc, char *argv[])
{
	void inthandler(int);
	void quithandler(int);
	char input[INPUTLEN];
	int nchars;

	signal(SIGINT, inthandler);
	signal(SIGQUIT, quithandler);
	
	do{
		printf("\nType a message: \n");
		nchars = read(0, input, (INPUTLEN - 1));
		if(nchars == -1)
			perror("read returned a error");
		else{
			input[nchars] = '\0';
			printf("You type : %s\n",input);
		}
	}while(strncmp(input, "quit", 4) != 0);
}

void inthandler(int s)
{
	printf("\nReceived signal %d.. waiting\n",s);
	sleep(1);
	printf("Leavcing inthandler\n");
}

void quithandler(int s){
	printf("\nReceived signal %d .. waiting\n",s);
	sleep(5);
	printf("Leaving quithandler\n");
}
