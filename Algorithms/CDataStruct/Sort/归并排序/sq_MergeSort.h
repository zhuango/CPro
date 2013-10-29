#ifndef SQ_MERGESORT_H
#define SQ_MERGESORT_H
#include "RedType.h"
#define MAX_SIZE 20 //一个用作示例的小顺序表的最大长度
typedef struct SqList
{//顺序表类型
	RedType r[MAX_SIZE];//r[0]闲置或用作哨兵单元
	int length;//顺序表长度
}SqList;

typedef SqList HeapType;//定义堆为顺序表存储结构

//函数声明
void PrintL(SqList &L);

void Merge(RedType SR[],RedType TR[],int i,int m,int n);

void MSort(RedType SR[],RedType TR1[],int s,int t);

void MergeSort(SqList &L);




#endif