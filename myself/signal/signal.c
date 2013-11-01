#include<signal.h>
#include<stdio.h>
#include<stdlib.h>

void my_func(int sign_no){
	if(sign_no == SIGBUS){
		printf("I have get SIGBUS\n");
	}
}

int main(){
	printf("Waiting for signal SIGBUS\n");

	signal(SIGBUS,my_func);
	pause();
	exit(0);
}

