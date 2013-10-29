#include<stdio.h>
#include<stdlib.h>

typedef struct node{
	int data;
	struct node *next;
}node;

typedef struct queue{
	node *first, *rear;
}queue;

queue *insert(queue *HQ, int num)
{
	node *a;
	a = malloc(sizeof(node));
	a->data = num;
	a->next = NULL;

	if(HQ->rear == NULL){/* No element in queue */
		HQ->first = a;
		HQ->rear = a;
	}else{/* normal insert */
		HQ->rear->next = a;
		HQ->rear = a;
	}

	return HQ;
}

queue *del(queue *HQ)
{
	node *p;
	int x;

	if(HQ->first == NULL){/* empty queue */
		printf("Queue is empty\n");
	}else{
		x = HQ->first->data;
		p = HQ->first;

		if(HQ->first == HQ->rear){/* one emelent in queue */
			HQ->first = NULL;
			HQ->rear = NULL;
		}else{/* first */
			HQ->first = HQ->first->next;
			free(p);
		}

	}
	return HQ;
}
void print_queue(queue *HQ)
{
	node *index = HQ->first;
	while(index != NULL){
		printf("%d ", index->data);
		index = index->next;
	}
	printf("\n");
}

int main(void)
{
	queue *HQ;
	int i;
	HQ = malloc(sizeof(queue));

	/* Insert 10 numbers */
	for(i = 0; i < 10; i++)
		HQ = insert(HQ, i);
	print_queue(HQ);

	/* Go outside */
	for(i = 0; i < 10; i++){
		HQ = del(HQ);
		print_queue(HQ);
	}
		HQ = del(HQ);
		print_queue(HQ);
	/* insert */
	HQ = insert(HQ, 11);
	print_queue(HQ);
	/* insert */
	HQ = insert(HQ, 12);
	print_queue(HQ);
	/* insert */
	HQ = insert(HQ, 13);
	print_queue(HQ);
	/* insert */
	HQ = insert(HQ, 14);
	print_queue(HQ);
	
	exit(EXIT_SUCCESS);
}
