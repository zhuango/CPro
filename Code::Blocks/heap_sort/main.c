//*********************************
//Book	  : Introduction Algorithms
//Page	  : 74~78
//function: The heap sort
//Time	  : 2012.11.04
//*********************************
#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>

#define NUM 1000000

int  heap_size = NUM;								/* the heap size */
void heap_sort(int array[], int num);				/* function of heap sort */
void max_heapify(int array[],int num, int father);	/* make the father be a root of a small max_heap */
void build_max_heap(int array[], int num);			/* build a max heap */

/* get the left child */
inline int LEFT(int father){
	return 2*father+1;
}
/* get the right child */
inline int RIGHT(int father){
	return 2*father+2;
}

int main(void)
{
	int i;/* use to print sort array */
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
	int *array = malloc(sizeof(int) * NUM);
	for(i = 0; i < NUM; i++){
        scanf("%d", &array[i]);
	}
	heap_sort(array, NUM);/* begin to sort */

	/* print the array */
	for(i = 0; i < NUM; i++){
		//printf("%d ",array[i]);
	}
	printf("\n");

	return 0;
}


//***************************************************
//function	: heap_sirt
//array[] 	: the array you want to sort
//num	  	: length of array
//descripter: put the biggest number that in heap
//			  to the root,
//			  and put this root on the end of array.
//			  again and again!
//***************************************************
void heap_sort(int array[], int num)
{
	int i;
	build_max_heap(array, num);/* build the max heap */
	for(i = num - 1; i > 0; i--){
		/* swap the biggest and the root */
		array[0] = array[0] + array[i];
		array[i] = array[0] - array[i];
		array[0] = array[0] - array[i];
		heap_size--;/* heap size down */
		max_heapify(array, num, 0);/* put the biggest one on the root */
	}
}

//*******************************************
//function	: max_heapify
//array		: the array you want to sort
//num	    : length of array
//father	: the father now!!!
//descripter: go with arg named father,
//			  make it to be a max heap father
//*******************************************
void max_heapify(int array[], int num, int father)
{
	int left  = LEFT(father);	/* get the left child position */
	int right = RIGHT(father);	/* get the right child position */
	int largest;				/* the real father */

	/* If left child was bigger than father, then largest = left, or largest = father */
	if(left < heap_size && array[left] > array[father])
		largest = left;
	else
		largest = father;

	/* if right child was bigger than father, then largest = right */
	if(right < heap_size && array[right] > array[largest])
		largest = right;

	/* father change! swap the element and go on */
	if(largest != father){
		array[father]  = array[largest] + array[father];
		array[largest] = array[father]  - array[largest];
		array[father]  = array[father]  - array[largest];
		max_heapify(array, num, largest);
	}
}

//************************************************************
//function	: build the max heap
//array		: the array you want to sort
//num		: length of array
void build_max_heap(int array[], int num)
{
	int position;
	heap_size = num;

	/* make each father bigger than his child */
	for(position = num/2 - 1; position >= 0; position --){
		max_heapify(array, num, position);
	}
}
