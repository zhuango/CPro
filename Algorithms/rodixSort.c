#include<stdio.h>
#include<stdlib.h>

int getbit(int x, int n)
{
	int tmp = 1;
	int i;
	for(i = 1; i < n; i++)
		tmp *= 10;
	return ( x = (x / tmp % 10) );
}
void radixSort(int array[], int num, int bitn, int rodix)
{
	int *Q[10];
	int i, j, k, head, tail = num;
	int x, index, bit;

	for(i = 0; i < rodix; i++)
		Q[i] = malloc(sizeof(int) * (num + 1));

	for(j = 1; j <= bitn; j++) {
		for(i = 0; i < rodix; i++)//Clear each queue
			Q[i][0] = 1;//The first index of Q[i] if represent the next position that element should be there
		head = 1;

		while(head != tail) {//If the queue is not empty
			x = array[head];
			head ++;
			bit = getbit(x, j);//Get the j'st bit of 'x'

			Q[bit][Q[bit][0]] = x;
			Q[bit][0] ++;
		}

		index = 1;
		for(i = 0; i < rodix; i++)//Regroup the array
			for(k = 1; k < Q[i][0]; k++) {
				array[index] = Q[i][k];
				index ++;
			}
	}
}
int main(void)
{
	int array[18] = {0, 207, 95, 646, 198, 809, 376, 917, 534, 310, 209, 181, 595, 799, 694, 334, 522, 139};
	int i;

	radixSort(array, 18, 3, 10);

	for(i = 1; i < 18; i++)
		printf("%d ", array[i]);
	printf("\n");

	exit(EXIT_SUCCESS);
}
