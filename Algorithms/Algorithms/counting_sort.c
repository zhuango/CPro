#include<stdio.h>

#define NUM 10
void counting_sort(int array[], int result[], int num);/* sort function */

int main(void)
{
	int i;
	int array[NUM] = {12,32,123,42,1,105,45,2,6,110};/* array you want to sort */
	int result[NUM]= {0,0,0,0,0,0,0,0,0,0};			 /* sort reasult */

	counting_sort(array,result,NUM);/* do the sort */

	/* print the sort */
	for(i = 0; i < NUM; i++)
		printf("%d ",result[i]);
	printf("\n");

	return 0;
}


//********************************************************************
//function: counting_sort, count the number and deciside the position!
//array	  : array you want to sort
//num	  : length of array
//********************************************************************
void counting_sort(int array[], int result[], int num)
{
	int clear_i;/* go through the array to clear as 0 */
	int count_i;/*count for eac element in array */
	int big_counti;/* for change the position  */
	int sort_i;	/*go through array and get the position of number */
	int tmp[124];/* count each element */

	/* clear to 0 */
	for(clear_i = 0; clear_i < 124; clear_i++)
		tmp[clear_i] = 0;
	/* the position that equal to the element in array, and count */
	for(count_i = 0; count_i < num; count_i++)
		tmp[array[count_i]] = tmp[array[count_i]] + 1;
	/* count the number that smaller than the element in array */
	for(big_counti = 1; big_counti < 124; big_counti++)
		tmp[big_counti] += tmp[big_counti - 1];

	/* put into the right sort into result array */
	for(sort_i = num-1; sort_i >= 0; sort_i--){
		result[tmp[array[sort_i]] - 1] = array[sort_i];
		tmp[array[sort_i]]--;
	}
}
