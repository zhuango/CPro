#include<stdio.h>
#include<string.h>

int main()
{
	int a[4];
	memset(&a, 0, sizeof(a));
	printf("%d\n", sizeof(long double));
	printf("%x\n", *a);
	*a = *a | 1;
	*a << 1;
	printf("%x\n", *a);

}
