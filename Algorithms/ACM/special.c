#include<stdio.h>
#include<stdlib.h>

void InsertSort(int array[], int num);

int main(void)
{
	int i, n, Bool = 0;
	int *number;
	int big, small;
	while(scanf("%d",&n)!=EOF){	
		number = malloc(sizeof(int) * n);
	
		for(i = 0; i < n; i++)
			scanf("%d", &number[i]);
	
		InsertSort(number, n);
		
		big = n - 1;
		small = 0;
		Bool = 0;
		while(big >= small) {
			if(big != n - 1 || small != 0) printf(" ");
			if(Bool == 0) {
				printf("%d", number[big]);
				Bool = 1;
				big --;
			}else {
				printf("%d", number[small]);
				Bool = 0;
				small ++;
			}
		}
		
		printf("\n");
	}
	exit(EXIT_SUCCESS);
}

void InsertSort(int array[], int num)
{
	int cur, i;
	int tmp;
	int pos;

	for(i = 1; i < num; i++) {
		cur = array[i];
		pos = i - 1;

		while(pos >= 0 && array[pos] > cur) {
			array[pos + 1] = array[pos];
			pos --;
		}

		array[pos + 1] = cur;
	}
}
