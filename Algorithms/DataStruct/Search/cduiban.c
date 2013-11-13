#include<stdio.h>
#include<stdlib.h>

#include<sys/time.h>
#define NUM 2000000
int main(void)
{
	
	int array[NUM + 10];
	int i;
	char number[20];
	int NumberToFind = 1852308325;
	//int NumberToFind = 0;
	int m = NUM / 2;

	FILE *fin = fopen("result", "r");

	i = 1;
	while(fgets(number, 20, fin) != NULL && i <= NUM) {
		array[i] = atoi(number);
		i++;
	}
	array[0] = -1;
	//***************************************************
	struct timeval *_tv = malloc(sizeof(struct timeval));
	struct timeval *_tv1 = malloc(sizeof(struct timeval));
	gettimeofday(_tv, NULL);
	//***************************************************
	i = m;	
	while(m != 0) {
		if(array[i] > NumberToFind)
			i = i - m / 2 - 1;
		else if(array[i] < NumberToFind)
			i = i + m / 2 + 1;
		else if(array[i] == NumberToFind) {
			printf("Find it!\n");
			break;
		}
		m = m / 2;
	}
	if(array[i] != NumberToFind) 
		printf("Failed\n");

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
