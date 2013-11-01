#include<stdio.h>
#include<stdlib.h>

int main()
{
	int numbers[10][10];
	int numbers2[10][10];
	int i, j, n, tmp;

	scanf("%d", &n);
	for(i = 0; i < n; i++) 
		for(j = 0; j < n; j++)
			scanf("%d", &numbers[i][j]);

	for(i = 0; i < n; i++)
		for(j = 0; j < n; j++) {
			numbers2[n - 1 - j][i] = numbers[i][j];
		}

	for(i = 0; i < n; i++) {
		for(j = 0; j < n; j++) 
			printf("%d ", numbers2[i][j]);
		printf("\n");
	}

	printf("\n");
	return 0;
}
