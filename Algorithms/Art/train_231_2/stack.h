#ifndef _STACK_H_
#define _STACK_H_

typedef struct node{
	int data;
	struct node *next;
}node;

typedef struct stack{
	node *bottom, *top;
}stack;

<<<<<<< HEAD
=======
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
>>>>>>> b377d5b6d37e1e0791c3b0af7035f3dc99c42dd4

#endif
