#include <stdio.h>
#include <stdlib.h>

int Fib(int N)
{
	if(N <= 1)
		return 1;
	else
		return Fib(N - 1) + Fib(N - 2);
}

int main(void)
{
	int N = 40;
	int result = Fib(N);
	printf("%d\n", result);
	exit(EXIT_SUCCESS);
}
