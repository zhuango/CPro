#include<stdio.h>
#include<stdlib.h>

#include "stack.h"

int main(void)
{
	stack *SK = malloc(sizeof(stack));
	
	SK = push(SK, 1);
	SK = push(SK, 2);
	SK = push(SK, 3);
	SK = pop(SK);
	SK = pop(SK);
	SK = push(SK, 4);
	SK = push(SK, 5);
	SK = pop(SK);
	SK = push(SK, 6);
	SK = pop(SK);
	SK = pop(SK);
	SK = pop(SK);

	printf("\n");
	return 0;
}
