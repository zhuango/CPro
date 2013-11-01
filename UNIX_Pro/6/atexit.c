#include<stdio.h>
#include<stdlib.h>
static void my_exit1();
static void my_exit2();

int main(void)
{
	if(atexit(my_exit2) != 0){
		perror("atexit error");
		exit(EXIT_FAILURE);
	}
	if(atexit(my_exit1) != 0){
		perror("at exit1 error");
		exit(EXIT_FAILURE);
	}
	if(atexit(my_exit1) != 0){
		perror("at exit1 error");
		exit(EXIT_FAILURE);
	}

	printf("main is done\n");

	//return 0;
	exit(0);
}

static void my_exit1(void)
{
	printf("first exit handler\n");
}

static void my_exit2(void)
{
	printf("second exit handler\n");
}

