#include "SqStack.h"
void print(SElemType e)
{
	printf("%d ",e);
}
int main(void)
{
	int j;
	SqStack s;
	SElemType e;
	InitStack(s);
	for (j = 1; j <= 12; j++)
	{
		Push(s,j);
	}
	printf("栈中的元素依次为");
	StackTraverse(s,print);
	Pop(s,e);
	printf("弹出栈顶元素e = %d\n",e);
	printf("栈是否为空？%d(1:空 0：不空)\n",StackEmpty(s));
	GetTop(s,e);
	printf("栈顶元素e=%d,栈的长度为%d\n",e,StackLength(s));
	ClearStack(s);
	printf("清空栈后 是否为空？%d(1:空 0：不空)\n",StackEmpty(s));
	DestroyStack(s);
	printf("销毁栈后，s.base = %u,s.top = %u,s.stacksize = %d\n",s.top,s.base,s.stacksize);
	return 0;
}