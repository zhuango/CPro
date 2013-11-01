#include<stdio.h>
#include<stdlib.h>

void lo(int array[], int size, int num);

int main(void)
{
	int array[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	int i;
	lo(array, 10, 5);

	for(i = 0; i < 10; i++)
		printf("%d ", array[i]);
	printf("\n");

	return 0;
}
void lo(int array[], int size, int num)
{
	int i, tmp, j;

	for(i = 0; i < num; i++){
		tmp = array[0];
		for(j = 1; j < 10; j++)
			array[j - 1] = array[j];
		array[j - 1] = tmp;
	}
}
