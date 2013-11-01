void InitStack(SqStack &S)//构造一个空栈
{
	if (!(S.base = (SElemType*)malloc(STACK_INIT_SIZE*sizeof(SElemType))))
	{
		exit (OVERFLOW);
	}
	S.top = S.base;
	S.stacksize = STACK_INIT_SIZE;
	return;
}

void DestroyStack(SqStack &S)//销毁栈S
{
	free(S.base);
	S.base = S.top = NULL;
	S.stacksize = 0;
	return;
}

void ClearStack(SqStack &S)//将S置为空栈
{
	S.top = S.base;
	return;
}

Status IsStackEmpty(SqStack S)//判断S是否为空栈
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

Status GetTop(SqStack S,SElemType &e)//用e返回S的栈顶元素
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
	if (S.top - S.base == S.stacksize)//判断S是否已满
	{
		S.base = (SElemType *)realloc(S.base,(S.stacksize + STACK_INCREMENT )*sizeof(SElemType));
		
		if (!S.base)
		{
			exit (OVERFLOW);
		}
		
		S.top = S.stacksize + S.base; //指向新的栈顶
		S.stacksize += STACK_INCREMENT; 
	}
	
	*S.top++ = e; 
}

Status Pop(SqStack &S,SElemType &e)//删除栈顶元素，用e返回其值
{
	if (S.top == S.base)
	{
		return ERROR;
	}
	e = *--S.top;
    
	return OK;
}

void StackTraverse(SqStack S,void(*visit)(SElemType))//从栈底到栈顶依次对S中没一个元素调用函数visit()
{
	while (S.base < S.top)
	{
		visit(*S.base++);
	}
	printf("\n");
}