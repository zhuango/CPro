#include<stdio.h>
#include<stdlib.h>
int main(void)
{
	int i;
	int *pri;
	pri = malloc(1000000 * sizeof(int));

	for(i = 0; i < 1000000; i++)
		pri[i] = i;
	for(i = 0; i < 1000000; i++){
		printf("%d\n", rand()%1000000);
	}


	return 0;
}
