#include "Sq_InsertSort.h"
#include <stdio.h>
#include <malloc.h>
void Print(SqList L)
{//输出顺序表L
	int i;
	for (i = 1; i <= L.length; ++i)
	{
		printf("(%d,%d)",L.r[i].key,L.r[i].otherinfo);
	}
	printf("\n");
}

void InsertSort(SqList &L)
{//对顺序表L作直接插入排序
	int i,j;
	for (i = 2; i <= L.length; ++i)
	{//从第二个记录到最后哟个记录
		if (LT(L.r[i].key,L.r[i - 1].key))
		{//当前记录<前一个记录
			L.r[0] = L.r[i];//将当前记录复制为哨兵
			for (j = i - 1;LT(L.r[0].key,L.r[j].key); --j)
			{//有序子表从后到前,若哨兵小于记录,则记录后移一个单元
				L.r[j + 1] = L.r[j];//后移一个单元
			}
			L.r[j + 1] = L.r[0];//将哨兵（当前记录）插入到正确位置
		}
	}
}

void BInsertSort(SqList &L)
{//对有序表L作折半插入排序
	int i,j,m,low,high;
	for (i = 2; i <= L.length; ++i)
	{//从第二个记录到最后哟个记录
		if (LT(L.r[i].key,L.r[i - 1].key))
		{//当前记录<前一个记录
			L.r[0] = L.r[i];//将当前记录复制为哨兵
			low = 1;//低端为第一个记录
			high = i - 1;//高端不包括当前记录
			while (low <= high)
			{//在[low,high]区间中折半查找有序插入的位置
				m = (low + high)/2;//折半
				if (LT(L.r[0].key,L.r[m].key))
				{//关键字小于中点关键字
					high = m - 1;//插入点在低半区
				}
				else//关键字大于等于中点关键字
				{
					low = m + 1;//插入点在高半区
				}
			}
			for (j = i - 1; j >= high + 1; --j)
			{//有序子表从后到前
				L.r[j + 1] = L.r[j];//记录后移
			}
			L.r[high + 1] = L.r[0]; //插入到[high + 1]
		}
	}
}

void P2_InsertSort(SqList &L,int flag)
{//2-路插入排序（flag = 0）和改进的2-路插入排序（flag = 1，当L.r[1]是待排序的记录中关键字最小或最大的记录时，仍有优越性）
	int i,j,first,final,mid=0;
	RedType *d;
	d=(RedType*)malloc(L.length*sizeof(RedType)); //生成L.length个记录的临时空间
	d[0]=L.r[1]; //设L的第1个记录为d中排好序的记录
	first=final=0; //first、final分别指示d中排好序的记录的第1个和最后一个记录的位置
	for(i=2;i<=L.length;++i) //依次将L的第2个~最后1个记录插入d中
	{ 
		if(flag) 
		{ 
			if(first>final)
			j=L.length; 
		else
			j=0;
	    mid=(first+final+j)/2%L.length; 
	}
	if(L.r[i].key<d[mid].key) 
	{ j=first; 
	first=(first-1+L.length)%L.length; 
	while(L.r[i].key>d[j].key) 
	{ d[(j-1+L.length)%L.length]=d[j]; 
	j=(j+1)%L.length; 
	}
	d[(j-1+L.length)%L.length]=L.r[i]; 
	}
	else 
	{ j=final++; 
	while(L.r[i].key<d[j].key) 
	{ d[(j+1)%L.length]=d[j]; 
	j=(j-1+L.length)%L.length; 
	}
	d[(j+1)%L.length]=L.r[i];

	}
	}
	for(i=1;i<=L.length;i++) 
		L.r[i]=d[(first+i-1)%L.length]; 
	free(d); 
}


















