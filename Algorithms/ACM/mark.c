#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(void)
{
	int array[100];
	int pos[100];
	int i;
	int max = 0;
	int m;

	memset(pos, 0, sizeof(pos));

	for(i = 0; i < 100; i++) {
		scanf("%d", &array[i]);
		pos[array[i]] += 1;
		if(array[i] == -1) break;
	}
	m = i;
	for(i = 0; i < 100; i++)
		if(pos[i] > max) max = pos[i];

	for(i = 0; i < 100; i++)
		if(pos[i] == max) printf("%d ", i);
	printf("\n");

	exit(EXIT_SUCCESS);
}

