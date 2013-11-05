#include<stdio.h>
#include<stdlib.h>

void SpecBubble(int array[], int num)
{
	int iswap = 1;
	int i = 0, j, tmp;

	while(iswap == 1) {
		iswap = 0;
		//Bubble
		for(j = num - i - 1; j > i; j--) {
			if(array[j] < array[j - 1]) {
				iswap = 1;
				tmp = array[j];
				array[j] = array[j - 1];
				array[j - 1] = tmp;
			}
		}
		//Down
		for(j = i + 1; j < num - 1; j++) {
			if(array[j] > array[j + 1]) {
				iswap = 1;
				tmp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = tmp;
			}
		}
		i++;
	}
}
int main(void)
{
	int array[10] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
	int i;

	SpecBubble(array, 10);

	for(i = 0; i < 10; i++)
		printf("%d ", array[i]);
	printf("\n");

	exit(EXIT_SUCCESS);
}
