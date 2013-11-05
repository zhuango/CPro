#include<stdio.h>
#include<stdlib.h>

typedef struct node{
	int data;
	struct node *next;
}node;

typedef struct stack{
	node *bottom, *top;
}stack;

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
		SK->top = SK->top->next;
	}

	return SK;
}

void print_stack(stack *SK)
{
	node *index;
	index = SK->top;

	while(index != NULL){
		printf("%d ", index->data);
		index = index->next;
	}
	printf("\n");
}

int main(void)
{
	stack *SK;
	int i;
	SK = malloc(sizeof(stack));

	/* Push 10 elements */
	printf("Push:\n");
	for(i = 0; i < 10; i++)
		SK = push(SK, i);
	print_stack(SK);
	/* Pop elemetns */
	printf("Pop\n");
	for(i = 0; i < 10; i++){
		SK = pop(SK);
		print_stack(SK);
	}
	SK = pop(SK);
	print_stack(SK);
	print_stack(SK);
	/* Push again */
	printf("Push again:\n");
	for(i = 0; i < 10; i++){
		SK = push(SK, i);
		print_stack(SK);
	}
	exit(EXIT_SUCCESS);
}

