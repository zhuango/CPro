#include<stdio.h>
#include<stdlib.h>
#include"list.h"
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

struct list* insert_list(struct list *head, int data)
{
	struct list *a = malloc(sizeof(struct list));
	a->data = data;
	a->next = head;
	a->pre = NULL;
	head = a;

	return head;
}

struct list *search_list(struct list *head, int data)
{
	struct list *a = head;
	while(a != NULL && a->data != data)
		a = a->next;
	return a;
}
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
void print_list(struct list* head)
{
	struct list *index = head;
	while(index != NULL){
		printf("%d ", index->data);
		index = index->next;
	}
	printf("\n");
}
int main(void)
{
	struct list *head, *index;
	index = head = create_list(4);
	while(index != NULL){
		printf("%d ", index->data);
		index = index->next;
	}
	printf("\n");
	index = head = insert_list(head, 10);
	print_list(head);
	printf("\n");
	if((index = search_list(head, 3)) != NULL){
		printf("find : %d\n", index->data);
	}
	else
		printf("Dnesn't find!\n");
	printf("the whole list: \n");
	print_list(head);
	head = delete_list(head, 10);
	print_list(head);
	head = delete_list(head, 3);
	print_list(head);
	head = delete_list(head, 1);
	print_list(head);


	exit(EXIT_SUCCESS);
}
