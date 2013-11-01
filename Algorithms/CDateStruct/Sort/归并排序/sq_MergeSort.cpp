#include "sq_MergeSort.h"
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

void Merge(RedType SR[],RedType TR[],int i,int m,int n)
{//将有序的SR[i..m]和SR[m + 1..n]归并为有序的TR[i..n]
	int j,k,p;
	for (j = m + 1, k = i; i <= m && j <= n; ++k)
	{//将SR的两个子序列由小到大归并到TR中
		if LQ(SR[i].key,SR[j].key)
		{
			TR[k] = SR[i++];
		}
		else
		{
			TR[k] = SR[j++];
		}
	}
	if (i <= m)
	{
		for (p = 0; p <= m - i; ++p)
		{
			TR[k + p] = SR[i + p]; //将剩余的SR[i..m]复制到TR
		}
	}
	if (j <= n)
	{
		for (p = 0; p <= n - j; ++p)
		{
			TR[k + p] = SR[j + p]; //将剩余的SR[j..n]复制到TR
		}
	}
}

void MSort(RedType SR[],RedType TR1[],int s,int t)
{//将SR[s..t]归并排序为TR1[s..t]
	int m;
	RedType TR2[MAX_SIZE + 1];
	if (s == t)
	{//只有一个元素待归并
		TR1[s] = SR[s];//直接赋值
	}
	else
	{//有对个元素待归并
		m = (s + t)/2;//将SR[s..t]平分为SR[s..m]和SR[m+1..t]
		MSort(SR,TR2,s,m);//递归的将SR[s..m]归并为有序的TR2[s..m]
		MSort(SR,TR2,m + 1,t);//递归的将SR[m+1..t]归并为有序的TR2[m+1..t]
		Merge(TR2,TR1,s,m,t);//将TR2[s..m]和TR2[m+1..t]归并到TR1[s..t]
	}
}

void MergeSort(SqList &L)
{//对顺序表L作归并排序
	MSort(L.r,L.r,1,L.length);
	//将顺序表L[1..L.length]归并排序为有序的顺序表L.r[1..L.length]
}