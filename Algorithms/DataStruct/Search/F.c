#include<stdio.h>
#include<stdlib.h>
#include<sys/time.h>

int F[11] = {0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55};

void Fe(int array[], int k, int m)
{
	int i = F[m];
	int t;
	int p = F[m - 1], q = F[m - 2];

	while(1) {
		printf("i = %d, p = %d, q = %d, k = %d, array[i] = %d\n", i, p, q, k, array[i]);
		if(k < array[i]) {
			if(q == 0){
				printf("failed!\n");
				break;
			}
			i = i - q;	//i = f[m] - f[m -2] = f[m - 1]
			t = p;
			p = q;		//p = f[m - 2]
			q = t - q;	//q = f[m - 1] - f[m - 2] = f[m - 3]
		}else if(k > array[i]) {
			if(p == 1) {
			       printf("Failed!\n");
			       break;
			}
			i = i + q;	//i = i + f[m - 2];
			p = p - q;	//p = f[m - 1] - f[m - 2] = f[m - 3]
			q = q - p;	//q = f[m - 2] - f[m - 3] = f[m - 4]
		}else {
			printf("Find it \n");
			break;
		}
	}

}
int main(void)
{
	//***************************************************
	struct timeval *_tv = malloc(sizeof(struct timeval));
	struct timeval *_tv1 = malloc(sizeof(struct timeval));
	gettimeofday(_tv, NULL);
	//***************************************************
	int array[54];
	FILE *fin = fopen("result", "r");
	int i;

	for(i = 1; i < 55; i++)
		fscanf(fin, "%d", &array[i]);
	Fe(array, 29, 9);

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
