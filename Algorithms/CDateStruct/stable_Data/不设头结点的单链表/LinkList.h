#include <stdio.h>
#include "Status.h"

typedef int ElemType;

typedef struct LNode
{
	ElemType date;
	LNode *next;
} *LinkList;

void InitList(LinkList &L);

void ClearList(LinkList &L);

Status ListEmpity(LinkList L);

int ListLength(LinkList L);

Status GetElem(LinkList L,int i,ElemType &e);

int LocateElemType(LinkList L,ElemType e,Status(*compare)(ElemType,ElemType));

Status ListInsert(LinkList &L,int i,ElemType e);

Status ListDelete(LinkList &L,int i,ElemType &e);

void ListTraverse(LinkList L, void (*vi)(ElemType));

Status PriorElem(LinkList L,ElemType cur_e,ElemType &pre_e);

Status NextElem(LinkList L,ElemType cur_e,ElemType &next_e);