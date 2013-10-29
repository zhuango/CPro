#include "ALGraph.h"
Status Equal(ElemType e1,ElemType e2)
{
	if ((e1.adjvex == e2.adjvex))
	{
		return TRUE;
	}
	return FALSE;
}

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
	
	e = p->data;
	return OK;
}

int LocateElem(LinkList L,ElemType e,Status(*compare)(ElemType,ElemType))
{
	int i = 1;
	LinkList p = L;
	while (p)
	{
		if (compare(e,p->data))
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
	s->data = e;
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
		e = p->data;
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
		q = p->next;
		p->next = p->next->next;
		e = q ->data;
		free(q);
	}
	return OK;
}

void ListTraverse(LinkList L, void (*vi)(ElemType))
{
	LinkList p = L;
	while (p)
	{
		vi(p->data);
		p = p->next;
	}
	printf("\n");
}

Status PriorElem(LinkList L,ElemType cur_e,ElemType &pre_e)
{
	LinkList p = L;

	while (p->next)
	{
		if (Equal(cur_e,p->next->data))
		{
			pre_e = p->data;
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
		if (Equal(p->data,cur_e))
		{
			next_e = p->next->data;
		}
		p = p->next;
		return OK;
	}
	return ERROR;
}

LinkList Point(LinkList L,ElemType e,Status(*equal)(ElemType ,ElemType),LinkList &pre)
{
	int j,i = LocateElem(L,e,Equal);
	if (i)
	{
		if (1 == i)
		{
			pre = NULL;
			return L;
		}
		pre = L;
		for (j = 2; j < i; ++j)
		{
			pre = pre->next;
		}
		return pre->next;
	}
	return NULL;
}