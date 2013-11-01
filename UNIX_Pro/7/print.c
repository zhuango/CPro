#include<stdio.h>
#include<stdlib.h>

int main(void)
{
	printf("real uid = %d, effective uid = %d\n", getuid(), geteuid());
	exit(EXIT_SUCCESS);
}
