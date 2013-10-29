#include<stdio.h>
#include<stdlib.h>

void insert_sort(short [], int num);
int main(void)
{
	short i;
	short array[3] = {92, 83, 71};
	insert_sort(array, 3);

	for(i = 0; i < 3; i++) {
		printf("%d ", array[i]);
	}
	printf("\n");
	exit(EXIT_SUCCESS);
}
void insert_sort(short array[], int num)
{
	short cur;
	short tmp;
	short pos, i;

	for(i = 1; i < num; i++) {
		cur = array[i];
		pos = i - 1;

		while(pos >= 0 && array[pos] > cur){
			array[pos + 1] = array[pos];
			pos --;
		}
		array[pos + 1] = cur;
	}

}

