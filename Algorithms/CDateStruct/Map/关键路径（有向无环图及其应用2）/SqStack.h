#include "Status.h"
#define STACK_INIT_SIZE 10//栈的初始储存空间
#define STACK_INCREMENT 10//存储空间分配增量
typedef int SElemType;

typedef struct SqStack
{
	SElemType *base;//在构造栈之前和销毁之后，base的值为NULL
	SElemType *top;//栈顶指针
	int stacksize;//当前以分配的存储空间
};

//基本操作函数声明
void InitStack(SqStack &S);

void DestroyStack(SqStack &S);

void ClearStack(SqStack &S);

Status StackEmpty(SqStack &S);

int StackLength(SqStack S);

Status GetTop(SqStack &S,SElemType &e);

void Push(SqStack &S,SElemType e);

Status Pop(SqStack &S,SElemType &e);

void StackTraverse(SqStack S, void (* visit)(SElemType));
