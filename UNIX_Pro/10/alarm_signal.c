#include<stdio.h>
#include<signal.h>
#include<stdlib.h>
void print_message(int signum);
void print_message2(int signum);

int main(void)
{
	signal(SIGUSR1, print_message);
	signal(SIGUSR2, print_message2);
	while(1);
	return 0;
}

void print_message(int signum)
{
	printf("SIGUSR1 happend!\n");
	exit(0);
}

void print_message2(int signum)
{
	printf("SIGUSR2 happend!\n");
	exit(0);
}
