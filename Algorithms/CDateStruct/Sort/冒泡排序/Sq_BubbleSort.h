#ifndef SQ_BUBBLESORT_H
#define SQ_BUBBLESORT_H

#include "RedType.h"
#define MAX_SIZE 20 //一个用作示例的小顺序表的最大长度
typedef struct SqList
{//顺序表类型
	RedType r[MAX_SIZE];//r[0]闲置或用作哨兵单元
	int length;//顺序表长度
}SqList;

void PrintL(SqList &L);

void BubbleSort(SqList &L);

#endif