#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
	char buf[1024] = "sdf";
	printf("%d\n", buf);
	printf("%d\n", sizeof(buf));
	printf("%d\n", strlen(buf));

	exit(EXIT_FAILURE);
}
