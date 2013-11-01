#include<stdio.h>
#include<stdlib.h>

typedef int type;
typedef struct node {
	type data;
	struct node *next;
}node;

typedef struct queue {
	node *head;
	node *tail;
}queue;

void push(queue *q, node *n)
{
	node *tmp;
	if(n == NULL) {
		return;
	}

	if(q->head == NULL) {
		q->tail = q->head = malloc(sizeof(node));
		q->head->data = n->data;
		q->tail->next = NULL;
		return;
	}
	tmp = malloc(sizeof(node));
	tmp->data = n->data;
	q->tail->next = tmp;
	tmp->next = NULL;
	q->tail = tmp;
}

void pop(queue *q)
{
	node *tmp;
	if(q->head == NULL) {
		return;
	}
	tmp = q->head->next;
	free(q->head);
	q->head = tmp;
}

int empty(queue *q)
{
	if(q->head == NULL) {
		return 1;
	}
	return 0;
}

int main()
{
	queue q;
	int n, i;
	node *Node = malloc(sizeof(node));

	q.head = NULL;
	q.tail = NULL;
	scanf("%d", &n);
	for(i = 0; i < n; i++) {
		Node->data = i + 1;
		push(&q, Node);
	}

	while(!empty(&q)) {
		printf("%d ", q.head->data);
		pop(&q);
		push(&q, q.head);
		pop(&q);
	}
	printf("\n");
	return 0;
}
