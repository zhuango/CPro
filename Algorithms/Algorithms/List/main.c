#include<stdio.h>
#include<stdlib.h>

#include "list.h"


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
