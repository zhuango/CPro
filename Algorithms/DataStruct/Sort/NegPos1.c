#include<stdio.h>
#include<stdlib.h>

void negpos(int array[], int num)
{
	int cur, pos;
	int i;

	for(i = 1; i < num; i++) {
		cur = array[i];
		pos = i - 1;
		if(array[i] < 0) {
			while(pos >= 0 && array[pos] >= 0) {
				array[pos + 1] = array[pos];
				pos --;
			}
			array[pos + 1] = cur;
		}
	}
}

int main(void)
{
	int array[10] = {12, 3, 4, -123, 43, 23, 5, 6, -234, -43};
	int i;

	negpos(array, 10);

	for(i = 0; i < 10; i++)
		printf("%d ", array[i]);
	printf("\n");

	exit(EXIT_SUCCESS);
}
