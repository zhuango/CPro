/*******************************************
 * Book			: Introduction to Algorithms
 * Page			: 10
 * Algorithms	: INSERTION_SORT
 *******************************************/

#include<stdio.h>

#define NUM 10/* length of array */

void insertion_sort(int array[], int num);

int main(void)
{
	int i;
	int array[NUM] = {9,2,1,3,4,5,2,4,34,543};
	insertion_sort(array, NUM);

	/* print the right sort array */
	for(i = 0;i < NUM; i++)
		printf("%d ",array[i]);
	printf("\n");
	return 0;
}


/***********************************************
 * insertion_sort	: get the right sort array
 * array			: the array you want to sort
 * num				: the length of array
 ***********************************************/
void insertion_sort(int array[], int num)
{
	int insert_number,position;
	int key;
	for(insert_number = 1; insert_number < num;
			insert_number ++){

		key = array[insert_number];			/* get the insert number */
		position = insert_number-1;			/* put the position that is before the current number */

		/* go throught the array ,compare each one to the insert number */
		while(position >= 0 && array[position] > key){
			array[position+1] = array[position];/* bigger than the insert number? then move the position */
			position = position-1;				/* compare next one */
		}
		array[position+1] = key;				/* insert the right position */
	}
}
