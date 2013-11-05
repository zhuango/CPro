#include<stdio.h>
#include<stdlib.h>
#define NUM 10

void HeapSort(int array[], int num);
void BuildMinHeap(int array[], int num);
void MinHeapify(int array[], int num, int node);

int LEFT(int node)
{
	return node * 2 + 1;
}
int RIGHT(int node)
{
	return node * 2 + 2;
}

int HeapSize = 0;
int main(void)
{
	//int array[NUM] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
//	int array[NUM] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
//	int array[NUM] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, };
	int array[NUM] = { 12, 321, 12, 142, 15, 11, 1423, 21, 41, 61, };
	int i;

	HeapSort(array, NUM - 1);

	for(i = 0; i < NUM; i++)
		printf("%d ", array[i]);
	printf("\n");

	exit(EXIT_SUCCESS);
}

void HeapSort(int array[], int num)
{
	int i;

	BuildMinHeap(array, num);
	for(i = num; i > 0; i --){
		array[i]	= array[i] ^ array[0];
		array[0]	= array[i] ^ array[0];
		array[i]	= array[i] ^ array[0];
		HeapSize --;
		MinHeapify(array, num, 0);
	}
}

void BuildMinHeap(int array[], int num)
{
	int i;
	HeapSize = num + 1;

	for(i = (num - 1) / 2; i >= 0; i--)
	       MinHeapify(array, num, i); 
}

void MinHeapify(int array[], int num, int node)
{
	int LeftIndex = LEFT(node);
	int RightIndex = RIGHT(node);
	int SmallestIndex ;
	
	if(LeftIndex < HeapSize && array[LeftIndex] < array[node])
		SmallestIndex = LeftIndex;
	else
		SmallestIndex = node;

	if(RightIndex < HeapSize && array[RightIndex] < array[SmallestIndex])
		SmallestIndex = RightIndex;

	if(SmallestIndex != node){
		array[SmallestIndex]	= array[SmallestIndex] ^ array[node];
		array[node]		= array[SmallestIndex] ^ array[node];
		array[SmallestIndex]	= array[SmallestIndex] ^ array[node];
		MinHeapify(array, num, SmallestIndex);
	}

}
