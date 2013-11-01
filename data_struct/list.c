#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>

#define LENGTH 10

typedef struct List{
	int data;
	struct List *next;
}List;

struct List *MakeNew(struct List*);

int main(void)
{
	List *Head_list = NULL;//the head of the list ,witch point to the first element of the list
	List *worker = NULL;//move to print the list
	Head_list = MakeNew(Head_list);//get the head
	worker = Head_list;

	while(worker != NULL){
		printf("%d ",worker->data);
		worker = worker->next;
	}
	puts("");
	return 0;
}

struct List *MakeNew(List *list)
{
	int i;
	List *new1 = NULL;
	List *new2 = NULL;
	new1 = (struct List*)malloc(sizeof(struct List));
	list = new1;
	new1->data = 0;
	for(i = 1;i < LENGTH;i++){
		new2 = malloc(sizeof(struct List));//create new element
		new1->next = new2;		   //link to the end
		new1 = new2;			   //flash the worker
		new1->data = i;			   //set the new element data
		new1->next = NULL;		   //set the new element next
	}
	return list;
}


