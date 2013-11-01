#include<stdio.h>
#include<malloc.h>

#include "stack.h"

stack *push(stack *SK, int num)
{
	node *new;
	new = malloc(sizeof(node));
	new->data = num;
	new->next = NULL;

	if(SK->top == NULL){/* Empty stack */
		SK->top = new;
		SK->bottom = new;
	}else{/* Normal push */
		new->next = SK->top;
		SK->top = new;
	}

	return SK;
}

stack *pop(stack *SK)
{
	node *p;
	int data;

	if(SK->top == NULL)/* Empty stack */
		printf("empty stack\n");
	else{/* Normal pop */
		p = SK->top;
		data = p->data;
		SK->top = SK->top->next;
	}

	printf("%d ", data);
	return SK;
}
