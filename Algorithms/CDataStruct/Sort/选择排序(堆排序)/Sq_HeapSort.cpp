#include "Sq_HeapSort.h"
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

void HeapAdjust(HeapType &H,int s,int m)
{//已知H.[s..m]中记录的关键字除H.r[s].key之外均满足大顶堆的定义，
//本函数调整H.r[s]的关键字，使H.r[s..m]中记录的关键字均满足大顶堆的定义
	int j;
	H.r[0] = H.r[s];//利用空闲结点存储待调整的记录
	for (j = 2 * s; j <= m; j *= 2)
	{//j指向待调整的记录[s]的左孩子，沿key较大的孩子结点向下筛选
		if (j < m && LT(H.r[j].key,H.r[j + 1].key))
		{//左孩子的关键字 < 右孩子的关键字
			++j;//j指向[s]的右孩子
		}
		if (!LT(H.r[0].key,H.r[j].key))
		{//[s]关键字不小于其孩子的的关键字
			break;//不必再调整，跳出for循环
		}
		H.r[s] = H.r[j];//否者[j]为大顶，插入[s]
		s = j;//[s]的位置向下移动到[j]（原左或右孩子处）
	}
	H.r[s] = H.r[0];//将待调整的记录插入[s]
}

void HeapSort(HeapType &H)
{//对顺序表H进行堆排序
	int i;
	for (i = H.length/2;i > 0; --i)
	{//从最后一个非叶子结点到第1个结点
		HeapAdjust(H,i,H.length);//调整H.r[i]，使H.r[i..H.length]成为大顶堆
	}
	for (i = H.length; i > 1; --i)
	{
		H.r[0] = H.r[1];//将堆顶记录[1]和未完全排序的H.r[1..i]中的最后一个记录交换
		H.r[1] = H.r[i];
		H.r[i] = H.r[0];
		HeapAdjust(H,1,i - 1);//调整H.r[1],使H.r[1..i-1]重新成为大顶堆
	}
}