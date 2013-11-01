#include<stdio.h>
void convert(int , int);

int main()
{
	int n, m;

	scanf("%d %d", &n, &m);

	convert(n, m);
	printf("\n");
	return 0;
}

void convert(int n, int m)
{
	if(m / n == 0) {
		printf("%d", m);
		return ;
	}else {
		convert(n, m / n);
		printf("%d", m % n);
	}
}
