#define ET 1
#include "LinkQueue.h"
#include <malloc.h>

void InitTree(CSTree &T)
{
	T = NULL;
}

void DestroyTree(CSTree &T)
{
	if (T)
	{
		DestroyTree(T->firstchild);
		DestroyTree(T->nextsibling);
		free(T);
		T = NULL;
	}
}

void PostOrderTraverse(CSTree T, void(*visit)(TElemType))
{
	CSTree p;
	if (T)
	{
		if (T->firstchild)
		{
			PostOrderTraverse(T->firstchild,visit);
			p = T->firstchild->nextsibling;
			while (p)
			{
				PostOrderTraverse(p,visit);
				p = p->nextsibling;
			}
		}
		visit(p->data);
	}
}

void LevelOrderTraverse(CSTree T,void (*visit)(TElemType))
{
	CSTree p;
	LinkQueue q;
	InitQueue(q);
	if (T)
	{
		visit(T->data);
		EnQueue(q,T);
		while (!QueueEmpty(q))
		{
			DelQueue(q,p);
			if (p->firstchild)
			{
				p = p->firstchild;
				visit(p->data);
				EnQueue(q,p);
				while (p->nextsibling)
				{
					p = p->nextsibling;
					visit(p->data);
					EnQueue(q,p);			
				}
			}

		}
	}
}

void PreOrderTraverse(CSTree T,void (*visit)(TElemType))
{
	if (T)
	{
		visit(T->data);
		PreOrderTraverse(T->firstchild,visit);
		PreOrderTraverse(T->nextsibling,visit);
	}
}