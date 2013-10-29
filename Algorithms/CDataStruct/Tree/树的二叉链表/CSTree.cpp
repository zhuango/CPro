#define ET 1
#include "LinkQueue.h"
#include <malloc.h>

#define ClearTree DestoyTree

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
void CreateTree(CSTree &T)
{
	char c[20];
	CSTree p,p1;
	LinkQueue q;
	int i, m;
	InitQueue(q);
	printf("请输入根结点（字符型，空格为空）：");
	scanf("%c%*c",&c[0]);
	if (c[0] != Nil)
	{
		T = (CSTree)malloc(sizeof(CSNode));
		T->data = c[0];
		T->nextsibling = NULL;
		EnQueue(q,T);
		while (!QueueEmpty(q))
		{
			DelQueue(q,p);
			printf("请按长幼顺序输入结点%c的所有孩子：", p->data);
			gets(c);
			m = strlen(c);
			if (m > 0)	
			{
				p1 = p->firstchild = (CSTree)malloc(sizeof(CSNode));
				p1->data = c[0];
				EnQueue(q,p1);
				for (i = 1; i < m; ++i)
				{
					p1->nextsibling = (CSTree)malloc(sizeof(CSNode));
					p1 = p1->nextsibling;
					p1->data = c[i];
					EnQueue(q,p1);
				}
				p1->nextsibling = NULL;
			}
			else
			{
				p->firstchild = NULL;
			}
		}
	}
	else
	{
		T = NULL;
	}

}

Status TreeEmpty(CSTree T)
{
	if (T)
	{
		return FALSE;
	}
	else
	{
		return TRUE;
	}
}

int TreeDepth(CSTree T)
{
	CSTree p;
	int depth, max = 0;
	if (!T)
	{
		return 0;
	}
	for (p = T->firstchild; p; p = p->nextsibling)
	{
		depth = TreeDepth(p);
		if (depth > max)
		{
			max = depth;
		}
	}
	return max + 1;
}

TElemType Value(CSTree p)
{
	return p->data;
}

TElemType Root(CSTree T)
{
	if (T)
	{
		return Value(T);
	}
	else
	{
		return Nil;
	}
}

CSTree Point(CSTree T, TElemType s)
{
	LinkQueue q;
	CSTree a;
	
	if (T)
	{
		InitQueue(q);
		EnQueue(q,T);
		while (!QueueEmpty(q))
		{
			DelQueue(q,a);
			if (a->data  == s)
			{
				return a;
			}
			if (a->firstchild)
			{
				EnQueue(q,a->firstchild);//入队长子
			}
			if (a->nextsibling)
			{
				EnQueue(q,a->nextsibling);//入队兄弟
			}
		}
	}
	return NULL;
}

Status Assign(CSTree &T, TElemType cur_e, TElemType value)
{
	CSTree p;
	if (T)
	{
		if (p = Point(T,cur_e))
		{
			p->data = value;
			return OK;
		}
	}
	return ERROR;
}

TElemType Parent(CSTree T, TElemType cur_e)
{
	CSTree p,t;
	LinkQueue q;
	InitQueue(q);
	if (T)
	{
		if (T->data == cur_e)
		{
			return Nil;
		}
		EnQueue(q,T);
		while (!QueueEmpty(q))
		{
			DelQueue(q,p);
			if (p->firstchild)
			{
				if (p->firstchild->data == cur_e)
				{
					return p->data;
				}
				t = p;
				p = p->firstchild;
				EnQueue(q,p);
				while (p->nextsibling)
				{
					p = p->nextsibling;
					if (p->data == cur_e)
					{
						return t->data;
					}
					EnQueue(q,p);
				}
			}
		}
	}
	return Nil;
}

TElemType LeftChild(CSTree T, TElemType cur_e)
{
	CSTree p;
	if (T)
	{
		p = Point(T,cur_e);
		if(p&&p->firstchild)
		{
			return p->firstchild->data;
		}
	}
	return Nil;
}

TElemType RightSibling(CSTree T, TElemType cur_e)
{
	CSTree p;
	if (T)
	{
		p = Point(T,cur_e);
		if(p&&p->nextsibling)
		{
			return p->nextsibling->data;
		}
	}
	return Nil;
}

Status InsertChild(CSTree T, CSTree p, int i, CSTree c)
{
	int j;
	CSTree pre;
	if (T)
	{
		if (1 == i)
		{
			c->nextsibling = p->firstchild;
			p->firstchild = c;
		}
		else
		{
			p = p->firstchild;
			for (j = 1; j < i; ++j)
			{
				if (p)
				{
					pre = p;
					p = p->nextsibling;
				}
				else
				{
					return ERROR;
				}
			}
			c->nextsibling = pre->nextsibling;
			pre->nextsibling = c;
		}
		return OK;
	}
	return ERROR;
}

Status DeleteChild(CSTree T, CSTree p, int i)
{
	int j;
	CSTree q, pre;
	if (T)
	{
		if (1 == i)
		{
			q = p->firstchild;
			p->firstchild = q->nextsibling;
			q->nextsibling = NULL;
			DestroyTree(q);
		}
		else
		{
			p = p->firstchild;	
			for (j = 1; j < i; ++j)
			{
				if (p)
				{
					pre = p;
					p = p->nextsibling;
				}
				else
				{
					return ERROR;
				}
			}
			pre->nextsibling = p->nextsibling;
			p->nextsibling = NULL;
			DestroyTree(p);
		}
		return OK;
	}
	return ERROR;
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
		visit(Value(T));
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