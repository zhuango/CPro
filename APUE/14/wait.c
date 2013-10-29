#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

static int pfd1[2], pfd2[2];
void TELL_WAIT(void)
{
	if(pipe(pfd1) < 0 || pipe(pfd2) < 0){
		perror("pipe");
		exit(EXIT_FAILURE);
	}
}

void TELL_PARENT(pid_t pid)
{
	if(write(pfd2[1], "c", 1) < 0){
		perror("tell parent");
		exit(EXIT_FAILURE);
	}
}

void WAIT_PARENT(void)
{
	char c;
	if(read(pfd1[0], &c, 1) < 0){
		perror("WAIT_PARENT");
		exit(EXIT_FAILURE);
	}
	if(c != 'p'){
		perror("WAIT_PARENT error");
		exit(EXIT_FAILURE);
	}
}

void TELL_CHILD(pid_t pid)
{
	if(write(pfd1[1], "p", 1) < 0){
		perror("write");
		exit(EXIT_FAILURE);
	}
}

void WAIT_CHILD(void)
{
	char c;
	if(read(pfd2[0], &c, 1) < 0){
		perror("WAIT_CHILD");
		exit(EXIT_FAILURE);
	}
	if(c != 'c'){
		perror("WAIT_CHILE error");
		exit(EXIT_FAILURE);
	}
}
int main(void){}
