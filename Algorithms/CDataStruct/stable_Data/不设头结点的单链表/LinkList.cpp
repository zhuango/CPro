#include "LinkList.h"

void InitList(LinkList &L)
{
	L = NULL;
}

void ClearList(LinkList &L)
{
	LinkList p;
	while(L)
	{
		p = L->next;
		free(L);
		L = p;
	}
}

Status ListEmpity(LinkList L)
{
	if (L)
	{
		return FALSE;
	}
	else
	{
		return TRUE;
	}
}

int ListLength(LinkList L)
{
	int i = 0;
	LinkList p = L;
	while (p)
	{
		i++;
		p = p->next;
	}
	return i;
}

Status GetElem(LinkList L,int i,ElemType &e)
{
	int j = 1;
	LinkList p = L;
	if (i < 1)
	{
		return ERROR;
	}
	while (p && j < i)
	{
		j++;
		p = p->next;
	}
	if (!p || j > i)
	{
		return ERROR;
	}
	
	e = p->date;
	return OK;
}

int LocateElemType(LinkList L,ElemType e,Status(*compare)(ElemType,ElemType))
{
	int i = 1;
	LinkList p = L;
	while (p)
	{
		if (compare(e,p->date))
		{
			return i;
		}
		i++;
		p = p->next;
	}
	return 0;
}

Status ListInsert(LinkList &L,int i,ElemType e)
{
	int j = 1;
	LinkList s,p = L;
	if (i < 1)
	{
		return ERROR;
	}	
	s = (LinkList)malloc(sizeof(LNode));
	s->date = e;
	if (i == 1)
	{
		s->next = L;
		L = s;
	}
	else
	{
		while (p && j < i - 1)
		{
			j++;
			p = p->next;
		}
		if (!p)
		{
			return ERROR;
		}
		s->next = p->next;
		p->next = s;
	}
	return OK;
}

Status ListDelete(LinkList &L,int i,ElemType &e)
{
	int j = 1;
	LinkList q, p = L;
	if (!L || i < 0)
	{
		return ERROR;
	}
	if (1 == i)
	{
		e = p->date;
		L = p->next;
		free (p);
	}
	else
	{
		while (p->next && j < i - 1)
		{
			j++;
			p = p->next;
		}
		if (!p->next || j > i - 1)
		{
			return ERROR;
		}
		e = p->date;
		q = p->next;
		p->next = p->next->next;
		free(q);
	}
	return OK;
}

void ListTraverse(LinkList L, void (*vi)(ElemType))
{
	LinkList p = L;
	while (p)
	{
		vi(p->date);
		p = p->next;
	}
	printf("\n");
}

Status PriorElem(LinkList L,ElemType cur_e,ElemType &pre_e)
{
	LinkList p = L;

	while (p->next)
	{
		if (cur_e == p->next->date)
		{
			pre_e = p->date;
			return OK;
		}
		p = p->next;
	}
	return ERROR;
}

Status NextElem(LinkList L,ElemType cur_e,ElemType &next_e)
{
	LinkList p = L;
	while (p->next)
	{
		if (p->date == cur_e)
		{
			next_e = p->next->date;
		}
		p = p->next;
		return OK;
	}
	return ERROR;
}