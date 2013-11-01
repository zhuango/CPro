#include<stdio.h>
#include<stdlib.h>

void f_atexit(void)
{
	puts("This message from f_atexit()");
}

int main(void)
{
	puts("This message from main()");
	if(atexit(f_atexit) != 0){
		fprintf(stderr,"Failed to register f_atexit()\n");
		exit(EXIT_FAILURE);
	}

	puts("Exiting...");
	exit(EXIT_SUCCESS);
}
