#include<stdio.h>
#include<stdlib.h>

void chose(int array[], int sum)
{
	int i, j;
	int tmp;

	for(i = 0; i < sum; i++)
		for(j = i; j < sum; j++) {
			if(array[j] < array[i]) {
				tmp = array[j];
				array[j] = array[i];
				array[i] = tmp;
			}
		}
}
int main(void)
{
	int array[10] = {23, 43, 23, 5, 65, 67, 8, 9, 34, 876};
	int i;

	chose(array, 10);

	for(i = 0; i < 10; i++)
		printf("%d ", array[i]);
	printf("\n");

	exit(EXIT_SUCCESS);
}
