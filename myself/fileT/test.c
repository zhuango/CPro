#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>

int main(void)
{
	printf("%ld\n", sysconf(_PC_NAME_MAX));
}
