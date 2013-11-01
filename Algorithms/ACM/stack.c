#include<stdio.h>
#include<stdlib.h>

typedef int type;
typedef struct node {
	type data;
	struct node *next;
}node;

typedef struct stack {
	node *top;
}stack;


void push(stack *s, node *n)
{
	if(n == NULL) {return;}
	node *new = malloc(sizeof(node));
	new->data = n->data;
	new->next = s->top;
	s->top = new;
}

void pop(stack *s)
{
	node *tmp;
	if(s->top == NULL) return;

	tmp = s->top;
	s->top = s->top->next;
	free(tmp);
}

int empty(stack *s)
{
	if(s->top == NULL) return 1;
	return 0;
}

int main()
{
	stack *Stack = malloc(sizeof(stack));
	node *Node = malloc(sizeof(stack));
	int n, i, j;
	int target[100];

	while(scanf("%d", &n ) == 1) {
		if(n == -1) break;
		for(i = 1; i <= n; i++)
			scanf("%d", &target[i]);
		int ok = 1;
		i = j = 1;
		while(j <= n) {
			if(i == target[j]) {i++; j++;}
			else if( !empty(Stack) && Stack->top->data == target[j]){ pop(Stack); j++; }
			else if( i <= n ) { Node->data = i++; push(Stack, Node);}
			else {ok = 0;break;}
		}
		printf("%s\n", ok ? "Yes" : "No");
	}

	return 0;
}
