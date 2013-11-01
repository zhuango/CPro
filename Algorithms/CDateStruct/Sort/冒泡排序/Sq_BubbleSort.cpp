#include "Sq_BubbleSort.h"
#include <stdio.h>

typedef int Status;//状态类型
#define TRUE 1
#define FALSE 0

void PrintL(SqList &L)
{//输出顺序表L
	int i;
	for (i = 1; i <= L.length; ++i)
	{
		printf("(%d,%d) ",L.r[i].key,L.r[i].otherinfo);
	}
	printf("\n");
}

void BubbleSort(SqList &L)
{//对顺表L进行冒泡排序
	int i,j;
	Status change = TRUE;//调整的标志,初值为TRUE
	for (i = L.length - 1; i >= 1 && change; --i)
	{
		change = FALSE;//本次循环未调整的标志
		for (j = 1; j <= L.length - 1; ++j)
		{
			if (LT(L.r[j + 1].key,L.r[j].key))//前面记录的关键字大于后面记录的关键字
			{//两记录互换
				L.r[0] = L.r[j];
				L.r[j] = L.r[j + 1];
				L.r[j + 1] = L.r[0];
				change = TRUE;//已调整的标志
			}
		}
	}
	
}