/*******************************************************
 * Book      : Introduction Algorithms
 * Page      : 23
 * fucntion  : bubble sort
 * descripter: swap the wrong position numbers that next
 * *****************************************************/
#include<stdio.h>

/* number of array you want ot sort */
#define NUM 5
void bubble_sort(int array[], int num);/* the function do the sort */

int main(void)
{
	int i;/* use to print the array */
	int array[NUM] = {333,222,221,220,219};
	/* do the sort */
	bubble_sort(array,NUM);

	/* print the result */
	for(i = 0; i < NUM; i++){
		printf("%d ",array[i]);
	}
	printf("\n");

	return 0;
}


/**************************************
 * fucntion: bubble_sort
 * array[] : the array you want to sort
 * num	   : the number of the array
 **************************************/
void bubble_sort(int array[], int num)
{
	int i,j;/* use to scan the array */

	for(i = 0; i < num; i++)/* get the most smaller one, then get the second smaller one, then ...... */
		for(j = num - 1; j > i; j--)/* scan whole array to compare the smaller one  */
		{
			if(array[j] < array[j-1]){/* if the behand one smaller the before one,swap the position */

				/* swap the position */
				array[j]   = array[j]+array[j-1];
				array[j-1] = array[j]-array[j-1];
				array[j]   = array[j]-array[j-1];
			}
		}
}
