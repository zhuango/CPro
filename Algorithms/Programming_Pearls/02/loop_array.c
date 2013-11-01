#include<stdio.h>
#include<stdlib.h>

int main(void)
{
	int array[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	int i, j, tmp;
	int index;
	index = 3;

	for(i = 0; i < 3; i++){
		tmp = array[i];
		for(j = 1; (i + index*j) < 9; j++){
			printf("%d %d\n", i + index * (j - 1), i + index * j);
			array[i + index * (j - 1)] = array[i + index * j];
		}
		array[i + index * (j - 1)] = tmp; 
	}

	for(i = 0; i < 10; i++)
		printf("%d ", array[i]);
	printf("\n");

	exit(EXIT_SUCCESS);
}
