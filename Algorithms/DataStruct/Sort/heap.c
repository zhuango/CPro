#include<stdio.h>
#include<stdlib.h>

int heap_size;

int Left(int i)
{
	return i * 2;
}
int Right(int i)
{
	return i * 2 + 1;
}
void max_heapify(int array[], int heap_size, int father)
{
	int largest, left, right;
	int tmp;
	left = Left(father);
	right= Right(father);

	if(left < heap_size && array[left] > array[father])
		largest = left;
	else
		largest = father;

	if(right < heap_size && array[right] > array[largest])
		largest = right;

	if(largest != father) {
		tmp = array[father];
		array[father] = array[largest];
		array[largest] = tmp;
		max_heapify(array, heap_size, largest);
	}
}
void build_max_heap(int array[], int num)
{
	int i;
	heap_size = num;
	for(i = num / 2; i > 0; i--)
		max_heapify(array, heap_size, i);
}
heap_sort(int array[], int num)
{
	int i;
	int tmp;
	build_max_heap(array, num);

	for(i = num; i > 0; i--) {
		tmp = array[i];
		array[i] = array[1];
		array[1] = tmp;
		heap_size --;
		max_heapify(array, heap_size, 1);
	}
}
int main(void)
{
	int array[11] = {0, 12, 32, 4, 23, 5, 0, 90, 342, 932, 12};
	int i;

	heap_sort(array, 10);

	for(i = 1; i <= 10; i++) 
		printf("%d ", array[i]);
	printf("\n");

	exit(EXIT_SUCCESS);
}
