#include<stdio.h>
#include<stdlib.h>

int partion(int array[], int start, int end)
{
	int mid = array[end];
	int mid_pos = start;
	int i, tmp;

	for(i = start; i < end; i++) {
		if(array[i] < mid) {
			tmp = array[i];
			array[i] = array[mid_pos];
			array[mid_pos] = tmp;
			mid_pos ++;
		}
	}
	tmp = array[end];
	array[end] = array[mid_pos];
	array[mid_pos] = tmp;

	return mid_pos;
}
void quick_sort(int array[], int start, int end)
{
	int middle;
	if(start < end) {
		middle = partion(array, start, end);
		quick_sort(array, start, middle - 1);
		quick_sort(array, middle + 1, end);
	}
}
int main(void)
{
	int array[10] = {12, 3, 4, 2, 323, 65, 234, 765, 234, 65};
	int i;

	quick_sort(array, 0, 9);

	for(i = 0; i < 10; i++)
		printf("%d ", array[i]);
	printf("\n");

	exit(EXIT_SUCCESS);
}
