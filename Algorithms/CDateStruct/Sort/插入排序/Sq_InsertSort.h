#ifndef SQ_INSERTSORT_H
#define SQ_INSERTSORT_H
#include "RedType.h"
#define MAX_SIZE 20 //一个用作示例的小顺序表的最大长度
typedef struct SqList
{//顺序表类型
	RedType r[MAX_SIZE];//r[0]闲置或用作哨兵单元
	int length;//顺序表长度
}SqList;
void Print(SqList L);

void InsertSort(SqList &L);

void BInsertSort(SqList &L);

void P2_InsertSort(SqList &L,int flag);

#endif