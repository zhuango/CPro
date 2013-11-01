#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<sys/ipc.h>

int main(void)
{
	printf("%d \n", sizeof(key_t));
	exit(EXIT_SUCCESS);
}
