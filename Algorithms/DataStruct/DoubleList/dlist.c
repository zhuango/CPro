#include<stdio.h>
#include<stdlib.h>

typedef struct dlist{
	int data;
	struct dlist *next;
	struct dlist *pre;
}dlist;

dlist *dlist_creat()
{
	dlist *head, *a, *b;
	int x, cycle = 1;
	
	a = head = malloc(sizeof(dlist));

	while(cycle){
		printf("input the dlist number: ");/* input the number */
		scanf("%d", &x);
		if(x != 0){
			b = malloc(sizeof(dlist));/* New element */
			b->data = x;/* Set new element data */
			a->next = b;/* Next */
			b->pre = a;/*  Pre */
			a = b;
		}else 
			cycle = 0;
	}

	head = head->next;
	head->pre =  NULL;
	a->next = NULL;

	return head;
}

void print_dlist(dlist *head)
{
	dlist *a = head;
	while(a != NULL){
		printf("%d ", a->data);
		a = a->next;
	}
	printf("\n");
}

print_dlist2(dlist *head)
{
	dlist *a = head;
	while(a->next != NULL)
		a = a->next;
	while(a != NULL){
		printf("%d ", a->data);
		a = a->pre;
	}
	printf("\n");
}

dlist *insert(dlist *head, int num)
{
	dlist *a = head, *b;
	dlist *new;
	new = malloc(sizeof(dlist));
	new->data = num;

	/* Find the number */
	while(a->data < num && a->next != NULL){
		b = a;
		a = a->next;
	}
	if(a->data >= num){
		if(a == head){/* insert into before head */
			new->next = a;
			new->pre = NULL;
			a->pre = new;
			head = new;
		}else{/* normal insert */
			b->next = new;
			new->pre = b;
			new->next = a;
			a->pre = new;
		}
	}else{/* insert behand tail */
		a->next = new;
		new->pre = a;
		new->next = NULL;
	}

	return head;
}

dlist *del(dlist *head, int num)
{
	dlist *a = head, *b;

	/* Find the number */
	while(a->data != num && a->next != NULL){
		b = a;
		a = a->next;
	}
	if(a->data == num){
		if(a == head){/* Delete head */
			head = head->next;
			head->pre = NULL;
			free(a);
		}else if(a->next == NULL){
			b->next = NULL;/* Delete tail */
			free(a);
		}else{/* Delete normal */
			b->next = a->next;
			a->next->pre = b;
			free(a);
		}
	}else
		printf("Can not find %d\n", num);

	return head;
}

int main(void)
{
	dlist *head;
	/* Create new dlist */	
	head = dlist_creat();
	printf("Create: \n");
	print_dlist(head);
	print_dlist2(head);

	/* Insert head */
	head = insert(head, 0);
	printf("Insert(0): \n");
	print_dlist(head);
	print_dlist2(head);

	/* Insert tail */
	head = insert(head, 10);
	printf("Insert(10):\n");
	print_dlist(head);
	print_dlist2(head);

	/* Delete head*/
	head = del(head, 0);
	printf("Delete head(0):\n");
	print_dlist(head);
	print_dlist2(head);

	/* Delete normal */
	head =del(head, 4);
	printf("Delete normal (4): \n");
	print_dlist(head);
	print_dlist2(head);

	/* Delete tail */
	head = del(head, 10);
	printf("Delete tail (9):\n");
	print_dlist(head);
	print_dlist2(head);
	
	exit(EXIT_FAILURE);
}
