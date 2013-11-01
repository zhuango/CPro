#include<stdio.h>
#include<stdlib.h>
int main(void)
{
	int i,j ;
	int *pri;
	pri = malloc(4000000U * sizeof(int));

	for(i = 0; i < 1000000; i++)
		pri[i] = i;
	for(i = 0; i < 4000000; i++){
			printf("%d\n", rand()%4294967295U);
	}

	return 0;
}
