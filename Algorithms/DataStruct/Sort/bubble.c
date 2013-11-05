#include<stdio.h>
#include<stdlib.h>

void bubble(int array[], int sum)
{
	int i, j;
	int tmp;

	for(i = 0; i < sum; i++)
		for(j = sum - 1; j > i; j--) {
			if(array[j] < array[j - 1]) {
				tmp = array[j];
				array[j] = array[j - 1];
				array[j - 1] = tmp;
			}
		}
}
int main(void)
{
	int array[8] = {7, 3, 1, 8, 6, 2, 4, 5};
	int i;

	bubble(array, 8);

	for(i = 0; i < 8; i++)
		printf("%d ", array[i]);
	printf("\n");

	exit(EXIT_SUCCESS);
}
