#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int n = 100, m = 1000000;

double Random()
{
	return (double)rand() / RAND_MAX;
}

int andom(int m)
{
	return (int) (Random() * (m - 1) + 0.5);
}

int main()
{
	int i;
	srand(time(NULL));
	printf("%d %d\n", n, m);

	for(i = 0; i < m; i++) {
		if(rand() % 2 == 0) printf("A"); else printf("B");
		int X, Y;

		for(;;) {
			X = andom(n) + 1;
			Y = andom(n) + 1;
			if(X != Y)  break;
		}
		printf(" %d %d\n", X, Y);
	}

	return 0;
}
