#ifndef SL_INSERTSORT_H
#define SL_INSERTSORT_H
#include "RedType.h"

#define SIZE 100
typedef struct SLNode
{//表结点类型
	RedType rc;//记录项
	int next;//指针项
}SLNode;

typedef struct SLinkListType
{//静态链表类型
	SLNode r[SIZE];//0号单元为表头结点
	int length;//链表当前长度
}SLinkListType;

//基本操作函数声明

void PrintL(SLinkListType L);

void CreatTableFromFile(SLinkListType &SL,FILE*f);

void MakeTableSorted(SLinkListType &SL);

void Arrange(SLinkListType &SL);

typedef SLinkListType SqList;

void Sort(SqList L,int adr[]);

void Rearrange(SqList &L,int adr[]);

#endif