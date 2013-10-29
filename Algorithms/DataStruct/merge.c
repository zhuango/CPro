#include<stdio.h>
#include<stdlib.h>

void merge(int array[], int start, int middle, int end)
{
	int *array1 = malloc(sizeof(middle - start + 2));
	int *array2 = malloc(sizeof(end - middle + 1));
	int i, j, k;

	for(i = start, j = 1; i <= middle; i++, j++)
		array1[j] = array[i];
	for(i = middle + 1, j = 1; i <= end; i++, j++)
		array2[j] = array[i];

	k = start;
	i = j = 1;
	while(1) {
		if(array1[i] < array2[j]) {
			array[k] = array1[i];
			k++;
			i++;
		}else if(array1[i] >= array2[j]) {
			array[k] = array2[j];
			k++;
			j++;
		}
		if(i > middle - start + 1 ||
			j > end - middle)
			break;
	}

	if(i > middle - start + 1) {
		while(j <= end - middle) {
			array[k] = array2[j];
			k++;
			j++;
		}
	}
	if(j > end - middle) {
		while(i <= middle - start + 1) {
			array[k] = array1[i];
			k++;
			i++;
		}
	}
}
void merge_sort(int array[], int start, int end)
{
	int middle;
	if(start < end) {
		middle = (start + end) / 2;
		merge_sort(array, start, middle);
		merge_sort(array, middle + 1, end);
		merge(array, start, middle, end);
	}
}
int main(void)
{
	int array[11] = {0, 23, 234, 2, 54, 23, 594, 65, 67, 87, 45};
	int i;

	merge_sort(array, 1, 10);

	for(i = 1; i < 11; i++) 
		printf("%d ", array[i]);
	printf("\n");

	exit(EXIT_SUCCESS);
}
