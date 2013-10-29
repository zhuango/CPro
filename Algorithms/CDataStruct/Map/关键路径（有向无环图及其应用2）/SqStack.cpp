#include "SqStack.h"

void InitStack(SqStack &S)
{
	if (!(S.base = (SElemType *)malloc(STACK_INIT_SIZE * sizeof(SElemType))))
	{
		exit(OVERFLOW);
	}
	S.top = S.base;
	S.stacksize = STACK_INIT_SIZE;
}

void DestroyStack(SqStack &S)
{
	free(S.base);
	S.top = S.base = NULL;
	S.stacksize = 0;
}

void ClearStack(SqStack &S)
{
	S.top = S.base;
}

Status StackEmpty(SqStack &S)
{
	if (S.top == S.base)
	{
		return TRUE;
	}
	else
	{
		return FALSE;
	}
}

int StackLength(SqStack S)
{
	return S.top - S.base;
}

Status GetTop(SqStack &S,SElemType &e)
{
	if (S.top > S.base)
	{
		e = *(S.top - 1);
		return OK;
	}
	else
	{
		return ERROR;
	}
}

void Push(SqStack &S,SElemType e)
{
	if (S.top - S.base == S.stacksize)
	{
		S.base = (SElemType *)realloc(S.base,(STACK_INIT_SIZE + STACK_INCREMENT)*sizeof(SElemType));
		if (!S.base)
		{
			exit(OVERFLOW);
		}
		S.top = S.base + S.stacksize;
		S.stacksize += STACK_INCREMENT;
	}
	*(S.top)++ = e;
}

Status Pop(SqStack &S,SElemType &e)
{
	if (S.top == S.base)//Õ»¿Õ
	{
		return ERROR; 
	}
	e = * --S.top;
	return OK;
}

void StackTraverse(SqStack S, void (* visit)(SElemType))
{
	while (S.top > S.base)
	{
		visit(*S.base++);
	}
	printf("\n");
}
