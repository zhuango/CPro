#include<stdio.h>
#include<stdlib.h>

#define N 10000

int main(void)
{
	_Bool a[N];
	long long i;
	int array[10] = {1, 23, 234 , 6, 2, 7, 14, 65, 32, 9};
	for(i = 0; i < N; i++)
		a[i] = 0;
	for(i = 0; i < 10; i++)
		a[array[i]] = 1;

	for(i = 0; i < N; i++)
		if(a[i])
			printf("%d ", i);
	sleep(10);
	printf("\n");
}
