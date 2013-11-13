#include<stdio.h>
#include<sys/time.h>
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
#define NUM 2000000
int main(void)
{
	int array[NUM];
	//***************************************************
	struct timeval *_tv = malloc(sizeof(struct timeval));
	struct timeval *_tv1 = malloc(sizeof(struct timeval));
	gettimeofday(_tv, NULL);
	//***************************************************

	long i;
	FILE *fout = fopen("result", "w");
	for(i = 0; i < NUM; i++)
		scanf("%d", &array[i]);
	
	quick_sort(array, 0, i - 1);
	//***************************************************
	gettimeofday(_tv1, NULL);
	long _end	= _tv1->tv_sec		* 1000000 + _tv1->tv_usec;
	long _start	= _tv->tv_sec		* 1000000 + _tv->tv_usec;
	long _s 	= (_end - _start)	/ 1000000;
	double _ms	= (_end - _start -   _s * 1000000) / 1000.0;
	printf("Total: %lu s %lf ms\n", _s, _ms);
	//***************************************************

	for(i = 0; i < NUM; i++)
		fprintf(fout, "%d\n", array[i]);
	printf("\n");

	exit(EXIT_SUCCESS);
}
