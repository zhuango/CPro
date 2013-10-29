/*****************Sq_QuitSort.h*****************/
#ifndef SQ_QUITSORT_H
#define SQ_QUITSORT_H

#include "RedType.h"
#define MAX_SIZE 20 //一个用作示例的小顺序表的最大长度
typedef struct SqList
{//顺序表类型
	RedType r[MAX_SIZE];//r[0]闲置或用作哨兵单元
	int length;//顺序表长度
}SqList;
//函数声明

void PrintL(SqList &L);

int Parition1(SqList &L,int low,int high);

int Parition2(SqList &L,int low,int high);

int Parition3(SqList &L,int low,int high);

int Parition4(SqList &L,int low,int high);

void Qsort(SqList &L,int low ,int high);

void QuikSort(SqList &L);

#endif 