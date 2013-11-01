#ifndef SLL_RADIXSORT_H
#define SLL_RADIXSORT_H
#include <stdio.h>
#define MAX_NUM_OF_KEY 8//关键字项数的最大值
#define RADIX 10//关键字基数的最大值,此时是十进制数的基数
#define MAX_SPACE 100//最大记录数
typedef char KeysType;//定义关键字类型为字符串类型
typedef int infoType;//定义其他数据项为整型

typedef struct SLCell
{//静态链表的结点类型
	KeysType keys[MAX_NUM_OF_KEY];//关键字
	infoType otheritems;//其他数据项
	int next;//下一条记录的序号
}SLCell;

typedef struct SLList
{//静态链表类型
	SLCell r[MAX_SPACE];//静态链表的可利用空间，r[0]为头结点
	int keynum;//记录的当前关键字个数
	int recnum;//静态链表的当前长度（当期记录的总数）
}SLList;

typedef int ArrType[RADIX];//指针数组类型，辅助数组
typedef SLList SqList;//定义SLList类型为SqList类型，以便利用Sort()和Rearrange()
#define length recnum//定义length类型为renum类型，以便利用Sort()和Rearrange()

//函数声明
void Print2(SLList L);

void PrintLL(SLList L);

void Sort(SqList L,int adr[]);

void Rearrange(SqList &L,int adr[]);

void MadeListFromFile(SqList &L,FILE *f);

int ord(char c);

void Distribute(SLCell r[],int i,ArrType f,ArrType e);

int succ(int i);

void Collect(SLCell r[],ArrType f,ArrType e);

void RadixSort(SLList &L);

#endif