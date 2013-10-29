#include "Sq_SelectSort.h"
#include <stdio.h>

void PrintL(SqList &L)
{//输出顺序表L
	int i;
	for (i = 1; i <= L.length; ++i)
	{
		printf("(%d,%d) ",L.r[i].key,L.r[i].otherinfo);
	}
	printf("\n");
}

int SelectMinKey(SqList L,int i)
{//返回在L.r[i..L.length]中key最小的记录的序号
	int j,k = i;//初施设[i]的关键词为最小，存i与k
	for (j = i + 1; j <= L.length; ++j)
	{
		if (LT(L.r[j].key,L.r[k].key))
		{
			k = j;//更新k为最小关键词序号j
		}
	}
	return k;
}

void SelectSort(SqList &L)
{//对顺序表L作简单选择排序
	int i,k;
	for (i = 1; i < L.length; ++i)
	{
		k = SelectMinKey(L,i);
		if (k != i)
		{
			L.r[0] = L.r[k];
			L.r[k] = L.r[i];
			L.r[i] = L.r[0];
		}
	}
}