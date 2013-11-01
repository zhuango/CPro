#ifndef SQ_HEAPSORT_H
#define SQ_HEAPSORT_H
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
void HeapAdjust(HeapType &H,int s,int m);

void HeapSort(HeapType &H);

#endif