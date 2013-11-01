#ifndef _STACK_H_
#define _STACK_H_

typedef struct node{
	int data;
	struct node *next;
}node;

typedef struct stack{
	node *bottom, *top;
}stack;


#endif
