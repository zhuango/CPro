#include "GList.h"


void Divide(SString str,SString hstr)
{//将脱去外层括号的非空串str分成两个部分：hstr为第一个","之前的子串，str为之后的子串
	int n,k = 0, i = 0;
	SString ch,c1,c2,c3;
	StrAssign(c1,",");
	StrAssign(c2,"(");
	StrAssign(c3,")");
	n = StrLength(str);
	do
	{
		++i;
		SubString(ch,str,i,1);
		if (!StrCompare(ch,c2))
		{
			++k;
		}
		else if (!StrCompare(ch,c3))
		{
			--k;
		}
	}while (i < n &&  StrCompare(ch,c1) || k != 0);
	if (i < n)
	{
		SubString(hstr,str,1,i - 1);
		SubString(str,str,i + 1,n - i);
	}
	else
	{
	   StrCopy(hstr,str);
	   ClearString(str);
	}
} 

void InitGList(GList &L)
{
	L = NULL;
}

void CreateGList(GList &L,SString S)
{
	SString sub,hsub,emp;
	GList p,q;
	StrAssign(emp,"()");
	if (!StrCompare(S,emp))
	{
		L = NULL;
	}
	else
	{
		if (!(L = (GList)malloc(sizeof(GLNode))))
		{
			exit(OVERFLOW);
		}
		if (StrLength(S) == 1)
		{
			L->tag = ATM;
			L->atom = S[1];
		}
		else
		{
			L->tag = LIST;
			p = L;
			SubString(sub,S,2,StrLength(S) - 2);//脱掉外层括号
			do
			{
				Divide(sub,hsub);
				CreateGList(p->ptr.hp,hsub);
				q = p;
				if (!StrEmpty(sub))
				{
					if (!(p = (GList)malloc(sizeof(GLNode))))
					{
						exit(OVERFLOW);
					}
					p->tag = LIST;
					q ->ptr.tp = p;
					
				}
			}while(!StrEmpty(sub));
			q->ptr.tp = NULL;
		}
	}

}

void DestroyGList(GList &L)
{
	GList q1,q2;
	if (L)
	{
		if (L->tag == LIST)
		{
			q1 = L->ptr.hp;
			q2 = L->ptr.tp;
			DestroyGList(q1);
			DestroyGList(q2);
		}
		free(L);
		L = NULL;
	}
}

void CopyGList(GList &T,GList L)
{
	if (!L)
	{
		T = NULL;
	}
	else
	{
		T = (GList)malloc(sizeof(GLNode));
		if (!T)
		{
			exit(OVERFLOW);
		}
		T->tag = L->tag;
		if (L->tag == ATM)
		{
			T->atom = L->atom;
		}
		else
		{
			CopyGList(T->ptr.hp,L->ptr.hp);
			CopyGList(T->ptr.tp,L->ptr.tp);
		}
	}
}

int GListLength(GList L)
{
	int len = 0;
	while (L)
	{
		L = L->ptr.tp;
		len++;
	}
	return len;
}

int GListDepth(GList L)
{
	int dep,max = 0;
	GList pp;
	if (!L)
	{
		return 1;
	}

	if (L->tag == ATM)
	{
		return 0;
	}
	for (pp = L; pp; pp = pp->ptr.tp)
	{
		dep = GListDepth(pp->ptr.hp);
		if (dep > max)
		{
			max = dep;
		}	
	}
	return max + 1;

}

Status GListEmpty(GList L)
{
	if (!L)
	{
		return TRUE;
	}
	else
	{
		return FALSE;
	} 
}

GList GetHead(GList L)
{
	GList h;
	if (!L)
	{
		return NULL;
	}
	CopyGList(h,L->ptr.hp);
    return h;
}

GList GetTail(GList L)
{
	GList t;
	if (!L)
	{
		return NULL;
	}
	CopyGList(t,L->ptr.tp);
    return t;
}

void InsertFirst_GL(GList &L,GList e)
{
	GList p = (GList)malloc(sizeof(GLNode));
	if (!p)
	{
		exit(OVERFLOW);
	}
	p->tag = LIST;
	p->ptr.hp = e;
	p->ptr.tp = L;
	L= p;
}

void DeleteFirst_GL(GList &L,GList &e)
{
	GList p = L;
	e = L->ptr.hp;
	L = L->ptr.tp;
	free(p);
}

void Traverse_GL(GList L,void (*visit)(AtomType))
{
	if (L)
	{
		if (L->tag == ATM)
		{
			visit(L->atom);
		}
		else
		{
			Traverse_GL(L->ptr.hp,visit);
			Traverse_GL(L->ptr.tp,visit);
		}
	}
}









