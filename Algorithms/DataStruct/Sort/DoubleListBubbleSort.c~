/*
 ============================================================================
 Name        : DoubleListBubbleSort.c
 Author      : Liuzhuang
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include<stdio.h>
#include<stdlib.h>

typedef struct dlist{
	int data;
	struct dlist *next;
	struct dlist *pre;
}dlist;

dlist *dlist_creat(int num)
{
	dlist *Head;
	dlist *head, *a, *b;
	int x = num, cycle = 1;

	Head = malloc(sizeof(dlist));
	a = head = malloc(sizeof(dlist));

	while(cycle){
		if(x != 0){
			b = malloc(sizeof(dlist));/* New element */
			b->data = x;/* Set new element data */
			a->next = b;/* Next */
			b->pre = a;/*  Pre */
			a = b;
		}else
			cycle = 0;
		x --;
	}

	head = head->next;
	head->pre =  NULL;
	a->next = NULL;

	Head->next = head;
	return Head;
}

void print_dlist(dlist *head)
{
	dlist *a = head->next;
	while(a != NULL){
		printf("%d ", a->data);
		a = a->next;
	}
	printf("\n");
}

void print_dlist2(dlist *head)
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

dlist *GetNode(dlist *head, int i)
{
	int count = 0;
	dlist *index = head->next;

	while(index != NULL) {
		count ++;
		//找到第i个元素
		if(count == i) return index;
		index = index->next;
	}
	return NULL;
}

dlist *GetTail(dlist *head)
{
	dlist *index = head->next;
	while(index->next != NULL)
		index = index->next;

	return index;
}
void BubbleSort(dlist *head, int num)
{
	int swap = 1;
	int i = 1, tmp;
	dlist *index, *cur;
	while(swap == 1) {
		swap = 0;

		cur = GetNode(head, i);
		index = GetTail(head);

		while(index != cur) {
			if(index->data < index->pre->data) {
				swap = 1;//有浮动，没有排序完成
				//交换元素
				tmp = index->data;
				index->data = index->pre->data;
				index->pre->data = tmp;
			}
			index = index->pre;//下一个元素
		}

		index = cur->next;
		while(index != NULL) {
			//是不是最后一个元素，是就退出
			if(index->next == NULL)
				break;
			if(index->data > index->next->data) {
				swap = 1;

				tmp = index->data;
				index->data = index->next->data;
				index->next->data = tmp;
			}
			index = index->next;
		}
		i++;
	}
}

int main(void)
{
	dlist *Head;
	Head = dlist_creat(10);

	print_dlist(Head);
	BubbleSort(Head, 10);
	print_dlist(Head);

	exit(EXIT_SUCCESS);
}

