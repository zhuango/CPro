#include<stdio.h>
#include<stdlib.h>
#include"list.h"
/* Create list */
struct list *create_list(int number)
{
	int i;
	struct list *head;
	struct list *a;
	struct list *b;
	if(number == 0)
		return NULL;

	a = malloc(sizeof(struct list));
	a->data = 0;
	head = a;
	head->pre = NULL;
	for(i = 1; i < number; i++){
		b = malloc(sizeof(struct list));
		a->next = b;
		a->next->data = i;
		b->pre = a;
		a = b;
	}
	a->next = NULL;

	return head;
}
/* Insert a element */
struct list* insert_list(struct list *head, int data)
{
	struct list *a = malloc(sizeof(struct list));
	a->data = data;
	a->next = head;
	a->pre = NULL;
	head = a;

	return head;
}
/* Find element */
struct list *search_list(struct list *head, int data)
{
	struct list *a = head;
	while(a != NULL && a->data != data)
		a = a->next;
	return a;
}

/* Delete a element */
struct list *delete_list(struct list *head, int data)
{
	struct list *a;
	if((a = search_list(head, data)) == NULL){
		printf("There is no this element\n");
		return NULL;
	}
	if(a->pre == NULL){
		head = a->next;
		head->pre = NULL;
	}else if(a->next == NULL){
		a->pre->next = NULL;
	}else{
		a->pre->next = a->next;
		a->next->pre = a->pre;
	}
	free(a);

	return head;

}
/* Print elements */
void print_list(struct list* head)
{
	struct list *index = head;
	while(index != NULL){
		printf("%d ", index->data);
		index = index->next;
	}
	printf("\n");
}
