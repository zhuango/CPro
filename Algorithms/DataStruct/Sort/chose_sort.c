/***********************
 * Book		 :Algorithms
 * Page		 :16
 * Algorithms: chose sort
 ***********************/
#include<stdio.h>

#define NUM 5

/* do the sort */
void chose_sort(int aray[], int num);

int main(void)
{
	int i;/* use to print */
	int array[NUM] = {23,42,14,345,21};
	chose_sort(array, NUM);

	/* print result */
	for(i = 0;i < NUM; i++)
		printf("%d ", array[i]);
	printf("\n");

	return 0;
}

/*******************************
 * chose_sort: get the right sort 
 * array	 : the array need to sort
 * num		 : length of array
 * *****************************/
void chose_sort(int array[], int num)
{
	int i,j;

	for(i = 0;i < num; i++)
		for(j = i+1; j < num; j++){
			if(array[i] > array[j]){
				array[i] = array[i] + array[j];
				array[j] = array[i] - array[j];
				array[i] = array[i] - array[j];
			}
		}

}
