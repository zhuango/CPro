#include<stdio.h>
#include<stdlib.h>

int people(int n, int k)
{
	if(n < k) return 0;
	else if(k == 0 ||  k == n) return 1;
	else
		return people(n - 1, k) + people(n - 1, k - 1);
}
int main(void)
{
	int n = 6;
	int sum;
	sum = people(n, 2);
	printf("%d\n", sum);

	exit(EXIT_SUCCESS);
}
