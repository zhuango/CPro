/*******************************************
 * Book			: Introduction to Algorithms
 * Page			: 10
 * Algorithms	: INSERTION_SORT
 *******************************************/

#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#define NUM 1000000/* length of array */

void insertion_sort(int array[], int num);

int main(void)
{
	int i;
	int *array = malloc(sizeof(int) * NUM);
	        int data;
        int new_fd;
        /* do the sort */
        if((data = open("/home/Og/Pro/CPro/Algorithms/Beauty_of_Programming/ID/result", O_RDONLY)) < 0){
            perror("open");
            exit(EXIT_FAILURE);
        }
        if(dup2(data, 0) < 0){
            perror("dup2");
            exit(EXIT_FAILURE);
        }
        for(i = 0; i < NUM; i++){
            scanf("%d", &array[i]);
        }
	insertion_sort(array, NUM);

	/* print the right sort array */
	for(i = 0;i < NUM; i++){
		//printf("%d ",array[i]);
    }
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
