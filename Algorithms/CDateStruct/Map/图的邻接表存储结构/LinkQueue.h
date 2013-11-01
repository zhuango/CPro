#ifndef LINKQUE_H
#define LINKQUE_H
typedef int QElemType;
//#include"QElemType.h"
//定义结构体(数据)
typedef struct QNode
{
	QElemType data;
	QNode *next;
}*QueuePtr;

struct LinkQueue
{
	QueuePtr front;
	QueuePtr rear;
};
//函数声明(一组操作)
void InitQueue(LinkQueue &);
void DestroyQueue(LinkQueue &);//销毁队列
void ClearQueue(LinkQueue &);//清空队列
Status IsQueueEmpty(LinkQueue &);//判断队列是否为空
int QueueLength(LinkQueue &);//返回队列长度
Status GetHead(LinkQueue &, QElemType &);//用e返回队头元素
void EnQueue(LinkQueue &,QElemType );//在队尾插入元素e
Status DelQueue(LinkQueue &, QElemType &);//删除队头元素
Status QueueTraverse(LinkQueue &, void(*visit)(QElemType));

#endif