#include<stdio.h>
#include<stdlib.h>

#include<sys/time.h>

#define NUM 2000000
void Interpolation(int array[], int num, int k)
{
	int s = 0, e = num + 1;
	int i;

	while(e > s + 1) {
		i = s + (k - array[s]) / (array[e] - array[s]) * (e - s + 1) + 1;
		if(array[i] < k)
			s = i;
		else if(array[i] > k)
			e = i;
		else
			break;
	}
	if(e - s <= 1)
		printf("failed\n");
	else
		printf("Find it\n");
}
int main(void)
{
	int array[NUM + 3];
	int i; 
	FILE *fin = fopen("result", "r");
	array[NUM + 1] = 2147481944;
	array[0] = 0;
	for(i = 1; i < NUM + 1; i++)
		fscanf(fin, "%d", &array[i]);
	//***************************************************
	struct timeval *_tv = malloc(sizeof(struct timeval));
	struct timeval *_tv1 = malloc(sizeof(struct timeval));
	gettimeofday(_tv, NULL);
	//***************************************************
	
	Interpolation(array, NUM, 2943);
	//***************************************************
	gettimeofday(_tv1, NULL);
	long _end	= _tv1->tv_sec		* 1000000 + _tv1->tv_usec;
	long _start	= _tv->tv_sec		* 1000000 + _tv->tv_usec;
	long _s 	= (_end - _start)	/ 1000000;
	double _ms	= (_end - _start -   _s * 1000000) / 1000.0;
	printf("Total: %lu s %lf ms\n", _s, _ms);
	//***************************************************

	exit(EXIT_SUCCESS);
}
