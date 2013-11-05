#include<stdio.h>
#include<stdlib.h>

int heap_size = 0;
int LEFT(int i)
{
	return i * 2;
}
int RIGHT(int i)
{
	return i * 2 + 1;
}

void Heapify(int array[], int end, int father)
{
	int left = LEFT(father);
	int right = RIGHT(father);
	int largest, tmp;

	if(left <= heap_size && array[left] > array[father])
		largest = left;
	else
		largest = father;

	if(right <= heap_size && array[right] > array[largest])
		largest = right;

	if(largest != father) {
		tmp = array[largest];
		array[largest] = array[father];
		array[father] = tmp;
		Heapify(array, end, largest);
	}
}

void BuildMaxHeap(int array[], int end)
{
	int i;
	heap_size = end;
	for(i = end / 2; i >= 1; i--)
		Heapify(array, end, i);
}

void HeapSort(int array[], int end)
{
	int i, tmp;
	BuildMaxHeap(array, end);
	for(i = end; i > 1; i--) {
		tmp = array[i];
		array[i] = array[1];
		array[1] = tmp;
		heap_size --;
		Heapify(array, end, 1);
	}
}

int main(void)
{
	int array[11] = {0, 100, 23, 43, 342, 543, 234, 6, 8, 45, 3};
	int i;

	HeapSort(array, 10);

	for(i = 1; i < 11; i++)
		printf("%d ", array[i]);

	printf("\n");

	exit(EXIT_SUCCESS);
}
