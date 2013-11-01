//********************************
//Book: Introduction to Algorithms
//Page: 85
//Algorithms: quick sort
//********************************
#include<stdio.h>

#define NUM 10
void quick_sort(int array[], int first, int end);/* do the sort */
int partition(int array[], int first, int end);	/* get the serval small array */

int main(void)
{
	int i;
	int array[NUM] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};/* numbers need to be sort */

	quick_sort(array,0,NUM-1);/* do the sort */

	/* print the sort */
	for(i = 0; i < NUM; i++)
		printf("%d ",array[i]);

	printf("\n");

	return 0;
}

//********************************************************
//function: quick_sort
//array	  :	the numbers nedd to be sort
//first   :	the first element of this array or small array
//end	  :	the end element of this array or small array
//********************************************************
void quick_sort(int array[], int first, int end)
{
	int middle;/* middle one of array */
	if(first < end){
		middle = partition(array,first,end);/* get the middle position */
		quick_sort(array,first,middle-1);	/* sort the small array */
		quick_sort(array,middle+1,end);
	}
}

//***************************************************************
//funciton	: partition get the middle number that port two array
//array		: the numbers need to be set part
//first		: the first element of the array
//end		: the end element
//***************************************************************
int partition(int array[], int first, int end)
{
	int middle = array[end];/* chose the end element as the middle number */
	int mid_pos = first - 1;/* biggest number that less than middle number */
	int each_ele = 0;		/* go through array */
	int tmp;				/* use to swap number */

	for(each_ele = first; each_ele < end; each_ele++)
	{
		if(array[each_ele] <= middle){/* less than midlle? */
			/* swap the number */
			mid_pos++;
			tmp = array[mid_pos];
			array[mid_pos] = array[each_ele];
			array[each_ele]=tmp;
		}
	}
	
	/* put the middle number into postion */
	tmp = array[mid_pos+1];
	array[mid_pos+1] = array[end];
	array[end] 		 = tmp;

	return mid_pos+1;/* return moddle position */
}

