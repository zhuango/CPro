#include "Status.h"
#include "Struct_LinkQueue.h"//包含结构体定义及函数声明

//结构体类型的基本操作
void InitQueue(LinkQueue &Q)//构造一个空的队列Q
{
	Q.rear = Q.front = (QueuePtr)malloc(sizeof(QNode));//队头和队尾指向头结点

	if (!Q.front)
	{
		exit(OVERFLOW);
	}

	Q.front->next = NULL;

	return;
}

void DestroyQueue(LinkQueue &Q)//销毁队列
{
	while (Q.front)            
	{
		Q.rear = Q.front->next;
		free(Q.front);
		Q.front = Q.rear;
	}
	return;
}

void ClearQueue(LinkQueue &Q)//清空队列
{
	DestroyQueue(Q);
	InitQueue(Q);

	return;
}

Status IsQueueEmpty(LinkQueue &Q)//判断队列是否为空
{
	if (Q.front->next == NULL)
	{
		return TRUE;
	}
	else
	{
		return FALSE;
	}
}

int QueueLength(LinkQueue &Q)//返回队列长度
{
	int i = 0;
	QueuePtr p = Q.front->next;
	while (p)
	{
		i++;
		p = p->next;
	}
	return i;
}

Status GetHead(LinkQueue &Q, QElemType &e)//用e返回队头元素
{
	if (Q.front == Q.rear)
	{
		return ERROR;
	}
	e = Q.front->next->data;
	return OK;
}

void EnQueue(LinkQueue &Q,QElemType e)//在队尾插入元素e
{
	Q.rear = Q.rear ->next = (QueuePtr)malloc(sizeof(QNode));
	if (!Q.rear)
	{
		exit (OVERFLOW);
	}
	Q.rear ->data = e;
	Q.rear ->next = NULL;

	return;
}

Status DelQueue(LinkQueue &Q, QElemType &e)//删除队头元素
{
	QueuePtr p;
	if (Q.front == Q.rear)
	{
		return ERROR;
	}

	p = Q.front->next;
	e = p->data;
	Q.front->next = p->next;

	if (p == Q.rear)//删除的是队尾元素
	{
		Q.rear = Q.front;
	}
	free(p);

	return OK;	
}

Status QueueTraverse(LinkQueue &Q, void(*visit)(QElemType))
{
	QueuePtr p = Q.front->next;

	if (Q.front == Q.rear)
	{
		return ERROR;
	}
	while (p)
	{
		visit(p->data);
		p = p->next;
	}

	printf("\n");

	return OK;
}