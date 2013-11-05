#include<stdio.h>
#include<stdlib.h>

void negpos(int array[], int num)
{
	int i, neg = 0, pos = 0;
	int *array1, *array2;
	array1 = malloc(sizeof(int) * num);
	array2 = malloc(sizeof(int) * num);

	for(i = 0; i < num; i++) {
		if(array[i] < 0) {
			array2[neg] = array[i];
			neg ++;
		}else {
			array1[pos] = array[i];
			pos ++;
		}
	}
	for(i = 0; i < neg; i++)
		array[i] = array2[i];
	
	for(i = neg; i < neg + pos; i++)
		array[i] = array1[i - neg];
}
int main(void)
{
	int array[10] = {32, 12, 5, -1, -453, 234, -2, 35, 234, -123};
	int i;

	negpos(array, 10);

	for(i = 0; i < 10; i++)
		printf("%d ", array[i]);
	printf("\n");

	exit(EXIT_SUCCESS);
}
