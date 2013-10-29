#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>


int main(void)
{
	int c;
	while((c = getchar()) != EOF)
		putchar(c);

	return 0;
}
