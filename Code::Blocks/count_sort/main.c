
#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>

#define NUM 1000000
void counting_sort(int array[], int result[], int num);/* sort function */

int main(void)
{
	int i;
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
        int *array = malloc(sizeof(int) * NUM);/* array you want to sort */
        int *result = malloc(sizeof(int) * NUM);			 /* sort reasult */
        for(i = 0; i < NUM; i++){
            scanf("%d", &array[i]);
            result[i] = 0;
        }


	counting_sort(array,result,NUM);/* do the sort */

	/* print the sort */
	for(i = 0; i < NUM; i++){
		//printf("%d ",result[i]);
		//printf("%d ",result[i]);
    }
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
	int *tmp = malloc(sizeof(int) * NUM);/* count each element */

	/* clear to 0 */
	for(clear_i = 0; clear_i < NUM; clear_i++)
		tmp[clear_i] = 0;
	/* the position that equal to the element in array, and count */
	for(count_i = 0; count_i < num; count_i++)
		tmp[array[count_i]] = tmp[array[count_i]] + 1;
	/* count the number that smaller than the element in array */
	for(big_counti = 1; big_counti < NUM; big_counti++)
		tmp[big_counti] += tmp[big_counti - 1];

	/* put into the right sort into result array */
	for(sort_i = num-1; sort_i >= 0; sort_i--){
		result[tmp[array[sort_i]] - 1] = array[sort_i];
		tmp[array[sort_i]]--;
	}
}
