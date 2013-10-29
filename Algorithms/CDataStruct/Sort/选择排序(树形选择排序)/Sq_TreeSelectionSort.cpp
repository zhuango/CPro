#include "Sq_TreeSelectionSort.h"
#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
void PrintL(SqList &L)
{//输出顺序表L
	int i;
	for (i = 1; i <= L.length; ++i)
	{
		printf("(%d,%d) ",L.r[i].key,L.r[i].otherinfo);
	}
	printf("\n");
}

void TreeSort(SqList &L)
{
	int i,j,n;
	RedType *t = (RedType *)malloc((2 * L.length - 1)*sizeof(RedType));//二叉树采用顺序存储结构
	for (i = 1; i <= L.length; ++i)
	{//将L.r赋给叶子结点（从上到下，从左到右）
		t[L.length - 2 + i] = L.r[i];
	}
	for ( i = L.length - 2; i >= 0; --i)
	{
		t[i] = t[2 * i + 1].key <= t[2 * i +2].key?t[2 * i + 1]:t[2 * i + 2];//非叶子结点的值为其左右孩子中关键字小的
	}
	for (i = 0; i < L.length; ++i)
	{
		L.r[i + 1] = t[0];//将当前最小值赋给L.r[i]
		n = 0;//根结点的序号
		do
		{//沿沿树根按层序找结点t[0]在叶子中的序号n
			n = t[2 * n + 1].key == t[n].key?2 *n + 1:2*n + 2;
		} while (n < L.length - 1);
		t[n].key = INT_MAX;//将此叶子结点的关键字赋无穷大
		while (n)
		{
			n = (n + 1)/2 - 1;//序号为n的结点的双亲结点序号
			t[n] = t[2 * n + 1].key <= t[2 *n + 2].key?(t[2 * n + 1]):(t[2 * n + 2]);
			//非叶子结点的值为其左右孩子中关键字小的
		}
	}
	free(t);
}