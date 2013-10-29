#include<stdio.h>
#include<stdlib.h>

void insert_sort(int array[], int sum, int add)
{
	int pos, cur, i;

	for(i = add; i < sum; i = i + add) {
		cur = array[i];
		pos = i - add;

		while(pos >= 0 && array[pos] > cur) {
			array[pos + add] = array[pos];
			pos = pos - add;
		}
		array[pos + add]  = cur;
	}
}
void shell_sort(int array[], int sum, int add)
{
	while(add != 0) {
		insert_sort(array, sum, add);
		add = add / 2;
	}
}
int main(void)
{
	int array[16] = {23, 4, 2, 5, 6, 87, 3, 23, 54, 12, 76, 43, 5673, 234, 35, 23};
	int i;

	shell_sort(array, 16, 8);
	for(i = 0; i < 16; i++)
		printf("%d ", array[i]);
	printf("\n");

	exit(EXIT_SUCCESS);
}
