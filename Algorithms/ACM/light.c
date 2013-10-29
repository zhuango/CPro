#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(void)
{
	int lights[1010];
	int n, k, i, j, first = 1;

	memset(lights, 0, sizeof(lights));
	scanf("%d %d", &n, &k);

	for(i = 1; i <= k; i++)
		for(j = 1; j <= n; j++)
			if(j % i == 0)  lights[j] = !lights[j];
	for(i = 1; i <= n; i++) 
		if(lights[i] == 1) {
			if(first) first = 0;
			else printf(" ");
			printf("%d", i);
		}
	printf("\n");
	exit(EXIT_SUCCESS);
}

